//
// Created by lukasz on 09.01.17.
//

#include "LogContainer.h"
#include "Exceptions.h"

LogContainer::LogContainer()
{

}

struct Log LogContainer::get() {
    std::lock_guard<std::mutex> lock(guard);

    if (!logContainer.empty()) {
        struct Log logToReturn = logContainer.front();
        logContainer.pop();
        return logToReturn;
    } else {
        throw NoElementsException();
    }

}

void LogContainer::put(struct Log a) {
    std::lock_guard<std::mutex> lock(guard);
    logContainer.push(a);
}

unsigned long LogContainer::size()
{
    return logContainer.size();
}