//
// Created by lukasz on 07.01.17.
//

#ifndef TIN_P2P_CONNECTION_H
#define TIN_P2P_CONNECTION_H
#include "SocketCreator.h"
#include "Socket.h"
#include "thread"
#include "File.h"

/**
 * Klasa reprezentujaca polaczenie TCP
 */
class Connection {

public:
    Connection(Socket*, File*);     // Konstruktor z podanym plikiem do wysylania
    Connection(Socket*);            // Konstruktor do wysylania??
    ~Connection();

    void sendFile(File*);
    void recieveFile();

private:
    std::thread threadId;
    int descriptor;
    Socket *sock;


};


#endif //TIN_P2P_CONNECTION_H
