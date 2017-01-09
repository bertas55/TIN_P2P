//
// Created by lukasz on 09.01.17.
//

#ifndef TIN_P2P_LOGCONTAINER_H
#define TIN_P2P_LOGCONTAINER_H
#include <queue>
#include <mutex>
/**
 * Typy logow
 */
enum LogType {
    DownloadFileProgres, //Informacja o postepie pobierania: Log(DownloadFileProgresm, NazwaPobiernaegoPliku, RozmiarDocelowyPliku
    FileVeto            // Informacja o zgloszeniu roszczenia do pliku: Log(FileVeto, NazwaPliku, RozmiarPliku)
};
/**
 * Struktura do opisu komunikatu przesylanaego do GUI
 */
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
/**
 * Kontener do przechowywania logow
 */
class LogContainer {
public:
    LogContainer();

    void put(struct Log);
    struct Log get();
    unsigned long size();

private:
    std::queue<struct Log> logContainer;
    std::mutex guard;

};


#endif //TIN_P2P_LOGCONTAINER_H
