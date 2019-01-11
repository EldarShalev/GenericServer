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

using namespace std;

class Utils {

public:
    static vector<string> splitToVectorByDelimiter(string str, char delimiter);

    static string parseString(string toReverse, bool reverse);

    template<typename T>
    static SearcherResult getSearcherResult(State<T> state) {
        State<T> ptr = state.getPrevious();
        int dist = 0;
        int cost = state.getCost();
        while (ptr != NULL) {
            ++dist;
            cost += ptr.getCost();
            ptr = ptr.getPrevious();
        }

        SearcherResult res;
        res.distance = dist;
        res.cost = cost;
        return res;
    }
};


#endif //SERVER_UTILS_H
