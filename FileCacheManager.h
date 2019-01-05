//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_FILECACHEMANAGER_H
#define SERVER_FILECACHEMANAGER_H

#include <string>
#include "CacheManager.h"
using namespace std;

class FileCacheManager : public CacheManager<std::string,std::string> {

private:
    // Consider for o(1) using : std::unordered_map
public:

    virtual bool isSolutionSavedInCache(string solution , string problem);

    virtual string getSolutionFromCach(string problem);

    virtual void saveSolutionForProblem(string solution, string problem);
};


#endif //SERVER_FILECACHEMANAGER_H
