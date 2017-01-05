//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_UDPADAPTER_H
#define TIN_P2P_UDPADAPTER_H

#include "Socket.h"
#include <thread>

class UDPAdapter {
private:
    Socket socket;
    std::thread UDPThread;
    //CONTAINER *c;

public:
    UDPAdapter();
    ~UDPAdapter();

    void listen();
    void send();



};


#endif //TIN_P2P_UDPADAPTER_H
