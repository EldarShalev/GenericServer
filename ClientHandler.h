//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H

#include <iostream>
#include <ostream>
#include <string>

using namespace std;

class ClientHandler {

public:

    virtual void handleClient(string buffer) = 0;
};


#endif //SERVER_CLIENTHANDLER_H
