#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <unistd.h>

int main(){

	// create socket
	int tcp_socket = socket(AF_INET, SOCK_STREAM, 0);

	// validation
	if(tcp_socket < 0){
		printf("[SOCKET CREATION ERR] An error has ocurred when creating the socket");
		return 1;
	}

	// define server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9977);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind socket to specified IP and port
	bind(tcp_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	char client_request[256];
	char server_message[256] = "Server received your message! \n\n";
	int client_socket;

	listen(tcp_socket, 5);



	// Docs: https://pubs.opengroup.org/onlinepubs/7908799/xns/accept.html
	/*
		*
		* int accept (int socket, struct sockaddr *address,
																 socklen_t *address_len);
		* If data from sender is required, pass a pointer to a sockaddr and it's length. 
		* The struct will be filled with the data from the sender.
		* 
		*/

	client_socket = accept(tcp_socket, NULL, NULL);
	recv(client_socket, &client_request, sizeof(client_request), 0);
	send(client_socket, server_message, sizeof(server_message), 0);
	close(tcp_socket);

	return 0;
}
