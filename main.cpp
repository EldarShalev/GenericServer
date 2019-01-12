#include <iostream>
#include "FileCacheManager.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "SearchableMatrix.h"
#include "Point.h"
#include "Bfs.h"
#include "Dfs.h"
#include "Astar.h"
#include "BestFs.h"
#include "Tester.h"

int main(int argc, char *argv[]) {

    int counter = 0;
    int numOfMatrices, sizeOfMatix;
    string point_start, point_end;
    vector<string> vector1;
    cin >> numOfMatrices;
    while (counter < numOfMatrices) {
        cin >> sizeOfMatix;
        cin >> point_start;
        cin >> point_end;
        string line;
        int index = 0;
        while (getline(cin, line)) {
            if (line == "end") {
                break;
            }
            if (line == "") {
                continue;
            }
            vector1.push_back(line);
            index++;
        }
        Point start = Utils::getPointFromString(point_start);
        Point end = Utils::getPointFromString(point_end);
        vector<vector<int>> intVector = Utils::vecStringToInt(vector1, sizeOfMatix);
        Searchable<Point> *searchable = new SearchableMatrix(sizeOfMatix, start, end, intVector);
        Bfs<Point> *bfs = new Bfs<Point>();
        Searcher<Point> *searcher = bfs;
        Tester<Point> *tester;
        tester->testSearcher(searcher, searchable);
        counter++;
    }
//    Solver<string, string> *solver = new StringReverser();
//    CacheManager<string, string> *cacheManager = new FileCacheManager();
//    MySerialServer *mySerialServer = new MySerialServer();
//    ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
//    mySerialServer->open(stoi(argv[1]), clientHandler);

    return 0;
}