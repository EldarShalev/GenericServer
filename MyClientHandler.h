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
#include "Astar.h"
#include <numeric>

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

    string handleClient(vector<string> vic) {
        // Parsing vector to matrix
        int sizeOfMatrix = atoi(vic.at(0).c_str());
        string point_start = vic.at(1);
        string point_end = vic.at(2);
        Point start = Utils::getPointFromString(point_start);
        Point end = Utils::getPointFromString(point_end);
        vector<string> vic2(vic.begin() + 3, vic.end());
        vector<vector<int>> intVector = Utils::vecStringToInt(vic2, sizeOfMatrix);
        Searchable<Point> *searchable = new SearchableMatrix(sizeOfMatrix, start, end, intVector);
        string matrix_problem, solution;
        matrix_problem = accumulate(vic.begin(), vic.end(), matrix_problem);
        if (this->cacheManager->isSolutionSavedInCache(matrix_problem)) {
            solution = this->cacheManager->getSolutionFromCache(matrix_problem);
        } else {
            // We run each algorithm on the matrix and save the solution
            Searcher<Point> *searcher1 = new Bfs<Point>();
            Searcher<Point> *searcher2 = new Dfs<Point>();
            Searcher<Point> *searcher3 = new BestFs<Point>();
            Searcher<Point> *searcher4 = new Astar<Point>();
            Tester<Point> *tester;

//            SearcherResult searcherResult1 = tester->testSearcher(searcher1, searchable);
//            SearcherResult searcherResult2 = tester->testSearcher(searcher2, searchable);
            SearcherResult searcherResult3 = tester->testSearcher(searcher3, searchable);
//            SearcherResult searcherResult4 = tester->testSearcher(searcher4, searchable);
            solution = searcherResult3.path;
            this->cacheManager->saveSolutionForProblem(matrix_problem, solution);
            // Delete allocated memory
            delete searcher1;
            delete searcher2;
            delete searcher3;
            delete searcher4;
        }
        // Delete allocated memory
        delete searchable;
        return solution;

    }


};


#endif //SERVER_MYCLIENTHANDLER_H
