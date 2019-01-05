//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_MYSERIALSERVER_H
#define SERVER_MYSERIALSERVER_H

#include "Server.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <zconf.h>
#include <sstream>

using namespace server_side;
using namespace std;

class MySerialServer : public Server {
private:
    static void *connectionHandler(void *context);
public:
    MySerialServer(){}

    void open(int port, ClientHandler *ch);

    void stop();

    bool isOpen();
};


#endif //SERVER_MYSERIALSERVER_H
