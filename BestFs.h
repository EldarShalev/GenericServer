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
    SearcherResult search(Searchable<T> searchable) {
        // These arrays are used to get row and column
        // numbers of 4 neighbours of a given cell
        int rowNum[] = {-1, 0, 0, 1};
        int colNum[] = {0, -1, 1, 0};

        map<T, State<T>> data = searchable.getAllPossibleStates();
        State<T> initial = searchable.getInitialState();
        State<T> goal = searchable.getGoalState();

        // Create a queue
        UpdatablePriorityQueue<double, State<T>> open;
        set<State<T>> closed;
        // Enqueue initial state
        open.push(data[initial].getCost(), data[initial]);

        while (!open.empty()) {
            State<T> curr = open.front();
            open.pop();
            closed.insert(curr);

            // If we have reached the goal state, we are done
            if (curr.getState() == goal.getState()) {
                return Utils::getSearcherResult(curr);
            }

            for (int i = 0; i < 4; i++) {
                T next = curr.getState().calcNext({rowNum[i], colNum[i]});
                State<T> nextState = data[next];
                typename priority_queue<State<T>>::iterator itq = open.find(nextState);
                typename set<State<T>>::iterator its = closed.find(nextState);
                if(itq == open.end() && its == closed.end()) {
                    nextState.setPrevious(curr);
                    SearcherResult nextRes = Utils::getSearcherResult(nextState);
                    open.push(nextRes.cost, nextState);
                }
                else {
                    State<T> whatIfState(nextState.getState(), nextState.getCost());
                    whatIfState.setPrevious(curr);
                    SearcherResult nextRes = Utils::getSearcherResult(nextState);
                    SearcherResult whatIfRes = Utils::getSearcherResult(whatIfState);
                    // if the new path is better then existing (costs less)
                    if(whatIfRes.cost < nextRes.cost) {
                        nextState.setPrevious(curr);
                        if (itq != open.end()) {
                            open.update(whatIfRes.cost, nextState);
                        } else {
                            open.push_back(whatIfRes.cost, nextState);
                        }
                    }
                }
            }
        }
        return {-1, -1};
    }
};


#endif //SERVER_BESTFS_H
