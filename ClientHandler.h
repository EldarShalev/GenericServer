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
    // TODO - change this part after better understanding of 'instream/outstream'..
//    virtual void handleClient1(istream input, ostream output) = 0;

    virtual void handleClient(string buffer) = 0;
};


#endif //SERVER_CLIENTHANDLER_H
