#include <iostream>
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"

int main(int argc, char *argv[]) {
    Solver<string, string> *solver = new StringReverser();
    CacheManager<string, string> *cacheManager = new FileCacheManager();
    MySerialServer *mySerialServer = new MySerialServer();
    ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
    mySerialServer->open(stoi(argv[1]), clientHandler);

    return 0;
}