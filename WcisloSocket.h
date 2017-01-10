//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_WCISLOSOCKET_H
#define TIN_P2P_WCISLOSOCKET_H
#include "Socket.h"
#include <string>
/**
 * Sebek - The Horse Puncher
 * Klasa poki co do UDP broadcast i odbieranie broadcastow
 */
class WcisloSocket : public Socket {

public:
    WcisloSocket(int);
    ~WcisloSocket();
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


#endif //TIN_P2P_WCISLOSOCKET_H
