//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_MESSAGE_H
#define TIN_P2P_MESSAGE_H

#include <string>
using namespace std;

enum MessageType {
    hello,
    handshake,
    requestFile,
    requestList,
    myList,
    newFile,
    veto,
    deleteFile,
    bye
};

struct Message {
    MessageType type;

    virtual string toString();

    Message() {};
    virtual ~Message() {};
};

struct MessageHello : virtual Message {
    MessageHello() {
        type = hello;
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
    MessageRequestList() {
        type = requestList;
    }

    string toString();
};

struct MessageMyList : Message {
    MessageMyList() {
        type = myList;
    }

    string toString();
};

struct MessageNewFile : Message {
    MessageNewFile() {
        type = newFile;
    }

    string toString();
};

struct MessageVeto : Message {
    MessageVeto() {
        type = veto;
    }

    string toString();
};

struct MessageDeleteFile : Message {
    MessageDeleteFile() {
        type = deleteFile;
    }

    string toString();
};

struct MessageBye : Message {
    MessageBye() {
        type = bye;
    }

    string toString();
};






#endif //TIN_P2P_MESSAGE_H
