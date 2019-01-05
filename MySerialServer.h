//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_MYSERIALSERVER_H
#define SERVER_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;
using namespace std;

class MySerialServer : public Server {
private:
    int port;
    ClientHandler *clientHandler;
public:
    MySerialServer(int port1, ClientHandler *ch) : port(port1), clientHandler(ch) {}

    void open(int port);

    void stop();

    bool isOpen();
};


#endif //SERVER_MYSERIALSERVER_H
