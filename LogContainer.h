//
// Created by lukasz on 09.01.17.
//

#ifndef TIN_P2P_LOGCONTAINER_H
#define TIN_P2P_LOGCONTAINER_H
#include <queue>
#include <mutex>
enum LogType {DownloadFileProgres, FileVeto};
struct Log
{
    LogType logType;
    std::string fileName;
    int argument;
    Log(LogType lt,std::string name, int arg) :
            logType(lt), fileName(name), argument(arg)
    {
    }
};

class LogContainer {
public:
    LogContainer();

    void put(struct Log);
    struct Log get();

private:
    std::queue<struct Log> logContainer;
    std::mutex guard;

};


#endif //TIN_P2P_LOGCONTAINER_H
