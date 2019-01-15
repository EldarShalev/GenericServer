//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_SOLVER_H
#define SERVER_SOLVER_H

template<typename Solution, typename Problem>
class Solver {
public:
    virtual Solution solve(Problem *p) = 0;
};


#endif //SERVER_SOLVER_H
