#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h> //included this for the close function
#define _XOPEN_SOURCE_EXTENDED 1

#include <netinet/in.h> //contains socket structs

int main()
{

	// creating client socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	// specify an address for the socket to connect to
	struct sockaddr_in server_address;
	// need to define a few fields within the sockaddr_in struct
	// what is the family
	server_address.sin_family = AF_INET;
	// specify port
	// htons = host to network (making sure data format is correct)
	// puts integer port into correct byte order
	// pass the actual port, htons takes care of conversion
	server_address.sin_port = htons(9002);

	// specify actual address
	// server_address is a struct with a sin_addr struct member which contains
	// s_addr field
	// conecting to loval machine, can use any address connected to local machine
	server_address.sin_addr.s_addr = INADDR_ANY;

	// first arg is actual socket
	// 2nd param, need to cast pointer  to struct sockaddr
	// 3rd param is size of address
	int connection_status = connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));

	// check for error with connection. if connect = -1, means error connecting
	if (connection_status == -1)
	{
		printf("There was an error making a connection to the remote socket\n\n");
	}

	// recieve data from the server using recv function
	char server_response[256]; // hold message that we get back from server
	recv(network_socket, &server_response, sizeof(server_response), 0);

	// print out the server's response
	printf("The server sent the data: %s", server_response);

	// and then close the socket
	close(network_socket);

	return 0;
}