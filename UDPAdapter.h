//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_UDPADAPTER_H
#define TIN_P2P_UDPADAPTER_H

#include "Socket.h"
#include "MessageContainer.h"
#include <thread>
#include "WcisloSocket.h"
class UDPAdapter {
private:
    WcisloSocket* socket;
    std::thread UDPThread;
    MessageContainer *serverMessageContainer;

public:
    UDPAdapter(MessageContainer*, WcisloSocket*);
    ~UDPAdapter();
    void run();
    void listen();
    void send();



};


#endif //TIN_P2P_UDPADAPTER_H
