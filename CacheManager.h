//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_CACHEMANAGER_H
#define SERVER_CACHEMANAGER_H


template<class Solution, class Problem>
class CacheManager {

public:

    virtual bool isSolutionSavedInCache(Solution s, Problem p) = 0;

    virtual Solution getSolutionFromCach(Problem problem) = 0;

    virtual void saveSolutionForProblem(Solution s, Problem p) = 0;
};


#endif //SERVER_CACHEMANAGER_H
