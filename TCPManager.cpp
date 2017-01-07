//
// Created by lukasz on 07.01.17.
//

#include "TCPManager.h"

TCPManager::TCPManager(FileManager* fm, FileInfoContainer*fic) :fileManager(fm), fileInfoContainer(fic)
{

}

void sendFile(File*, char* recieverAddress, unsigned short recieverPort) /*Wysylanie pliku do zadanego hosta*/
{
    /**
     * Rozpoczyna polaczenie z zadanym portem. Do tego wykorzystywana jest klasa Connection
     */
}
void recieveFile(struct FileInfo*) /*Pobieranie pliku*/
{
    /**
     * Sprawdza liste fileInfoContainer, pobiera z nich adresy zrodel ktore plik posiadaja.
     * Z podanych adresow nawiazuje polaczenie. To powinno robic sie w oddielnym watku.
     * Zarzada ktora czesc, od ktorego hosta pobrac.
     */
}