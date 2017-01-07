//
// Created by hubert on 05.01.17.
//

#include <string>
#include "Message.h"
#include "JsonCreator.h"

using namespace std;

string Message::toString() {
    // unimplemented
    return "base";
}

string MessageHello::toString() {
    return JsonCreator::hello();
}

string MessageHandshake::toString() {
    return JsonCreator::handshake(hostName);
}

string MessageRequestFile::toString() {
    return JsonCreator::requestFile(hostName, fileName, fileSize, offset);
}

string MessageRequestList::toString() {
    return JsonCreator::requestList();
}

string MessageMyList::toString() {
    return "Not implemented yet";
}

string MessageNewFile::toString() {
    return "Not implemented yet";
}

string MessageVeto::toString() {
    return "Not implemented yet";
}

string MessageDeleteFile::toString() {
    return "Not implemented yet";
}

string MessageBye::toString() {
    return "Not implemented yet";
}


