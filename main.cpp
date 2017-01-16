//
// Created by Hubert Kuczyński on 01.01.17.
//

#include <iostream>
#include<thread>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <net/if.h>
#include "ServerInterface.h"
#include "FileManager.h"
#include "JsonParser.h"

using namespace std;

void userInterface()
{
    ServerInterface serverInterface;
    serverInterface.consoleInterface();
    cout << "Finished!\n";

}
int main(void)
{
    userInterface();
    return 0;
}

