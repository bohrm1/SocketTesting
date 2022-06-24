#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <string>

class TCPclient 
{
private:
    int PortNumber;
    std::string ClientAddress;
    int NetworkSocket;

public: 
    
    TCPclient(int port_number, std::string client_address);     //constructor 
    ~TCPclient();    //deconstructor

    //setters and getters;
    void setPortNumber(int port_number);
    int getPortNumber(void);
    void setClientAddress(std::string client_address);
    std::string getClientAddress(void);

};

#endif //TCPCLIENT_H