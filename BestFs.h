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
public:
    SearcherResult search(Searchable<T> *searchable) {
        State<T> *initial = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();

        // Create a priority queue
        UpdatablePriorityQueue<State<T>, int> open;
        map<T, bool> visited;
        visited[initial->getState()] = true;
        // Enqueue initial state
        open.push(initial, initial->getCost());

        while (!open.empty()) {
            PriorityQueueNode<State<T>, int> curr = open.pop_value();
            visited[curr.key.getState()] = true;

            // If we have reached the goal state, we are done
            if (curr.key.getState() == goal->getState()) {
                return Utils::getSearcherResult(curr.key);
            }

            vector<State<T>*> nextStates = searchable->getAllPossibleStates(curr.key);

            for (int i = 0; i < nextStates.size(); i++) {
                State<T> *nextState = nextStates[i];
                T next = nextState->getState();
                if (visited[next]) {
                    //we already calculated the best for this one
                    continue;
                }

                State<T> whatIfState(nextState->getState(), nextState->getCost());
                whatIfState.setPrevious(&curr.key);
                SearcherResult whatIfRes = Utils::getSearcherResult(whatIfState);

                // if the new path is better then existing (costs less)
                if (whatIfRes.cost < curr.priority) {
                    nextState->setPrevious(&curr.key);
                    open.set(nextState, whatIfRes.cost);
                }
            }
        }
        //did not reach goal
        return {-1, -1};
    }
};


#endif //SERVER_BESTFS_H
