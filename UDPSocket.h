//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_UDPSOCKET_H
#define TIN_P2P_UDPSOCKET_H
#include "Socket.h"
#include <string>
/**
 * Klasa reprezentujaca gniazdo UDP
 */
class UDPSocket : public Socket {

public:
    UDPSocket(int);
    ~UDPSocket();
    bool Bind(unsigned short port);
    bool Listen(void);
    Socket* Accept(void);
    bool setBroadcast();
    bool setBroadcastListerner();
    long Send(const char* bytes, unsigned long numberOfBytes);
    char* Receive(char* bytes, unsigned long numberOfBytes);

private:
    int broadcastEnable;

};


#endif //TIN_P2P_UDPSOCKET_H
