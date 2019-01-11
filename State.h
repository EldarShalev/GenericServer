//
// Created by Eldar on 1/9/2019.
//

#ifndef SERVER_STATE_H
#define SERVER_STATE_H

template<typename T>
class State {
private:
    T state;
    double cost;
    State<T> *cameFrom = NULL;
public:
    State() {}

    State(T state) { setState(state); }

    State(T state, double cost) {
        setState(state);
        this->cost = cost;
    }

    void setState(T state) { this->state = state; }

    double getCost() { return cost; }

    State<T> *getPrevious() { return cameFrom; }

    void setPrevious(State<T> *state) { this->cameFrom = state; }

    T getState() { return state; }
};


#endif //SERVER_STATE_H
