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
    void calcLogic(State<T> curr, set<State<T>> &openList) {
        SearcherResult infoPrev = Utils::getSearcherResult(*curr.getPrevious());
        SearcherResult infoCurr = Utils::getSearcherResult(curr);
        int fPrev = infoPrev.distance + infoPrev.cost;
        int fCurr = infoCurr.distance + infoCurr.cost;

        // If it isn’t on the open list, add it to
        // the open list. Make the current square
        // the parent of this square. Record the
        // f, g, and h costs of the square cell
        //                OR
        // If it is on the open list already, check
        // to see if this path to that square is better,
        // using 'f' cost as the measure.
        if (fPrev >= INT_MAX || fPrev > fCurr) {
            openList.insert(curr);
        }
    }

public:
    SearcherResult search(Searchable<T> *searchable) {
        State<T> *initial = searchable->getInitialState();
        State<T> *goal = searchable->getGoalState();

        // If the destination cell is the same as source cell
        if (initial->getState() == goal->getState()) {
            return Utils::getSearcherResult(*initial);
        }

        map<T, bool> visited;
        set<State<T>*> openList;

        openList.insert(initial);

        while (!openList.empty()) {
            State<T> curr = *openList.begin();

            // Remove this vertex from the open list
            openList.erase(openList.begin());

            // Add this vertex to the closed list
            visited[curr.getState()] = true;
            vector<State<T>*> nextStates = searchable->getAllPossibleStates(curr);

            for (int i = 0; i < nextStates.size(); i++) {
                State<T> *next = nextStates[i];
                next->setPrevious(&curr);

                // If the destination cell is the same as the
                // current successor
                if (next->getState() == goal->getState()) {
                    return Utils::getSearcherResult(next);
                } else if (!visited[next->getState()]) {
                    calcLogic(next, openList);
                }
            }
        }

        // When the destination cell is not found and the open
        // list is empty, then we conclude that we failed to
        // reach the destination cell. This may happen when the
        // there is no way to destination cell (due to blockages)
        return {-1, -1};
    }
};

#endif //SERVER_ASTAR_H
