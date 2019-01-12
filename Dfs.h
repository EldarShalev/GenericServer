//
// Created by Eldar on 1/9/2019.
//

#ifndef SERVER_DFS_H
#define SERVER_DFS_H

#include <cstring>
#include "Utils.h"
#include "Searcher.h"

template<typename T>
class Dfs : public Searcher<T> {
private:
    State<T> DFS(map<T, State<T>> data, State<T> initial, T dest, map<T, bool> visited);
};


#endif //SERVER_DFS_H
