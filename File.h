//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_FILE_H
#define TIN_P2P_FILE_H

#include <string>
#include <fstream>
using namespace std;

enum FileState {
    blocked,
    toRemove,
    normal
};

class File {

public:
    File(string path, string name);

    ~File();

    char* getFilePart();

    void lock();

    void unlock();

    bool isLocked();

    struct FileInfo getFileInfo();

private:
    fstream file;
    string name;
    unsigned int size;
    bool owner;
    bool locked;
    FileState state;

    std::ifstream::pos_type readSize();
};

struct FileInfo {
    string name;
    unsigned int size;

    FileInfo(string name, unsigned int size) {
        this->name = name;
        this->size = size;
    }
};


#endif //TIN_P2P_FILE_H
