//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_UDPADAPTER_H
#define TIN_P2P_UDPADAPTER_H

#include "Socket.h"
#include "MessageContainer.h"
#include <thread>
#include "WcisloSocket.h"
/**
 * Klasa reprezentujaca polaczenie UDP.
 * Mozliwe tryby pracy: Broadcast, Sluchacz
 */
class UDPAdapter {
private:
    WcisloSocket* socket;
    bool *exitFlag;
    std::thread UDPThread;
    MessageContainer *serverMessageContainer;
    bool broadcaster;
    void sendMessage(Message*);


public:
    UDPAdapter(MessageContainer*, WcisloSocket*,bool,bool*);
    ~UDPAdapter();
    void run();
    void listen();
    void send();
    void closeSocket();



};


#endif //TIN_P2P_UDPADAPTER_H
