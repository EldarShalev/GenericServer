//
// Created by Eldar on 03-Jan-19.
//

#ifndef SERVER_FILECACHEMANAGER_H
#define SERVER_FILECACHEMANAGER_H

#include <string>
#include <cstring>
#include "CacheManager.h"
#include <iostream>
#include <fstream>
#include "Utils.h"

const char fileDelimiter = '$';

using namespace std;

template<typename Problem, typename Solution>
class FileCacheManager : public virtual CacheManager<Problem, Solution> {

private:
    map<Problem, Solution> *problemToSolutions;
public:

    FileCacheManager() {
        problemToSolutions = new map<Problem, Solution>;
        loadFileToMap();
    }

    bool isSolutionSavedInCache(Problem problem) {
        return this->problemToSolutions->count(problem) > 0;
    }

    Solution getSolutionFromCache(Problem problem) { return this->problemToSolutions->at(problem); }

    void saveSolutionForProblem(Problem problem, Solution solution) {
        problemToSolutions->insert(make_pair(problem, solution));
    }

    void saveAllToFile() {
        ofstream myfile;
        myfile.open("Solutions.txt", ios::app | fstream::out);
        for (typename map<Problem, Solution>::iterator it = problemToSolutions->begin();
             it != problemToSolutions->end(); ++it) {
            myfile << it->first << fileDelimiter << it->second << "\n";
        }
        myfile.close();
    }

    void loadFileToMap() {
        ifstream myfile;
        string line;
        vector<string> parsing;
        myfile.open("Solutions.txt");
        while (getline(myfile, line)) {
            parsing = Utils::splitToVectorByDelimiter(line, fileDelimiter);
            problemToSolutions->insert(make_pair(parsing.at(0), parsing.at(1)));
        }
        myfile.close();

    }

    ~FileCacheManager() {
        saveAllToFile();
        delete problemToSolutions;
    }
};


#endif //SERVER_FILECACHEMANAGER_H
