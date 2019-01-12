//
// Created by Eldar on 1/9/2019.
//

#ifndef SERVER_BFS_H
#define SERVER_BFS_H

#include <list>
#include <iostream>
#include <queue>
#include <cstring>
#include "Utils.h"
#include "State.h"

#include "Searcher.h"

template<typename T>
class Bfs : public Searcher<T> {
public:
    SearcherResult search(Searchable<T> searchable);
};


#endif //SERVER_BFS_H
