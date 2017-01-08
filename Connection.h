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

/**
 * Klasa reprezentujaca polaczenie TCP
 */
class Connection {

public:
    Connection(Socket*, File*);     // Konstruktor z podanym plikiem do wysylania
    Connection(Socket*,FileManager*);            // Konstruktor do wysylania??
    ~Connection();

    void sendFile(File*);
    void recieveFile();
    void run();

private:
    std::thread threadId;
    FileManager *fileManager;
    int descriptor;
    bool running;
    Socket *sock;
    void interpreteMessage(Message *msg);
    void sendMessages(Message *msg);



};


#endif //TIN_P2P_CONNECTION_H
