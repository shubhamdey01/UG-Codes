#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <poll.h>

#define MAX_BUFFER_SIZE 1024
#define DROP_THRESHOLD 0.1
#define ACK_TIMEOUT 100

typedef struct {
    int start_byte;
    int length;
} Packet;

void send_ack(int sockfd, int expected_byte, const struct sockaddr_in *client_addr) {
    char ack_data[MAX_BUFFER_SIZE];
    sprintf(ack_data, "%d", expected_byte);
    sendto(sockfd, ack_data, strlen(ack_data), 0, (const struct sockaddr *)client_addr, sizeof(*client_addr));
    printf("ACK sent. NEXT Byte = %d\n", expected_byte);
}

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct pollfd poll_fds[1];
    int expected_byte = 0;
    Packet packets[MAX_BUFFER_SIZE];
    int num_packets = 0;

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    bzero(&server_addr, sizeof(server_addr));

    // Server information
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    printf("Receiver is running. Requesting for byte : %d\n", expected_byte);
    send_ack(sockfd, expected_byte, &server_addr);

    poll_fds[0].fd = sockfd;
    poll_fds[0].events = POLLIN;

    while (1) {
        // Wait for data or timeout
        int poll_result = poll(poll_fds, 1, ACK_TIMEOUT);

        if (poll_result == -1) {
            perror("poll failed");
            exit(EXIT_FAILURE);
        } else if (poll_result == 0) {
            // Timeout occurred, re-transmit last ACK
            send_ack(sockfd, expected_byte, &server_addr);
        } else {
            // Data received, process the packet
            char buffer[MAX_BUFFER_SIZE];
            socklen_t addr_len = sizeof(server_addr);

            ssize_t packet_length = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&server_addr, &addr_len);

            if (packet_length < 0) {
                perror("recvfrom failed");
                exit(EXIT_FAILURE);
            }

            double drop_probability = (double)rand() / (double)RAND_MAX;
            if (drop_probability <= DROP_THRESHOLD) {
                printf("VALUE = %g\nPacket dropped\n", drop_probability);
                // expected_byte = packet.start_byte + packet.length;
                send_ack(sockfd, expected_byte, &server_addr);
                continue;  // Drop the packet
            }

            Packet packet;
            memcpy(&packet, buffer, sizeof(Packet));
            if(expected_byte != packet.start_byte) {
                printf("\nACK != start\n");
                send_ack(sockfd, expected_byte, &server_addr);
                packets[num_packets++] = packet;
                continue;
            }

            // Store the packet
            packets[num_packets++] = packet;

            printf("\nReceived packet: start_byte = %d, length = %d\n", packet.start_byte, packet.length);

            // Update expected_byte
            expected_byte = packet.start_byte + packet.length;

            // Send ACK
            send_ack(sockfd, expected_byte, &server_addr);
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}
