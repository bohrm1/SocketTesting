#ifndef TCPSERVER_H
#define TCPSERVER_h

#include <string>

class TCPserver 
{
private:
    int PortNumber;
    std::string ServerAddr;
    int ServerSocket; 

public: 
    TCPserver(int port_number, std::string server_addr);
    ~TCPserver();

    void setPortNumber(int port_number);
    int getPortNumber(void);
    void setServerAddress(std::string server_addr);
    std::string getServerAddress(void);


};

#endif