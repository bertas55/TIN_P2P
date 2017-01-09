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
    FileAppeared,        // Informacja o pojawieniu sie pliku w sieci               Log(FileAppeared,NazwaPliku,HostName,RozmiarPliku);
    FileRemoved,         // Informacja o usunieciu pliku                            Log(FileRemoved,NazwaPliku,"",RozmiarPliku);
    /*Inny host moze zazadac by usunac plik, ktorego jest wlascicielem.
     * W tym przypadku musimy usunac plik z posiadanych*/
    FileBlocked,         // Informacja o zablkowaniu pliku                          Log(FileBlocked,NazwaPliku,HostName,RozmiarPliku);
    FileUnblocked,       // Informacja o odblokowaniu pliku                         Log(FileUnblocked,NazwaPliku,HostName,RozmiarPliku);
    ServerError          // Informacja o bledzie w dzialaniu serwera                Log(ServerError, Komunikat, "", 0 lub 1);
    /*0 - nie wymaga zamkniecia aplikacji,
     * 1 wymaga natychmiastowego zamkniecia aplikacji
     * */
};
/**
 * Struktura do opisu komunikatu przesylanaego do GUI
 */
typedef struct Log
{
    LogType logType;
    std::string data[2];
    unsigned long argument;
    Log(LogType lt,std::string name,std::string host, unsigned long size) :
            logType(lt), argument(size)
    {
        data[0]= name;
        data[1]= host;
    }
}Logs;
/**
 * Kontener do przechowywania logow
 */
class LogContainer {
public:
    LogContainer();

    void put(Log);
    struct Log get();
    unsigned long size();

private:
    std::queue<struct Log> logContainer;
    std::mutex guard;
};


#endif //TIN_P2P_LOGCONTAINER_H
