#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client 
{
private:
    int PortNumber;
    std::string ClientAddress;
    int NetworkSocket;

public: 
    
    Client(int port_number, std::string client_address);     //constructor 
    ~Client();    //deconstructor

    //setters and getters;
    void setPortNumber(int port_number);
    int getPortNumber(void);
    void setClientAddress(std::string client_address);
    std::string getClientAddress(void);

};

#endif //TCPCLIENT_H