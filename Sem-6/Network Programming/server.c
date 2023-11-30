#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    int start_byte;
    int length;
} Packet;

void send_packet(int sockfd, const struct sockaddr_in *client_addr, const Packet *packet) {
    char buffer[MAX_BUFFER_SIZE];
    memcpy(buffer, packet, sizeof(Packet));

    sendto(sockfd, buffer, sizeof(Packet), 0, (const struct sockaddr *)client_addr, sizeof(*client_addr));
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    Packet packet;
    packet.start_byte = 0;

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    memset(&client_addr, 0, sizeof(client_addr));

    // Server information
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Sender is running. Ready to send packets...\n");

    while (1) {
        char ack_data[MAX_BUFFER_SIZE];
        socklen_t addr_len = sizeof(client_addr);
        ssize_t ack_length = recvfrom(sockfd, ack_data, sizeof(ack_data), 0, (struct sockaddr *)&client_addr, &addr_len);

        if (ack_length < 0) {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        int expected_byte = atoi(ack_data);
        printf("Received ACK: expected_byte = %d\n", expected_byte);
        if(expected_byte != packet.start_byte) {
            packet.start_byte = expected_byte;
        }
        packet.length = (rand() % (15 - 5 + 1)) + 5;
        send_packet(sockfd, &client_addr, &packet);
        printf("Sent packet: start_byte = %d, length = %d\n", packet.start_byte, packet.length);
        usleep(((rand() % (5 - 1 + 1)) + 1)*100000);
        packet.start_byte += packet.length;
    }

    // Close the socket
    close(sockfd);

    return 0;
}
