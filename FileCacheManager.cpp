//
// Created by Eldar on 03-Jan-19.
//

#include "FileCacheManager.h"

FileCacheManager::FileCacheManager() {
    //Default behaviour - singleton file, loading file to problemToSolutions only once
    loadFileToMap();
}

bool FileCacheManager::isSolutionSavedInCache(string problem) {
    return this->problemToSolutions.count(problem) > 0;
}

string FileCacheManager::getSolutionFromCache(string problem) {
    return this->problemToSolutions[problem];
}

void FileCacheManager::saveSolutionForProblem(string prob, string sol) {
    problemToSolutions.insert(make_pair(prob, sol));
    saveAlsoToFile(prob, sol);
}

void FileCacheManager::saveAlsoToFile(string problem, string solution) {
    ofstream myfile;
    myfile.open("Solutions.txt", ios::app | fstream::out);
    if (myfile.is_open()) {
        myfile << problem << fileDelimiter << solution << "\n";
        myfile.close();
    }
}

void FileCacheManager::loadFileToMap() {
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