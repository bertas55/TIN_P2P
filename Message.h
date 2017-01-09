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
    deleteFile,
    bye,
    denied
};

struct Message {
    MessageType type;

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

struct MessageHandshake : Message {
    MessageHandshake(string hostName) {
        type = handshake;
        this->hostName = hostName;
    }

    string hostName;

    string toString();
};

struct MessageRequestFile : Message {
    MessageRequestFile(string hostName, string fileName, unsigned int fileSize, unsigned int offset) {
        type = requestFile;
        this->hostName = hostName;
        this->fileName = fileName;
        this->fileSize = fileSize;
        this->offset = offset;
    }

    string hostName;
    string fileName;
    unsigned int fileSize;
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
    MessageMyList(vector<FileInfo> files) {
        type = myList;
        this->files = files;
    }

    vector<FileInfo> files;
    string toString();
};

struct MessageNewFile : Message {
    MessageNewFile(string fileName, unsigned int fileSize, string hostName) {
        type = newFile;
        this->fileName = fileName;
        this->fileSize = fileSize;
        this->hostName = hostName;
    }

    string fileName;
    unsigned int fileSize;
    string hostName;

    string toString();
};

struct MessageVeto : Message {
    MessageVeto(string fileName, unsigned int fileSize) {
        type = veto;
        this->fileName = fileName;
        this->fileSize = fileSize;
    }

    string fileName;
    unsigned int fileSize;

    string toString();
};

struct MessageDeleteFile : Message {
    MessageDeleteFile(string fileName, unsigned int fileSize, string hostName) {
        type = deleteFile;
        this->fileName = fileName;
        this->fileSize = fileSize;
        this->hostName = hostName;
    }

    string fileName;
    unsigned int fileSize;
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

#endif //TIN_P2P_MESSAGE_H
