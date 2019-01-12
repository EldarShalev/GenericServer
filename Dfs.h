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
    State<T> *DFS(Searchable<T> *searchable, State<T> *initial, T dest, map<T, bool> visited) {
        visited[initial->getState()] = true;

        if(initial == NULL || initial->getCost() == -1) {
            //dead end
            return NULL;
        }

        // If we have reached the destination,we are done
        if (initial->getState() == dest) {
            return initial;
        }

        vector<State<T>> nextStates = searchable->getAllPossibleStates(*initial);

        for(int i = 0; i < nextStates.size(); ++i) {
            State<T> next = nextStates[i];
            if(!visited[next.getState()] && next.getCost() > -1) {
                State<T> *state = DFS(searchable, &next, dest, visited);
                if(state != NULL) {
                    //ignore dead ends
                    state->setPrevious(initial);
                    return state;
                }
            }
        }
        return NULL;
    }

public:
    SearcherResult search(Searchable<T> *searchable) {
        State<T> initial = searchable->getInitialState();

        // Mark all the vertices as not visited
        map<T, bool> visited;

        State<T> *state = DFS(searchable, &initial, searchable->getGoalState().getState(), visited);
        return Utils::getSearcherResult(*state);
    }
};


#endif //SERVER_DFS_H
