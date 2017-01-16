//
// Created by Lukasz Niedzwiedz on 05.01.17.
//

#ifndef TIN_P2P_SERVER_H
#define TIN_P2P_SERVER_H

#include "Socket.h"
#include "UDPAdapter.h"
#include "MessageContainer.h"
#include "Message.h"
#include "SocketCreator.h"
#include "File.h"
#include "ActionContainer.h"
#include "FileManager.h"
#include "FileInfoContainer.h"
#include "TCPManager.h"
#include "LogContainer.h"

/**
 * Klasa reprezentujaca watek nadzorcy serwera.
 * Sprawdza komunikaty i akcje, nakazujac wykonanie zwiazanaych z nimi funkcji.
 *
 */
class ServerThread {
private:
    UDPAdapter *UDPBroadcaster;
    UDPAdapter *UDPReciver;
    MessageContainer inputMessages; /*Messages recived*/
    MessageContainer outputMessage; /*Messages to send via broadcast*/
    ActionContainer *actionContainer;
    LogContainer* logContainer;
    FileManager *fileManager;
    TCPManager *tcpManager;
    std::thread threadId;
    FileInfoContainer fileInfoContainer;
    bool exitFlag;

    void sendExitMessage();
    void broadcastMessage(Message*);
    void checkForMessages();
    void checkForActions();

public:
    ServerThread();
    ServerThread(ActionContainer*,FileManager*,LogContainer*);
    ~ServerThread();

    void run();

};


#endif //TIN_P2P_SERVER_H
