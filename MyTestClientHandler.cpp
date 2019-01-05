//
// Created by Eldar on 03-Jan-19.
//

#include "MyTestClientHandler.h"


void MyTestClientHandler::handleClient(string problem) {

    string reverseString;
    if (this->cacheManager->isSolutionSavedInCache(problem)) {
        this->cacheManager->getSolutionFromCache(problem);
    } else {
        reverseString = this->solver->solve(problem);
        this->cacheManager->saveSolutionForProblem(problem,reverseString);
    }
}