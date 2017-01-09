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
    DownloadFileProgres, // Informacja o postepie pobierania:                       Log(DownloadFileProgresm, NazwaPobiernaegoPliku,"", RozmiarDocelowyPliku);
    DownloadFileError,   // Informacja o wystapieniu bledu podczas pobierania       Log(DownloadFileError, NazwaPobieranegoPliku, KomunikatObledzie, RozmiarDocelowyPliku);
    FileVeto,            // Informacja o zgloszeniu roszczenia do pliku:            Log(FileVeto, NazwaPliku,"", RozmiarPliku)
    /*Dzialanie Veto:
     * 1. Usuniecie pliku z widocznych dla uztykownika
     * 2. Wybranie nowego poprzez QDialog lub porzucenie dodawania*/
    FileDisappeared,     // Informacja o zniknieciu pliku z dostepnych sieciowo:    Log(FileDisappeared, NazwaPliku, HostName, RozmiarPliku);
    FileRemoved,         // Informacja o usunieciu pliku                            Log(FileRemoved,NazwaPliku,"",RozmiarPliku);
    FileBlocked,         // Informacja o zablkowaniu pliku                          Log(FileBlocked,NazwaPliku,HostName,RozmiarPliku);
    FileUnblocked,       // Informacja o odblokowaniu pliku                         Log(FileUnblocked,NazwaPliku,HostName,RozmiarPliku);
    FileAppeared,        // Informacja o pojawieniu sie pliku w sieci               Log(FileAppeared,NazwaPliku,HostName,RozmiarPliku);
    ServerError          // Informacja o bledzie w dzialaniu serwera                Log(ServerError, Komunikat, "", 0);
};
/**
 * Struktura do opisu komunikatu przesylanaego do GUI
 */
struct Log
{
    LogType logType;
    std::string data[2];
    int argument;
    Log(LogType lt,std::string name,std::string host, int arg) :
            logType(lt), argument(arg)
    {
        data[0]= name;
        data[1]= host;
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
