//
// Created by hubert on 05.01.17.
//

#include "MessageContainer.h"
#include <queue>
#include "Exceptions.h"
using namespace std;


MessageContainer::MessageContainer() {

}

Message MessageContainer::get() {
    lock_guard<mutex> lock(guard);

    if (!messagesQueue.empty()) {
        Message msgToReturn = messagesQueue.front();
        messagesQueue.pop();
        return msgToReturn;
    } else {
        throw NoElementsException();
    }

}

void MessageContainer::put(Message msg) {
    lock_guard<mutex> lock(guard);
    messagesQueue.push(msg);
}