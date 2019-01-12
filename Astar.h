//
// Created by Eldar on 1/9/2019.
//

#ifndef SERVER_ASTAR_H
#define SERVER_ASTAR_H

#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
#include <set>
#include "Utils.h"

#include "Searcher.h"

template<typename T>
class Astar : public Searcher<T> {
private:
    void calcLogic(State<T> curr, set<State<T>> &openList);
public:
    SearcherResult search(Searchable<T> searchable);
};

#endif //SERVER_ASTAR_H
