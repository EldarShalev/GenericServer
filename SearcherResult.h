//
// Created by Eldar on 1/11/2019.
//

#ifndef SERVER_SEARCHERRESULT_H
#define SERVER_SEARCHERRESULT_H

#include <string>

using namespace std;

class SearcherResult {
public:
    int distance;
    int cost;
    int numOfEvaluatedNodes;
    string path;
};

#endif //SERVER_SEARCHERRESULT_H
