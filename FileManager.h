//
// Created by hubert on 05.01.17.
//

#ifndef TIN_P2P_FILEMANAGER_H
#define TIN_P2P_FILEMANAGER_H

#include <vector>
#include <string>
#include "File.h"
using namespace std;

class FileManager {

public:

    FileManager();

    void lockFile(string name, unsigned int size);

    void unlockFile(string name, unsigned int size);

    bool isFileLocked(string name, unsigned int size);

    void removeFile(string name, unsigned int size);

    vector<FileInfo> getFilesList();


private:
    vector<File*> files;
};


#endif //TIN_P2P_FILEMANAGER_H
