//
// Created by Eldar on 1/12/2019.
//

#include "SearcherSolver.h"

template<typename T>
SearcherResult SearcherSolver<T>::solve(Searchable<T> searchable) {
    return searcher.search(searchable);
}