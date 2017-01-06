//
// Created by hubert on 05.01.17.
//

#include <vector>
#include "FileManager.h"
#include "Exceptions.h"
#include <dirent.h>
#include <stdlib.h>
#include "Configuration.h"

using namespace std;

FileManager::FileManager() {
    DIR *dir;
    const char* dirPath = Configuration::getDirectoryPath();
    struct dirent *ent;
    if ((dir = opendir (dirPath)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            printf ("%s\n", ent->d_name);
        }
        closedir (dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }
}

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