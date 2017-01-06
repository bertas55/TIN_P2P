//
// Created by lukasz on 05.01.17.
//

#ifndef TIN_P2P_SERVER_H
#define TIN_P2P_SERVER_H

#include "Socket.h"
#include "UDPAdapter.h"
#include "MessageContainer.h"
#include "Message.h"
#include "SocketCreator.h"

/**
 *
 */
class ServerThread {
private:
    UDPAdapter *UDPBroadcaster;
    UDPAdapter *UDPReciver;
    MessageContainer inputMessages; /*Messages recived*/
    MessageContainer outputMessage; /*Messages to send via broadcast*/
    std::thread threadId;
    WcisloSocket *serverSocket;

    void broadcastMessage(Message);
    void checkForMessages();

public:
    ServerThread();
    ~ServerThread();

    void run();

};


#endif //TIN_P2P_SERVER_H
