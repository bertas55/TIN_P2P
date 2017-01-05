//
// Created by hubert on 05.01.17.
//

#include "MessageContainer.h"
#include <queue>
using namespace std;


MessageContainer::MessageContainer() {

}

Message MessageContainer::get() {
    Message msgToReturn = messagesQueue.front();
    messagesQueue.pop();
    return msgToReturn;
}

void MessageContainer::put(Message msg) {
    messagesQueue.push(msg);
}