//
// Created by hubert on 05.01.17.
//

#include <vector>
#include "FileManager.h"
#include "Exceptions.h"
using namespace std;

void FileManager::lockFile(string name, unsigned int size) {
    bool success = false;
    for (auto file : files) {
        FileInfo fileInfo = file->getFileInfo();
        if (fileInfo.name == name && fileInfo.size == size) {
            file->lock();
            success = true;
            break;
        }
    }

    if (!success) {
        throw FileNotFoundException();
    }
}

void FileManager::unlockFile(string name, unsigned int size) {
    bool success = false;
    for (auto file : files) {
        FileInfo fileInfo = file->getFileInfo();
        if (fileInfo.name == name && fileInfo.size == size) {
            file->unlock();
            success = true;
            break;
        }
    }

    if (!success) {
        throw FileNotFoundException();
    }
}

bool FileManager::isFileLocked(string name, unsigned int size) {
    for (auto file : files) {
        FileInfo fileInfo = file->getFileInfo();
        if (fileInfo.name == name && fileInfo.size == size) {
            return file->isLocked();
        }
    }

    throw FileNotFoundException();
}

vector<FileInfo> FileManager::getFilesList() {
    vector<FileInfo> filesInfo;

    for (auto file : files) {
        FileInfo fileInfo = file->getFileInfo();
        filesInfo.push_back(fileInfo);
    }

    return filesInfo;
}