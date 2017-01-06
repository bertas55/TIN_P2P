//
// Created by hubert on 05.01.17.
//

#include "FileManager.h"

void FileManager::lockFile(string name, unsigned int size) {
    for (auto file : files) {
        FileInfo fileInfo = file->getFileInfo();
        if (fileInfo.name == name && fileInfo.size == size) {

        }
    }
}