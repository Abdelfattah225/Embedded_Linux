
#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <arpa/inet.h>  // sockaddr_in, inet_addr, htons
#include <stdlib.h>     // exit
#include <string.h>
#include <unistd.h>     // to use read func.

// port
#define PORT 10010
// size of buffer
#define MAX_BUFFER 1024
// flag of send syscall
#define SEND_NORMALLY 0

int main(void)
{
    int sock;

    struct sockaddr_in server_address;
     char buffer[MAX_BUFFER];
    double num1, num2;
    char op;
    // 1. create socket
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);

    }

    // server address configuration
    server_address.sin_family= AF_INET;
    server_address.sin_port=htons(PORT);

      // Convert IP from string to binary form
    if (inet_pton(AF_INET, "10.244.170.242", &server_address.sin_addr) <= 0) {
        printf("Invalid address / Address not supported\n");
        return -1;
    }

    // 3. Connect to server
    if (connect(sock, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        printf("Connection Failed\n");
        return -1;
    }
      // 4. Get input from user
    printf("Enter first number: ");
    scanf("%lf", &num1);
    printf("Enter second number: ");
    scanf("%lf", &num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);

    // 5. Send data to server
    sprintf(buffer, "%lf %c %lf", num1, op, num2);
    send(sock, buffer, strlen(buffer), 0);

    // 6. Receive result from server
    memset(buffer, 0, MAX_BUFFER);
    read(sock, buffer, MAX_BUFFER);
    printf("%s\n", buffer);

    // 7. Close socket
    close(sock);

}