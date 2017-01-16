//
// Created by lukasz on 07.01.17.
//

#ifndef TIN_P2P_FILEINFOCONTAINER_H
#define TIN_P2P_FILEINFOCONTAINER_H
#include <vector>
#include <mutex>
#include "File.h"
/**
 * Kontener przechowujacy informacje o plikach dostepnych w sieci
 */
class FileInfoContainer {

public:
    FileInfoContainer();

    void put(struct FileInfo);
    std::vector<struct FileInfo> getAllHostsContains(struct FileInfo);
    bool remove (struct FileInfo);
    bool remove (string name, unsigned long size, string hostName);
    struct FileInfo* remove (string hostName);
    struct FileInfo* has(string fileName, unsigned long fileSize);

private:
    std::vector<struct FileInfo> fileInfoVector;
    std::mutex guard;
};


#endif //TIN_P2P_FILEINFOCONTAINER_H
