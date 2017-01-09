//
// Created by hubert on 05.01.17.
//

#include "File.h"
#include "Constants.h"
#include "Exceptions.h"
#include <string>
#include <iostream>

using namespace std;

File::File(string name) {
    this->name = name;
    this->path = Constants::Configuration::directoryPath;
    this->size = readSize();
}

std::ifstream::pos_type File::readSize()
{
    std::ifstream in(name, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

void File::lock() {
    if (!locked) {
        locked = true;
    } else {
        // throw "is already locked"
    }
}

void File::unlock() {
    if (locked) {
        locked = false;
    } else {
        // throw "is already unlocked"
    }
}

bool File::isLocked() {
    return locked;
}

string File::getName() {
    return name;
}

unsigned int File::getSize() {
    return size;
}

struct FileInfo File::getFileInfo() {
    return FileInfo(name, size, blocked, owner);
}

char* File::getFilePart(unsigned int partNumber) {
    unsigned int offset = partNumber * Constants::File::partSize;
    if (offset + Constants::File::partSize >= size) {
        throw OutOfRangeException();
    }
    string fullPath = path + name;
    ifstream file(fullPath);
    if (!file.is_open()) {
        throw LoadingFileException();
    }
    file.seekg(offset);
    unsigned int readLength = min(Constants::File::partSize, size - offset);
    char *buff = new char[readLength];
    file.read(buff, readLength);
    file.close();
    return buff;
}

void File::saveFilePart(unsigned int partNumber, unsigned int dataLength, char *data) {
//    std::lock_guard<std::mutex> lock(guard);
    unsigned int offset = partNumber * Constants::File::partSize;
    if (offset + dataLength > size) {
        throw OutOfRangeException();
    }
    string fullPath = path + name;
    ofstream file(fullPath,ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        throw LoadingFileException();
    }
    file.seekp(offset, ios::beg);
//    file.put('X');
    file.write(data, dataLength);
//    file.write("X", 1);
    file.close();
}
