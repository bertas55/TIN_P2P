//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_SOCKETCREATOR_H
#define TIN_P2P_SOCKETCREATOR_H
#include "Socket.h"
#include "WcisloSocket.h"

class SocketCreator {
public:
    static Socket* CreateSocket(void);
    static Socket* CreateSocket(const std::string& address, unsigned short port, bool connect);
    static WcisloSocket* CreateServerSocket(void);
    static WcisloSocket* CreateServerSocket(unsigned short port);

private:
    SocketFactory(void);
    SocketFactory(const SocketFactory&);
    SocketFactory& operator=(const SocketFactory&);
};


#endif //TIN_P2P_SOCKETCREATOR_H
