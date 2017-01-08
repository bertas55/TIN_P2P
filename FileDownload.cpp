//
// Created by hubert on 08.01.17.
//

#include "FileDownload.h"

FileDownload::FileDownload(string name, unsigned int size) : File(name) {
    this->path = Constants::Configuration::downloadPath;
    this->size = size;
    int partsCount;
    partsCount = (size + Constants::File::partSize - 1) / Constants::File::partSize;
    for (int i = 0; i < partsCount; i++) {
        addPartToDownload(i);
    }
}

unsigned int FileDownload::getPartToDownload() {
    if (partsLeft.empty()) {
        return -1;
    }
    unsigned int part = partsLeft.front();
    partsLeft.pop();
    return part;
}

unsigned long FileDownload::partsLeftCount() {
    return partsLeft.size();
}

void FileDownload::addPartToDownload(unsigned int partNumber) {
    partsLeft.push(partNumber);
}