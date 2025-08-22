#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // 1. Create TCP socket

    int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (tcp_socket < 0) {
        perror("socket");
        return 1;
    }

    // 2. Define server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port   = htons(9977);
    // Replace with "127.0.0.1" to explicitly connect to localhost
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("inet_pton");
        close(tcp_socket);
        return 1;
    }

    // 3. Connect to the server
    if (connect(tcp_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        close(tcp_socket);
        return 1;
    }
    printf("[CLIENT] Connected to server!\n");

    // 4. Send message to the server
    char message[256];

    printf("Send a message to the server!\n> ");
    scanf("%255s", message);  // prevent overflow
    send(tcp_socket, message, strlen(message)+1, 0);


    // 5. Receive response
    char server_response[256];
    memset(server_response, 0, sizeof(server_response));
    ssize_t bytes_received = recv(tcp_socket, server_response, sizeof(server_response)-1, 0);
    if (bytes_received < 0) {
        perror("recv");

    } else {
        printf("[CLIENT] Server replied: %s\n", server_response);
    }

    // 6. Close socket
    close(tcp_socket);
    printf("[CLIENT] Connection closed.\n");

    return 0;
}

