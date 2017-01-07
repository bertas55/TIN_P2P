//
// Created by lukasz on 07.01.17.
//

#include "ActionContainer.h"
#include "Exceptions.h"

ActionContainer::ActionContainer()
{

}

Action ActionContainer::get() {
    lock_guard<mutex> lock(guard);

    if (!actionQueue.empty()) {
        Action msgToReturn = actionQueue.front();
        actionQueue.pop();
        return msgToReturn;
    } else {
        throw NoElementsException();
    }

}

void ActionContainer::put(Action a) {
    lock_guard<mutex> lock(guard);
    actionQueue.push(a);
}