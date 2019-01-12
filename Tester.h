//
// Created by Eldar on 12-Jan-19.
//

#ifndef SERVER_TESTER_H
#define SERVER_TESTER_H


#include "Searcher.h"
#include "Dfs.h"
#include "Searchable.h"
#include "SearcherResult.h"

template<typename T>
class Tester {
public:
    void testSearcher(Searcher<T> *searcher, Searchable<T> *searchable) {
//        Dfs<T> *dfs=new Dfs<T>();
        SearcherResult sol1=searcher->search(searchable);
//        SearcherResult solution = searcher->search(searchable);
    }

};


#endif //SERVER_TESTER_H
