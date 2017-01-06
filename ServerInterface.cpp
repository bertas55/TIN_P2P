//
// Created by lukasz on 06.01.17.
//

#include "ServerInterface.h"


//enum UserAction{ RefreshList, DownloadFile, DisableFile, EnableFile, RemoveFile, Exit };
ServerInterface::ServerInterface()
{

    server = new ServerThread();


}
ServerInterface::~ServerInterface()
{

    delete server;
}

bool ServerInterface::loadConfig(string path) {

    return true;
}
void ServerInterface::userAction(UserAction action)
{
    if (action == UserAction::RefreshList || action == UserAction::DownloadFile)
    {
        putServerAction(action);
    } else if (action == UserAction::Exit)
    {

    }
    else {
        fileManagerAction(action);
    }
}
void ServerInterface::fileManagerAction(UserAction action)
{
    switch (action)
    {
        case (UserAction::DisableFile):
        {

            break;
        }
        case (UserAction::EnableFile):
        {

            break;
        }
        case (UserAction::RemoveFile):
        {

            break;
        }
        case (UserAction::Exit):
        {

            break;
        }
    }


}
void ServerInterface::putServerAction(UserAction action)
{
    switch (action)
    {
        case (UserAction::RefreshList):
        {

            break;
        }
        case (UserAction::DownloadFile):
        {

            break;
        }
        case (UserAction::Exit):
        {

            break;
        }
    }
}