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

const char fileDelimiter = '$';

using namespace std;

template<typename Problem, typename Solution>
class FileCacheManager : public virtual CacheManager<Problem, Solution> {

private:
    map<Problem, Solution> problemToSolutions;
public:

    FileCacheManager() { loadFileToMap(); }

    bool isSolutionSavedInCache(Problem problem) {
        return this->problemToSolutions.count(problem) > 0;
    }

    Solution getSolutionFromCache(Problem problem) { return this->problemToSolutions.at(problem); }

    void saveSolutionForProblem(Problem problem, Solution solution) {
        problemToSolutions.insert(make_pair(problem, solution));
        saveAlsoToFile(problem, solution);
    }

    void saveAlsoToFile(Problem problem, Solution solution) {
        ofstream myfile;
        myfile.open("Solutions.txt", ios::app | fstream::out);
        if (myfile.is_open()) {
            myfile << problem << fileDelimiter << solution << "\n";
            myfile.close();
        }
    }

    void loadFileToMap() {
        ifstream myfile;
        string line;
        vector<string> parsing;
        myfile.open("Solutions.txt");
        while (getline(myfile, line)) {
            parsing = Utils::splitToVectorByDelimiter(line, fileDelimiter);
            problemToSolutions.insert(make_pair(parsing.at(0), parsing.at(1)));
        }
        myfile.close();

    }
};


#endif //SERVER_FILECACHEMANAGER_H
