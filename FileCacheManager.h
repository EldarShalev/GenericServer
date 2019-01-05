//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_FILECACHEMANAGER_H
#define SERVER_FILECACHEMANAGER_H

#include <string>
#include "CacheManager.h"
#include "unordered_map"
#include <iostream>
#include <fstream>
#include "Utils.h"

const char fileDelimiter = ',';

using namespace std;

class FileCacheManager : public CacheManager<std::string, std::string> {

private:
    unordered_map<string, string> problemToSolutions;
public:

    FileCacheManager();

    bool isSolutionSavedInCache(string problem);

    string getSolutionFromCache(string problem);

    void saveSolutionForProblem(string problem, string solution);

    void saveAlsoToFile(string problem, string solution);

    void loadFileToMap();
};


#endif //SERVER_FILECACHEMANAGER_H
