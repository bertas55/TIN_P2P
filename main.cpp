//
// Created by Hubert Kuczyński on 01.01.17.
//

#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>

#include "JsonCreator.h"

#include<thread>
#include <iostream>

#define BUFLEN 512  //Max length of buffer
#define PORT 8888   //The port on which to listen for incoming data
#define SERVER "127.0.0.1"

using namespace std;

void die(char *s)
{
    perror(s);
    exit(1);
}

void listenForMessages() {
    struct sockaddr_in si_me, si_other;

    int s , recv_len;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];

    //create a UDP socket
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        die("socket");
    }

    // zero out the structure
    memset((char *) &si_me, 0, sizeof(si_me));

    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind socket to port
    if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
    {
        die("bind");
    }

    //keep listening for data
    while(true)
    {
        printf("Waiting for data...");
        fflush(stdout);

        //try to receive some data, this is a blocking call
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == -1)
        {
            die("recvfrom()");
        }

        //print details of the client/peer and the data received
        printf("Received packet from %s:%d\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port));
        printf("Data: %s\n" , buf);
    }
}

void sendMessage(char* message) {
    struct sockaddr_in si_other;
    int s, i;
    socklen_t slen = sizeof(si_other);
    char buf[BUFLEN];


    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        die("socket");
    }

    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);

    if (inet_aton(SERVER , &si_other.sin_addr) == 0)
    {
        fprintf(stderr, "inet_aton() failed\n");
        return;
    }



    //send the message
    if (sendto(s, message, strlen(message) , 0 , (struct sockaddr *) &si_other, slen)==-1)
    {
        die("sendto()");
    }
}

int main(void)
{
    std::thread t1(listenForMessages);

//    std::string msgJson = JsonCreator::requestFile("NazwaHosta", "NazwaPliku", 234, 345);

    t1.join();

    return 0;
}