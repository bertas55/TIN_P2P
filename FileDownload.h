//
// Created by hubert on 08.01.17.
//

#ifndef TIN_P2P_FILEDOWNLOAD_H
#define TIN_P2P_FILEDOWNLOAD_H

#include <queue>
#include "File.h"

class FileDownload : public File {

public:

    FileDownload(string name, unsigned int size);

    unsigned int getPartToDownload();

    void addPartToDownload(unsigned int);

private:
    queue<unsigned int> partsLeft;
};


#endif //TIN_P2P_FILEDOWNLOAD_H
