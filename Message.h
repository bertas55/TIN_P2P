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
    deleteFile
};

struct Message {

    MessageType type;

};

struct MessageHello : Message {
    MessageHello() {
        type = hello;
    }
};

struct MessageHandshake : Message {
    MessageHandshake(string hostName) {
        type = handshake;
        this.hostName = hostName;
    }

    string hostName;
};

struct MessageRequestFile : Message {
    MessageRequestFile(string hostName, string fileName, unsigned int fileSize, unsigned int offset)) {
        type = requestFile;
        this.hostName = hostName;
        this.fileName = fileName;
        this.fileSize = fileSize;
        this.offset = offset;
    }

    string hostName;
    string fileName;
    unsigned int fileSize;
    unsigned int offset;
};

struct MessageRequestList : Message {
    MessageRequestList() {
        type = requestList;
    }
};

struct MessageMyList : Message {
    MessageMyList() {
        type = myList;
    }
};

struct MessageNewFile : Message {
    MessageNewFile() {
        type = newFile;
    }
};

struct MessageVeto : Message {
    MessageVeto() {
        type = veto;
    }
};

struct MessageDeleteFile : Message {
    MessageDeleteFile() {
        type = deleteFile;
    }
};








#endif //TIN_P2P_MESSAGE_H
