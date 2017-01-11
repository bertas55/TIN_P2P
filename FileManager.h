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

    File* getFile(string name, unsigned long size);

    void lockFile(string name, unsigned long size);

    void unlockFile(string name, unsigned long size);

    bool isFileLocked(string name, unsigned long size);

    bool isOwner(string name, unsigned long size);

    File* addFile(string name, string path);

    void addFile(File* file);



    bool removeFile(string name, unsigned long size);

    FileInfo* removeHostFile(string hostname);

    vector<FileInfo> getFilesList();


private:
    vector<File*> files;

    void loadFiles();

    std::ifstream::pos_type getFileSize(const char* filename);
};


#endif //TIN_P2P_FILEMANAGER_H
