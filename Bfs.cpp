//
// Created by Eldar on 1/12/2019.
//

#include "Bfs.h"

template<typename T>
SearcherResult Bfs<T>::search(Searchable<T> searchable) {
    map<T, State<T>> data = searchable.getAllPossibleStates();
    State<T> initial = searchable.getInitialState();
    State<T> goal = searchable.getGoalState();

    // Mark all the vertices as not visited
    map<T, bool> visited;
    visited[initial] = true;

    // Create a queue
    queue<State<T>> open;
    // Enqueue initial state
    open.push(data[initial]);

    // Do a BFS starting from initial state
    while (!open.empty()) {
        State<T> curr = open.front();

        // If we have reached the goal state, we are done
        if (curr.getState() == goal.getState()) {
            return Utils::getSearcherResult(curr);
        }

        // Otherwise dequeue the state in the queue and enqueue its adjacent states
        open.pop();

        vector<State<T>> nextStates = searchable.getAllPossibleStates(curr);

        for (int i = 0; i < nextStates.size(); i++) {
            T next = nextStates[i].getState();

            // if adjacent state is valid, has path and not visited yet, enqueue it.
            if (!visited[next] && data[next].getCost() > -1) {
                // mark state as visited and enqueue it
                visited[next] = true;
                data[next].setPrevious(curr);
                open.push(data[next]);
            }
        }
    }

    // Return -1 if destination cannot be reached
    return {-1, -1};
}