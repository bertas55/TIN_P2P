//
// Created by lukasz on 11.01.17.
//

#ifndef TIN_P2P_DOWNLOADHANDLER_H
#define TIN_P2P_DOWNLOADHANDLER_H


#include <thread>
#include <vector>
#include "File.h"
#include "FileDownload.h"
#include "LogContainer.h"
#include "FileManager.h"

/**
 * Klasa reprezentujaca watek sciagajacy plik.
 */
class DownloadHandler {
public:
    DownloadHandler(std::vector<FileInfo> h,FileDownload* file,FileManager* fm,LogContainer* lc, bool* exit);
    ~DownloadHandler();


private:
    std::thread threadId;
    FileManager* fileManager;
    LogContainer* logContainer;
    std::vector<FileInfo> hosts;
    bool* exitFlag;
    void startDownload(FileDownload* file);

};


#endif //TIN_P2P_DOWNLOADHANDLER_H
