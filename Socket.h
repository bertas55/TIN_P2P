//
// Created by Lukasz Niedzwiedz on 05.01.17.
//

#ifndef TIN_P2P_SOCKET_H
#define TIN_P2P_SOCKET_H
#include <string>
/**
 *
 */
class Socket
{
protected:
    int descriptor;
    bool closed;

public:
    Socket(int _descriptor);
    ~Socket(void);
    bool Bind(const std::string& address, unsigned short port);
    bool Bind(unsigned short port);
    bool Listen();
    Socket* Accept();
    bool Connect(const std::string& address, unsigned short port);
    long Send(const char* bytes, unsigned long numberOfBytes);
    long Receive(char* bytes, unsigned long numberOfBytes);

    void Close(void);
    void Terminate(void);
};


#endif //TIN_P2P_SOCKET_H
