//
// Created by hubert on 05.01.17.
//

#include <string>
#include "Message.h"
#include "JsonCreator.h"

using namespace std;

string Message::toString() {
    return "Base message class. You should not do this";
}

string MessageOk::toString() {
    return JsonCreator::ok();
}

string MessageHandshake::toString() {
    return JsonCreator::handshake(hostName);
}

string MessageRequestFile::toString() {
    return JsonCreator::requestFile(hostName, fileName, fileSize, offset);
}

string MessageRequestList::toString() {
    return JsonCreator::requestList(hostName);
}

string MessageMyList::toString() {
    return JsonCreator::myList(files);
}

string MessageNewFile::toString() {
    return JsonCreator::newFile(fileName, fileSize, hostName);
}

string MessageVeto::toString() {
    return JsonCreator::veto(fileName, fileSize);
}

string MessageFileRemoved::toString() {
    return JsonCreator::removedFile(fileName, fileSize, hostName);
}

string MessageBye::toString() {
    return JsonCreator::bye();
}

string MessageDenied::toString() {
    return JsonCreator::denied();
}

string MessageRevoke::toString() {
    return JsonCreator::revokeFile(fileName, fileSize);
}

