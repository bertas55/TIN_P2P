//
// Created by Lukasz Niedzwiedz on 07.01.17.
//

#ifndef TIN_P2P_ACTIONCONTAINER_H
#define TIN_P2P_ACTIONCONTAINER_H

#include <queue>
#include <mutex>
#include "File.h"

enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, AddFile, RevokeFile, Exit };
/**
 * Struktura przechowujaca dane o akcji.
 */
typedef struct Actions {
    UserAction action;
    string data[2];
    unsigned long arg;
    Actions(UserAction u, string fName, string fSize, unsigned long i): action(u),arg(i)
    {
        data[0]=fName;
        data[1]=fSize;
    };

}Action;
/**
 * Klasa reprezentujaca kontener na akcje.
 * Dostep jest kontrolowany poprzez mutex.
 */
class ActionContainer {
public:

    ActionContainer();

    Action get();

    void put(Action);


private:
    queue<Action> actionQueue;
    mutex guard;
};


#endif //TIN_P2P_ACTIONCONTAINER_H
