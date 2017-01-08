//
// Created by lukasz on 07.01.17.
//

#ifndef TIN_P2P_CONNECTION_H
#define TIN_P2P_CONNECTION_H
#include "SocketCreator.h"
#include "Socket.h"
#include "thread"
#include "File.h"
#include "FileManager.h"
#include "FileDownload.h"

/**
 * Klasa reprezentujaca polaczenie TCP
 */
class Connection {

public:
    Connection(Socket*, FileDownload*);     // Konstruktor z podanym plikiem do wysylania
    Connection(Socket*,FileManager*);            // Konstruktor do wysylania??
    ~Connection();

    void sendFile(File*, int);
    void recieveFile(FileDownload*);
    void run();

private:
    std::thread threadId;
    FileManager *fileManager;
    int descriptor;
    bool running;
    Socket *sock;
    void interpreteMessage(Message *msg);
    void sendMessage(Message *msg);



};


#endif //TIN_P2P_CONNECTION_H
