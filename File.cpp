//
// Created by hubert on 05.01.17.
//

#include "File.h"
#include <string>
using namespace std;

File::File(string path, string name) {
    string fullPath = path + name;
    file.open (fullPath);
}

File::~File() {
    file.close();
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

