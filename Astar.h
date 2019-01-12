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
    void calcLogic(State<T> *next, State<T> *curr, set<State<T> *> &openList) {
        if (next->getPrevious() == NULL) {
            next->setPrevious(curr);
            openList.insert(next);
        } else {
            SearcherResult infoPrev = Utils::getSearcherResult(*next->getPrevious());
            State<Point> whatIf(next->getState(), next->getCost());
            whatIf.setPrevious(curr);
            SearcherResult infoWhatIf = Utils::getSearcherResult(whatIf);
            int fPrev = infoPrev.distance + infoPrev.cost;
            int fWhatIf = infoWhatIf.distance + infoWhatIf.cost;

            if (fWhatIf <= fPrev) {
                next->setPrevious(curr);
                openList.insert(next);
            }
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
        set<State<T> *> openList;

        openList.insert(initial);

        while (!openList.empty()) {
            State<T> *curr = *openList.begin();

            // Remove this vertex from the open list
            openList.erase(openList.begin());

            // Add this vertex to the closed list
            visited[curr->getState()] = true;
            vector<State<T> *> nextStates = searchable->getAllPossibleStates(curr);

            for (int i = 0; i < nextStates.size(); i++) {
                State<T> *next = nextStates[i];

                if (!visited[next->getState()]) {
                    calcLogic(next, curr, openList);
                }
            }
        }

        if (goal->getPrevious() == NULL) {
            return {-1, -1};
        }
        return Utils::getSearcherResult(*goal);
    }
};

#endif //SERVER_ASTAR_H
