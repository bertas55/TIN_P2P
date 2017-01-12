//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_SOCKETCREATOR_H
#define TIN_P2P_SOCKETCREATOR_H
#include "Socket.h"
#include "UDPSocket.h"
/**
 * Singleton reprezentujacy
 */
class SocketCreator {
public:
    static Socket* CreateSocket(void);
    static Socket* CreateSocket(const std::string& address, unsigned short port, bool connect);
    static UDPSocket* CreateServerSocket(void);
    static UDPSocket* CreateServerSocket(unsigned short port);
    static UDPSocket* broadcasterSocket(void);
    static UDPSocket* broadcasterSenderSocket(void);
    static Socket* createTCPListener();

private:
    SocketCreator(void);
    SocketCreator(const SocketCreator&);
    SocketCreator& operator=(const SocketCreator&);
};


#endif //TIN_P2P_SOCKETCREATOR_H