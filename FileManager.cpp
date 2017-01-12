//
// Created by hubert on 05.01.17.
//

#include <vector>
#include "FileManager.h"
#include "Exceptions.h"
#include <dirent.h>
#include <stdlib.h>

using namespace std;

FileManager::FileManager() {
//    loadFiles();
}

File* FileManager::addFile(string name, string path)
{
    File* newFile = new File(name,path);
    files.push_back(newFile);
    return newFile;
}

void FileManager::addFile(File* file)
{
    files.push_back(file);
}
void FileManager::loadFiles() {
    if (Constants::Configuration::debugMode) {
        DIR *dir;
        const char* dirPath = ".";
        struct dirent *ent;
        if ((dir = opendir (dirPath)) != NULL) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != NULL) {
                printf ("%s\n", ent->d_name);
                File *newFile = new File(ent->d_name, Constants::Configuration::directoryPath);
                files.push_back(newFile);
            }
            closedir (dir);
        } else {
            /* could not open directory */
            perror ("");
//        return EXIT_FAILURE;
        }
    }
}

File* FileManager::getFile(string name, unsigned long size) {
    for (auto file : files) {
        if (file->getName() == name && file->getSize() == size) {
            return file;
        }
    }
    return nullptr;
}

void FileManager::lockFile(string name, unsigned long size) {
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

void FileManager::unlockFile(string name, unsigned long size) {
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

bool FileManager::isFileLocked(string name, unsigned long size) {
    for (auto file : files) {
        FileInfo fileInfo = file->getFileInfo();
        if (fileInfo.name == name && fileInfo.size == size) {
            return file->isLocked();
        }
    }
    throw FileNotFoundException();
}

bool FileManager::isOwner(string name, unsigned long size) {
    for (auto file : files) {
        FileInfo fileInfo = file->getFileInfo();
        if (fileInfo.name == name && fileInfo.size == size) {
            return file->isOwner();
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

bool FileManager::removeFile(string name, unsigned long size)
{
    bool success = false;
    unsigned int index = 0;
    for (vector<File*>::const_iterator iter = files.begin(); iter != files.end();++index, iter++) {
        FileInfo fileInfo = (*iter)->getFileInfo();
        if (fileInfo.name == name && fileInfo.size == size) {
//            files.erase(iter);
            success = true;
            break;
        }
    }
    if (success) files.erase(files.begin()+index);
    return success;
}

FileInfo* FileManager::removeHostFile(string hostname)
{
    for (vector<File*>::const_iterator iter = files.begin(); iter != files.end(); iter++) {
        FileInfo fileInfo = (*iter)->getFileInfo();
        if (fileInfo.hostAddress == hostname) {
            FileInfo* toRet = new FileInfo(fileInfo.name,fileInfo.size,false,false);
            files.erase(iter);
            return toRet;
        }
    }
    return nullptr;
}