#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>


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

    server_address.sin_addr.s_addr = INADDR_ANY;


    // 3. Bind socket to the specified IP and port
    if (bind(tcp_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        close(tcp_socket);
        return 1;
    }

    // 4. Listen for incoming connections
    if (listen(tcp_socket, 5) < 0) {
        perror("listen");

        close(tcp_socket);
        return 1;
    }
    printf("[SERVER] Listening on port 9977...\n");

    // 5. Accept a client
    int client_socket = accept(tcp_socket, NULL, NULL);
    if (client_socket < 0) {

        perror("accept");
        close(tcp_socket);

        return 1;
    }
    printf("[SERVER] Client connected!\n");

    // 6. Receive data from the client
    char client_request[256];
    memset(client_request, 0, sizeof(client_request));
    ssize_t bytes_received = recv(client_socket, client_request, sizeof(client_request)-1, 0);
    if (bytes_received < 0) {
        perror("recv");
    } else {
        printf("[SERVER] Received: %s\n", client_request);
    }

    // 7. Send response back
    char server_message[] = "Server received your message!\n";
    send(client_socket, server_message, sizeof(server_message), 0);

    // 8. Close sockets
    close(client_socket);
    close(tcp_socket);
    printf("[SERVER] Connection closed.\n");

    return 0;
}

