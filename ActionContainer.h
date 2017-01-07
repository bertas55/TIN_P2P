//
// Created by lukasz on 07.01.17.
//

#ifndef TIN_P2P_ACTIONCONTAINER_H
#define TIN_P2P_ACTIONCONTAINER_H

#include <queue>
#include <mutex>
#include "File.h"

enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, Exit };
typedef struct Actions {
    UserAction action;
    File *file;
    int arg;
    Actions(UserAction u, File *f, int i): action(u),file(f),arg(i)
    {};

}Action;

class ActionContainer {
public:

    ActionContainer();

    Action get();

    void put(Action);

    int getSize();

private:
    queue<Action> actionQueue;
    mutex guard;
};


#endif //TIN_P2P_ACTIONCONTAINER_H
