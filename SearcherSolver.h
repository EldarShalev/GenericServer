//
// Created by Eldar on 1/12/2019.
//

#ifndef SERVER_SEARCHERSOLVER_H
#define SERVER_SEARCHERSOLVER_H


#include "Solver.h"
#include "SearcherResult.h"
#include "Searchable.h"
#include "Searcher.h"

template<typename T>
class SearcherSolver : public Solver<SearcherResult, Searchable<T>> {
private:
    Searcher<T> searcher;
public:
    SearcherSolver(const Searcher<T> &searcher) : searcher(searcher) {}
    SearcherResult solve(Searchable<T> searchable);
};


#endif //SERVER_SEARCHERSOLVER_H
