//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_MYTESTCLIENTHANDLER_H
#define SERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include <string>

class MyTestClientHandler : public ClientHandler {

private:
    Solver<std::string,std::string> *solver;
    CacheManager<std::string,std::string> *cacheManager;
public:
    void handleClient(istream input, ostream output);


};


#endif //SERVER_MYTESTCLIENTHANDLER_H
