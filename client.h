#ifndef CLIENT_H
#define CLIENT_H
constexpr int MAXLINE = 1024;

#include <string>

class Client 
{
private:
    int PortNumber;
    std::string ClientAddress;
    std::string CommsProtocol;
    int ClientSocket;              
    char server_response[MAXLINE]; 
    int ConnectionStatus;

    ::sockaddr_in server_address;
    ::sockaddr_in* serveraddr_ptr = &server_address;
    socklen_t server_address_length = sizeof(server_address);

public: 
    
    Client(int port_number, std::string client_address, std::string comms_protocol);     //constructor 
    ~Client();    //deconstructor


    int getPortNumber(void);
    std::string getClientAddress(void);
    void setCommsProtocol(std::string comms_protocol);
    std::string getCommmsProtocol(void);

    void send(void);
    void receive(void);
};

#endif //TCPCLIENT_H