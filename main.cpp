#include <iostream>
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyClientHandler.h"
#include "StringReverser.h"
#include "SearchableMatrix.h"
#include "Point.h"
#include "Bfs.h"
#include "Dfs.h"
#include "Astar.h"
#include "BestFs.h"
#include "Tester.h"
#include "MyParallelServer.h"
#include "SearcherSolver.h"
#include <ctime>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    /**This code generates random matrix with num of nodes for testing alogrithm runtime  Also measuring time and print it */
//    clock_t start1234 = clock();
//    time_t begin1, end1;
//    time(&begin1);
//    int v1;
    /**Change here the number of nodes */
//    int sizeOfMatrix = 100;
//    vector<vector<int>> intVector;
//    vector<int> a;
//    for (int i = 0; i < sizeOfMatrix; i++) {
//        for (int j = 0; j < sizeOfMatrix; j++) {
//            a.push_back(v1);
//            v1 = rand() % 100;
//        }
//        intVector.push_back(a);
//        a.clear();
//    }
//    Point start(0, 0);
//    Point end(sizeOfMatrix - 1, sizeOfMatrix - 1);
//    Searchable<Point> *searchable = new SearchableMatrix(sizeOfMatrix, start, end, intVector);
//    Bfs<Point> *bfs = new Bfs<Point>();
//    Astar<Point> *astar = new Astar<Point>();
//    BestFs<Point> *bestFs = new BestFs<Point>();
//
//    Searcher<Point> *searcher1 = bfs;
//    Searcher<Point> *searcher2 = astar;
//    Searcher<Point> *searcher3 = bestFs;
//    Tester<Point> *tester;
    /**Change here the number of searcher for each algorithm */
//    tester->testSearcher(searcher1, searchable);
//
//    clock_t stop = clock();
//    double elapsed = (double) (stop - start1234) / CLOCKS_PER_SEC;
//    printf("\nTime elapsed: %.5f\n", elapsed);


    /** This code check the parallel server */

    /**  Just Example of dfs, we don't use it **/
    Bfs<Point> *dfs1 = new Bfs<Point>();
    /**  New Solver with Object Adapter "Searcher-solver" injected (for algorithm-to-matrix)  **/
    Solver<SearcherResult, Searchable<Point>> *solver = new SearcherSolver<Point>();
    /**  New Cache Manager with File manager injected  **/
    CacheManager<string, string> *cacheManager = new FileCacheManager<string, string>();
    /**  New Server with parallel server injected  **/
    Server *parallelServer = new MyParallelServer();
    /**  New Client with MyClientHandler injected  **/
    ClientHandler *clientHandler = new MyClientHandler<SearcherResult, Searchable<Point>>(solver, cacheManager);
    /**  Start the server on specific client handler**/
    parallelServer->open(stoi(argv[1]), clientHandler);


    return 0;
}