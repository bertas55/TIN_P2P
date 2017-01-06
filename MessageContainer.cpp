//
// Created by hubert on 05.01.17.
//

#include "MessageContainer.h"
#include <queue>
#include <iostream>
using namespace std;


MessageContainer::MessageContainer() {

}

Message MessageContainer::get() {
    lock_guard<mutex> lock(guard);
    Message msgToReturn = messagesQueue.front();
    messagesQueue.pop();
//    if (msgToReturn == NULL) cout << "dupa\n";
    return msgToReturn;
}

void MessageContainer::put(Message msg) {
    lock_guard<mutex> lock(guard);
    messagesQueue.push(msg);
}