//
// Created by lukasz on 06.01.17.
//

#ifndef TIN_P2P_SERVERINTERFACE_H
#define TIN_P2P_SERVERINTERFACE_H
#include "ServerThread.h"
#include <string>

enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, Exit };


class ServerInterface {
public:
    ServerInterface();
    ~ServerInterface();

    void userAction(UserAction);

private:
    ServerThread *server;
    string serverPort, clientPort;
    string broadcastAdress;

    void fileManagerAction(UserAction);
    void putServerAction(UserAction);
    bool loadConfig(string);
};


#endif //TIN_P2P_SERVERINTERFACE_H
