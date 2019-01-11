//
// Created by Eldar on 1/9/2019.
//

#ifndef SERVER_SEARCHABLE_H
#define SERVER_SEARCHABLE_H

#include <map>
#include "State.h"
#include "Point.h"

using namespace std;

template<typename T>
class Searchable {
protected:
    State<T> initialState;
    State<T> goalState;
    map<T, State<T>> allStates;

public:
    Searchable(T initial, T goal, map<T, State<T>> all) {
        initialState = initial;
        goalState = goal;
        allStates = all;
    }

    virtual State<T> getInitialState() { return initialState; }

    virtual State<T> getGoalState() { return goalState; }

    virtual map<T, State<T>> getAllPossibleStates() { return allStates; }

};


#endif //SERVER_SEARCHABLE_H
