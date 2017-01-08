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
    for (int i = 0 ; i < fileInfoVector.size() ; ++i)
    {
        if (file.size== fileInfoVector[i].size
            && file.name == fileInfoVector[i].name
                && file.hostAddress == fileInfoVector[i].hostAddress)
        {
//            @TODO
        }
    }
}