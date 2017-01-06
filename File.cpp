//
// Created by hubert on 05.01.17.
//

#include "File.h"
#include <string>
using namespace std;

File::File(string name) {

}

void File::lock() {
    if (!isLocked) {
        isLocked = true;
    } else {
        // throw "is already locked"
    }
}

void File::unlock() {
    if (isLocked) {
        isLocked = false;
    } else {
        // throw "is already unlocked"
    }
}

bool File::isLocked() {
    return isLocked;
}

FileInfo File::getFileInfo() {
    return FileInfo(name, size);
}

