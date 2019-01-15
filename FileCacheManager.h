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
    mutex m;
    map<Problem, Solution> *problemToSolutions;
    vector<string> *vic;
public:

    FileCacheManager() {
        problemToSolutions = new map<Problem, Solution>;
        vic = new vector<string>;
        loadFileToMap();
    }

    bool isSolutionSavedInCache(Problem problem) {
        std::lock_guard<mutex> lockGuard(m);
        return this->problemToSolutions->count(problem) > 0;
    }

    Solution getSolutionFromCache(Problem problem) {
        std::lock_guard<mutex> lockGuard(m);
        return this->problemToSolutions->at(problem);
    }

    void saveSolutionForProblem(Problem problem, Solution solution) {
        m.lock();
        problemToSolutions->insert(make_pair(problem, solution));
        string to_push = problem + fileDelimiter + solution;
        this->vic->push_back(to_push);
        m.unlock();
    }

    void saveAllToFile() {
        ofstream myfile;
        myfile.open("Solutions.txt", ios::app | fstream::out);
        for (vector<string>::iterator it = vic->begin(); it != vic->end(); ++it) {
            myfile << *it << "\n";
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
        delete vic;
        delete problemToSolutions;
    }
};


#endif //SERVER_FILECACHEMANAGER_H
