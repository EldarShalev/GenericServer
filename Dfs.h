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
    State<T> DFS(map<T, State<T>> data, State<T> start, T dest, map<T, bool> visited) {
        visited[start] = true;

        // If we have reached the destination cell,
        // we are done
        if (start.getState() == dest) {
            return start;
        }


        for(map<T, State<T>>::iterator it = data.find(start); it != data.end(); ++it) {
            if(!visited[it->first]) {
                State<T> state = DFS(data, it->second, dest, visited);
                state.setPrevious(start);
                return state;
            }
        }
    }
public:
    SearcherResult search(Searchable<T> searchable) {
        map<T, State<T>> data = searchable.getAllPossibleStates();
        T start = searchable.getInitialState();

        // Mark all the vertices as not visited
        map<T, bool> visited;

        State<T> state = DFS(data, data[start], searchable.getGoalState(), visited);
        return Utils::getSearcherResult(state);
    }
};


#endif //SERVER_DFS_H
