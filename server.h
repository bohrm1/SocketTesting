#ifndef SERVER_H
#define SERVER_H

#include <string.h>

class Server 
{
private:
    int PortNumber;
    std::string ServerAddr;
    std::string CommsProtocol;
    int ServerSocket; 

public: 
    Server(int port_number, std::string server_addr, std::string comms_protocol);
    ~Server();

    void setPortNumber(int port_number);
    int getPortNumber(void);
    void setServerAddress(std::string server_addr);
    std::string getServerAddress(void);
    void setCommsProtocol(std::string comms_protocol);
    std::string getCommsProtocol(void);
};

#endif