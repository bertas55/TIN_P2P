//
// Created by lukasz on 06.01.17.
//

#ifndef TIN_P2P_SERVERINTERFACE_H
#define TIN_P2P_SERVERINTERFACE_H
#include "ServerThread.h"
#include "File.h"
#include <string>
#include "ActionContainer.h"
#include "FileManager.h"


class ServerInterface {
public:
    ServerInterface();
    ~ServerInterface();

    void consoleInterface();
    void downloadFile(int index);
    void refreshList();
    void enableFile(File*);
    void disableFile(File*);
    void userExit();
    void getDownloadProgress(File);
    void removeFile(File *);


private:
    ServerThread *server;
    FileManager fileManager;
    ActionContainer container;
    string serverPort, clientPort;
    string broadcastAdress;

    void putServerAction(UserAction);
};


#endif //TIN_P2P_SERVERINTERFACE_H
