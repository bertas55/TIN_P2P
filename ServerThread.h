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
#include "File.h"
#include "ActionContainer.h"
#include "FileManager.h"
#include "FileInfoContainer.h"

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
    FileManager *fileManager;
    std::thread threadId;
    FileInfoContainer fileInfoContainer;
    bool exitFlag;

    void sendInitialMessage();
    void sendExitMessage();
    void broadcastMessage(Message);
    void checkForMessages();
    void checkForActions();

public:
    ServerThread();
    ServerThread(ActionContainer*,FileManager*);
    ~ServerThread();

    void run();

};


#endif //TIN_P2P_SERVER_H
