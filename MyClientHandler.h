//
// Created by Eldar on 12-Jan-19.
//

#ifndef SERVER_MYCLIENTHANDLER_H
#define SERVER_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Utils.h"
#include <string>
#include "Searcher.h"
#include "SearchableMatrix.h"
#include "Dfs.h"
#include "BestFs.h"
#include "Bfs.h"
#include "Tester.h"


template<typename Solution, typename Problem>
class MyClientHandler : public ClientHandler {

private:
    Solver<Solution, Problem> *solver;
    CacheManager<string, string> *cacheManager;
public:
    MyClientHandler(Solver<Solution, Problem> *solver1, CacheManager<string, string> *cacheManager1) {
        this->solver = solver1;
        this->cacheManager = cacheManager1;
    }

    void handleClient(vector<string> vic) {

        // Parsing vector to matrix
        int sizeOfMatrix = atoi(vic.at(0).c_str());
        string point_start = vic.at(1);
        string point_end = vic.at(2);
        Point start = Utils::getPointFromString(point_start);
        Point end = Utils::getPointFromString(point_end);
        vector<string> vic2(vic.begin() + 3, vic.end() - 1);
        vector<vector<int>> intVector = Utils::vecStringToInt(vic2, sizeOfMatrix);
        Searchable<Point> *searchable = new SearchableMatrix(sizeOfMatrix, start, end, intVector);
        // TODO - check algorithm before choosing
        Dfs<Point> *dfs = new Dfs<Point>();
        Searcher<Point> *searcher = dfs;
        Tester<Point> *tester;
        tester->testSearcher(searcher, searchable);

    }


};


#endif //SERVER_MYCLIENTHANDLER_H
