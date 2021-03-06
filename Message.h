//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_MESSAGE_H
#define TIN_P2P_MESSAGE_H

#include <string>
#include <vector>
#include "File.h"

using namespace std;

enum MessageType {
    ok,
    handshake,
    requestFile,
    requestList,
    myList,
    newFile,
    veto,
    removedFile,
    bye,
    denied,
    revokeFile,
    myFile,
    checksumPart
};

struct Message {
    MessageType type;
    string hostName;
    virtual string toString();

    Message() {};
    virtual ~Message() {};
};

struct MessageOk : virtual Message {
    MessageOk() {
        type = ok;
    }

    string toString();
};

struct MessageRequestFile : Message {
    MessageRequestFile(string hostName, string fileName, unsigned long fileSize, unsigned int offset) {
        type = requestFile;
        this->hostName = hostName;
        this->fileName = fileName;
        this->fileSize = fileSize;
        this->offset = offset;
    }

    string hostName;
    string fileName;
    unsigned long fileSize;
    unsigned int offset;

    string toString();
};

struct MessageRequestList : Message {
    MessageRequestList(string hostName) {
        type = requestList;
        this->hostName = hostName;
    }

    string hostName;

    string toString();
};

struct MessageMyList : Message {
    MessageMyList() {
        type = myList;
    }

    string toString();
};

struct MessageNewFile : Message {
    MessageNewFile(string fileName, unsigned long fileSize, string hostName) {
        type = newFile;
        this->fileName = fileName;
        this->fileSize = fileSize;
        this->hostName = hostName;
    }

    string fileName;
    unsigned long fileSize;
    string hostName;

    string toString();
};

struct MessageVeto : Message {
    MessageVeto(string fileName, unsigned long fileSize) {
        type = veto;
        this->fileName = fileName;
        this->fileSize = fileSize;
    }

    string fileName;
    unsigned long fileSize;

    string toString();
};

struct MessageFileRemoved : Message {
    MessageFileRemoved(string fileName, unsigned long fileSize, string hostName) {
        type = removedFile;
        this->fileName = fileName;
        this->fileSize = fileSize;
        this->hostName = hostName;
    }

    string fileName;
    unsigned long fileSize;
    string hostName;

    string toString();
};

struct MessageBye : Message {
    MessageBye() {
        type = bye;
    }

    string toString();
};

struct MessageDenied : Message {
    MessageDenied() {
        type = denied;
    }

    string toString();
};

struct MessageRevoke : Message {
    MessageRevoke(string fileName, unsigned long fileSize) {
        type = revokeFile;
        this->fileName = fileName;
        this->fileSize = fileSize;
    }

    string fileName;
    unsigned long fileSize;

    string toString();
};

struct MessageMyFile : Message {
    MessageMyFile(string fileName, unsigned long fileSize, string hostName, bool locked, bool owner) {
        type = myFile;
        this->fileName = fileName;
        this->fileSize = fileSize;
        this->hostName = hostName;
        this->owner = owner;
        this->locked = locked;
    }

    string fileName;
    unsigned long fileSize;
    string hostName;
    bool owner;
    bool locked;

    string toString();
};

struct MessageChecksum : Message {
    MessageChecksum(string checksum) {
        type = checksumPart;
        this->checksum = checksum;
    }

    string checksum;

    string toString();
};

#endif //TIN_P2P_MESSAGE_H
