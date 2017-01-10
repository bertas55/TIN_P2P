//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_FILE_H
#define TIN_P2P_FILE_H

#include <string>
#include <fstream>
#include <mutex>
#include "Constants.h"
using namespace std;

enum FileState {
    blocked,
    toRemove,
    s
};

struct Data {
    char* data;
    unsigned int checksum;

    Data(char* data, unsigned int checksum) {
            this->data = data;
            this->checksum = checksum;
    }
};

class File {

public:
    File(string name, string path);

    Data getFilePart(unsigned int);

    void saveFilePart(unsigned int, unsigned int, char*);

    string getName();

    unsigned long getSize();

    void lock();

    void unlock();

    bool isLocked();

    bool isOwner();

    struct FileInfo getFileInfo();

protected:
    string name;
    string path;
    unsigned int size;
    bool owner;
    bool locked;
    FileState state;
    mutex guard;

    std::ifstream::pos_type readSize();
    unsigned int genChecksum(char*);
};

struct FileInfo {
    string name;
    unsigned long size;
    string hostAddress;
    bool blocked;
    bool owner;

    FileInfo(string name, unsigned int size, bool blocked, bool owner) {
        this->name = name;
        this->size = size;
        this->hostAddress = Constants::Configuration::localhostAddress;
        this->blocked = blocked;
        this->owner = owner;
    }
    FileInfo(string name, unsigned int size, bool blocked, bool owner, string host) {
            this->name = name;
            this->size = size;
            this->hostAddress = host;
            this->blocked = blocked;
            this->owner = owner;
    }

};


#endif //TIN_P2P_FILE_H
