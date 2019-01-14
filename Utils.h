//
// Created by Eldar on 05-Jan-19.
//

#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "State.h"
#include "SearcherResult.h"
#include "Point.h"

using namespace std;

class Utils {

public:
    static vector<string> splitToVectorByDelimiter(string str, char delimiter);

    static string parseString(string toReverse, bool reverse);

    static Point getPointFromString(string str);

    static vector<vector<int>> vecStringToInt(vector<string> vector1, int matrixSize);

    static string splitStringByDelimiterAndIndex(string str, char delimiter, int index);

    template<typename T>
    static SearcherResult getSearcherResult(State<T> state) {
        vector<string> shortestPath;
        State<T> *ptr = state.getPrevious();
        shortestPath.push_back(state.getDetails());
        int dist = 0;
        int cost = state.getCost();
        while (ptr != NULL) {
            ++dist;
            cost += ptr->getCost();
            shortestPath.push_back(ptr->getDetails());
            ptr = ptr->getPrevious();
        }
        string parsedPath = parsingVectorOfPointsToPath(shortestPath);
        SearcherResult res;

        // TODO add also res.numOfEvaluatedNodes
        res.path = parsedPath;
        res.distance = dist;
        res.cost = cost;

        return res;
    }

    static string parsingVectorOfPointsToPath(vector<string> vic) {
        string calculation;
        int p1_x, p1_y;
        int p2_x, p2_y;
        // instead of reverse the vector, iteration starts from the end.
        for (vector<string>::iterator it = vic.end(); it > vic.begin() + 1;) {
            it--;
            p1_x = stoi(splitStringByDelimiterAndIndex(*it, ',', 1));
            p1_y = stoi(splitStringByDelimiterAndIndex(*it, ',', 2));
            p2_x = stoi(splitStringByDelimiterAndIndex(*(it - 1), ',', 1));
            p2_y = stoi(splitStringByDelimiterAndIndex(*(it - 1), ',', 2));
            if (p2_x > p1_x) {
                calculation += "DOWN,";
            } else if (p2_x < p1_x) {
                calculation += "UP,";
            } else if (p2_y > p1_y) {
                calculation += "RIGHT,";
            } else {
                calculation += "LEFT,";
            }
        }
        string finalResult = calculation.substr(0, calculation.size() - 1);
        return finalResult;

    }
};


#endif //SERVER_UTILS_H
