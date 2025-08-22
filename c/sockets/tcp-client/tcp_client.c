#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <unistd.h>

int main(){

	// Docs: https://pubs.opengroup.org/onlinepubs/7908799/xns/socket.html

	// Step 1.- Create socket	
	// NOTE: SOCK_STREAM = TCP 
	int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	if(tcp_socket < 0){
		printf("[SOCKET CREATION ERR] An error has ocurred when creating the socket");
		return 1;
	}

	/*
	* Test to see what does tcp_socket returns.
	*/
	// printf("%d", tcp_socket);
	// return 0;

	// Specify address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9977);
	server_address.sin_addr.s_addr = INADDR_ANY; // 0.0.0.0

	// server address (type -> sockaddr_in) must be cased to sockaddr*
	// named connection status because returns 0 if ok, -1 and errno if error.
	int connection_status = connect(tcp_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	if(connection_status < 0){
		printf("[CONNECTION ERR] An error has ocurred when connecting the socket");
		return 1;
	}

	int server_socket = accept(tcp_socket, NULL, NULL);

	// Send message to the server
	char message[256];
	printf("Send a message to the server! \n> ");
	scanf("%s", message);
	send(server_socket, message, sizeof(message), 0);

	// Receive data from the server
	char server_response[256];
	recv(tcp_socket, &server_response, sizeof(server_response), 0);

	// Print received data
	printf("The server sent a message: \n%s\n", server_response);

	// Close the socket
	close(tcp_socket);
	
	return 0;
}
