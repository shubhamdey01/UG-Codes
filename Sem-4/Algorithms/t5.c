#include <stdio.h>
#include <string.h>

#define N 25

void reverse(char *msg) {
    char str[N];
    strcpy(str, msg);
    int i = strlen(str)-1, j=0;
    for(i; i>=0; i--, j++)
    {
        msg[j] = str[i];
        printf("%c",str[i]);
    }
    msg[j] ='\0';
}

int main() {
    char msg[N];
    printf("Enter : ");
    scanf("%s", msg);
    reverse(msg);
    printf("\n%s\n",msg);
}