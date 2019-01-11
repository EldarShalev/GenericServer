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
    SearcherResult search(Searchable<T> searchable) {
        SearcherResult res = {-1, -1};
        // These arrays are used to get row and column
        // numbers of 4 neighbours of a given cell
        int rowNum[] = {-1, 0, 0, 1};
        int colNum[] = {0, -1, 1, 0};

        //we currently support only n*n sized matrix
        map<T, State<T>> data = searchable.getAllPossibleStates();
        int m = data.size();
        int n = m;
        State<T> start = searchable.getInitialState();
        State<T> dest = searchable.getGoalState();

        // Mark all the vertices as not visited
        map<T, bool> visited;
        visited[start] = true;

        // Create a queue for BFS
        queue<State<T>> q;

        // Distance of source cell is 0
        q.push(data[start]);  // Enqueue source cell

        // Do a BFS starting from source cell
        while (!q.empty())
        {
            State<T> curr = q.front();

            // If we have reached the destination cell,
            // we are done
            if (curr.getState() == dest.getState()) {
                return Utils::getSearcherResult(curr);
            }

            // Otherwise dequeue the front cell in the queue
            // and enqueue its adjacent cells
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                T next = curr.getState().calcNext({rowNum[i], colNum[i]});

                // if adjacent cell is valid, has path and
                // not visited yet, enqueue it.
                if (!visited[next] && data[next].getCost() > -1)
                {
                    // mark cell as visited and enqueue it
                    visited[next] = true;
                    data[next].setPrevious(curr);
                    q.push(data[next]);
                }
            }
        }

        // Return -1 if destination cannot be reached
        return res;
    }
};


#endif //SERVER_BFS_H
