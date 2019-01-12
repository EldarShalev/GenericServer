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
    State<T> DFS(map<T, State<T>> data, State<T> initial, T dest, map<T, bool> visited) {
        visited[initial] = true;

        if(initial == NULL) {
            //dead end
            return NULL;
        }

        // If we have reached the destination,we are done
        if (initial.getState() == dest) {
            return initial;
        }

        for(typename map<T, State<T>>::iterator it = data.find(initial); it != data.end(); ++it) {
            if(!visited[it->first] && it->second.getCost() > -1) {
                State<T> state = DFS(data, it->second, dest, visited);
                state.setPrevious(initial);
                return state;
            }
        }
        return NULL;
    }
public:
    SearcherResult search(Searchable<T> searchable) {
        map<T, State<T>> data = searchable.getAllPossibleStates();
        T initial = searchable.getInitialState();

        // Mark all the vertices as not visited
        map<T, bool> visited;

        State<T> state = DFS(data, data[initial], searchable.getGoalState().getState(), visited);
        return Utils::getSearcherResult(state);
    }
};


#endif //SERVER_DFS_H
