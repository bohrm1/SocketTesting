#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>
#include <string.h>

class Server 
{
private:
    int PortNumber;
    std::string ServerAddr;
    std::string CommsProtocol;
    
    int ServerSocket; 
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
};

#endif