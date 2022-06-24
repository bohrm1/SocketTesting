#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client 
{
private:
    int PortNumber;
    std::string ClientAddress;
    std::string CommsProtocol;
    int NetworkSocket;

public: 
    
    Client(int port_number, std::string client_address, std::string comms_protocol);     //constructor 
    ~Client();    //deconstructor

    //setters and getters;
    void setPortNumber(int port_number);
    int getPortNumber(void);
    void setClientAddress(std::string client_address);
    std::string getClientAddress(void);
    void setCommsProtocol(std::string comms_protocol);
    std::string getCommmsProtocol(void);

};

#endif //TCPCLIENT_H