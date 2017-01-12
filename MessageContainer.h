//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_MESSAGECONTAINER_H
#define TIN_P2P_MESSAGECONTAINER_H

#include "Message.h"
#include "File.h"
#include <queue>
#include <mutex>
using namespace std;

/**
 * Kontener wiadomosci.
 * Dodawanie i pobieranie wiadomosci jest kontrolowane przez mutex.
 */
class MessageContainer {

public:

    MessageContainer();

    Message* get();

    void put(Message *msg);

    int getSize();

private:
    queue<Message*> messagesQueue;
    mutex guard;
};




#endif //TIN_P2P_MESSAGECONTAINER_H
