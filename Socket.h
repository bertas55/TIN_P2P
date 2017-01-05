//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_SOCKET_H
#define TIN_P2P_SOCKET_H
#include <string>

class Socket
{
private:
    int descriptor;
    bool closed;

public:
    Socket(int _descriptor);
    ~Socket(void);
    bool Bind(const std::string& address, unsigned short port);
    bool Connect(const std::string& address, unsigned short port);
    long Send(const char* bytes, unsigned long numberOfBytes);
    long Receive(char* bytes, unsigned long numberOfBytes);
    void Close(void);
};


#endif //TIN_P2P_SOCKET_H
