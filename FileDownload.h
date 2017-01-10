//
// Created by hubert on 08.01.17.
//

#ifndef TIN_P2P_FILEDOWNLOAD_H
#define TIN_P2P_FILEDOWNLOAD_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include "File.h"

class FileDownload : public File {

public:

    FileDownload(string name, string path, unsigned int size, unsigned int seeds);

    long getPartToDownload();

    void addPartToDownload(long);

    unsigned long partsLeftCount();

    void seedDisconected();

    void waitUntilFinished();


private:
    queue<long> partsLeft;

    unsigned int seedsConnected;

    condition_variable finished;
};


#endif //TIN_P2P_FILEDOWNLOAD_H
