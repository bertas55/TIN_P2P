//
// Created by lukasz on 07.01.17.
//

#include "FileInfoContainer.h"

FileInfoContainer::FileInfoContainer()
{

}

void FileInfoContainer::put(struct FileInfo fileInfo)
{
    std::lock_guard<std::mutex> lock(guard);
    fileInfoVector.push_back(fileInfo);
}
std::vector<struct FileInfo> FileInfoContainer::getAllHostsContains(struct FileInfo file)
{
    std::vector<struct FileInfo> vectorToReturn;

    for (int i = 0 ; i < fileInfoVector.size() ; ++i)
    {
        if (file.size== fileInfoVector[i].size
            && file.name == fileInfoVector[i].name) vectorToReturn.push_back(fileInfoVector[i]);
    }

    return vectorToReturn;
}

void FileInfoContainer::remove(struct FileInfo file) {
    for (vector<FileInfo>::const_iterator fileInfo = fileInfoVector.begin(); fileInfo != fileInfoVector.end(); fileInfo++) {
        if (file.size== fileInfo->size
            && file.name == fileInfo->name
            && file.hostAddress == fileInfo->hostAddress) {
            fileInfoVector.erase(fileInfo);
        }
    }
}

struct FileInfo* FileInfoContainer::has(string fileName, unsigned long fileSize) {
    for (unsigned int i =0 ; i < fileInfoVector.size() ; ++i)
    {
        if (fileInfoVector[i].size == fileSize
            && fileInfoVector[i].name == fileName) return &fileInfoVector[i];
    }
    return nullptr;

}