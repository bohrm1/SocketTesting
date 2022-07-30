#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <string.h>
constexpr int MAXLINE_CLIENTBUFFER = 1024;

class Server 
{
private:
    int PortNumber;
    std::string ServerAddr;
    std::string CommsProtocol;
    int ServerSocket, ClientSocket;
    char buffer[MAXLINE_CLIENTBUFFER];   //used for storing message from client using UDP
    ::sockaddr_in server_address, client_address;
    ::sockaddr_in* serveraddr_ptr = &server_address;
    ::sockaddr_in* clientaddr_ptr = &client_address;

public: 
    Server(int port_number, const std::string &server_addr, const std::string &comms_protocol);
    ~Server();

    int getPortNumber(void);
    std::string getServerAddress(void);
    void setCommsProtocol(std::string comms_protocol);
    std::string getCommsProtocol(void);

    void send(const std::string &server_message);
    void receive (void);
};

#endif

