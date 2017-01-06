//
// Created by hubert on 05.01.17.
//

#include "File.h"
#include <string>
using namespace std;

File::File(string path, string name) {
    string fullPath = path + name;
    file.open (fullPath);
    this->name = name;
    this->size = readSize();
}

File::~File() {
    file.close();
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

struct FileInfo File::getFileInfo() {
    return FileInfo(name, size);
}

