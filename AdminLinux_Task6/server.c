/*
TCPCalculator.md 2025-10-31
1 / 1
Task 7: TCP-Based RPC Client-Server Calculator
Description
TCP is a Transport Layer protocol characterized by its reliabe connection between two hosts. Here,
TCP is utilized to perform a Remote Procedure Call (RPC): allowing the client to invoke an operation
at the server and asking for its return. In the case of a calculator, the client takes two numbers from
the user, sends them to the server where a certain operation is performed, then the server responds
with the result.
Demo
Requirements
Create two python scripts for TCP client and server respectively with the described behaviour.
Screenshot the scripts running twice: once on the same PC and another when each script is running
on a different machine.
*/

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
    int server_fd ;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    

    char buffer[MAX_BUFFER];

    // 1. create socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);

    }

    // 2. Prepare the sockaddr_in structure
    
    // IPv4
    address.sin_family= AF_INET;
    
    // Listen on all interfaces
    address.sin_addr.s_addr=INADDR_ANY;

    // Set port (convert to network byte order)
    address.sin_port=htons(PORT);

    // 3. Bind Socket to IP + PORT ==> assigning a name to a socket
    if((bind(server_fd, (struct sockaddr*)&address, addrlen)) < 0)
    {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }


    // 4. Listen for connection
    if((listen(server_fd, 3)) < 0)
    {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);
    
    // 5. accept connection 
    int new_socket = accept(server_fd,(struct sockaddr*)&address , (socklen_t*)&addrlen);
    if(new_socket < 0)
    {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from client\n");

    // 6. Recieve data

    // fill memory with a constant byte{0}
    memset(buffer, 0,MAX_BUFFER);

    read(new_socket, buffer, MAX_BUFFER);


    // expected format : num1 op num2 
    double num1 , num2 , result ;
    char op ;
    sscanf(buffer," %lf %c %lf",&num1, &op , &num2);


    // 7. Perform calculation
    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = num2 != 0 ? num1 / num2 : 0; break;
        default: result = 0; break;
    }

    // 8. send result back
    sprintf(buffer,"Result: %lf\n",result);
    send(new_socket,buffer,MAX_BUFFER,SEND_NORMALLY);

     // 9. Close sockets
    close(new_socket);
    close(server_fd);

    return 0;



}