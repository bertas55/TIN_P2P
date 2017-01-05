//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_SERVER_H
#define TIN_P2P_SERVER_H

#include "Socket.h"
#include "UDPAdapter.h"
/**
 *
 */
class ServerThread {
private:
    UDPAdapter UDPBroadcaster;
    UDPAdapter UDPReciver;
    std::thread serverThread;
public:
    ServerThread();
    ~ServerThread();

    void run();

};


#endif //TIN_P2P_SERVER_H
