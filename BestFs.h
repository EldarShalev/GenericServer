//
// Created by Eldar on 1/9/2019.
//

#ifndef SERVER_BESTFS_H
#define SERVER_BESTFS_H

#include <queue>
#include "Searcher.h"
#include "Utils.h"
#include "UpdatablePriorityQueue.h"

using namespace better_priority_queue;

template<typename T>
class BestFs : public Searcher<T> {
};


#endif //SERVER_BESTFS_H
