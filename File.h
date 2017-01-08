//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_FILE_H
#define TIN_P2P_FILE_H

#include <string>
#include <fstream>
#include "Constants.h"
using namespace std;

enum FileState {
    blocked,
    toRemove,
    normal
};

class File {

public:
    File(string path, string name);

    char* getFilePart(unsigned int);

    void saveFilePart(unsigned int, unsigned int, char*);

    string getName();

    unsigned int getSize();

    void lock();

    void unlock();

    bool isLocked();

    struct FileInfo getFileInfo();

private:
    string name;
    string path;
    unsigned int size;
    bool owner;
    bool locked;
    FileState state;

    std::ifstream::pos_type readSize();
};

struct FileInfo {
    string name;
    unsigned int size;
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
};


#endif //TIN_P2P_FILE_H
