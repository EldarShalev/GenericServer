//
// Created by Eldar on 03-Jan-19.
//

#include "MyTestClientHandler.h"


void MyTestClientHandler::handleClient(string problem) {

    string reverseString;
    string parsedProblem = Utils::parseString(problem, false);
    if (this->cacheManager->isSolutionSavedInCache(parsedProblem)) {
        this->cacheManager->getSolutionFromCache(parsedProblem);
    } else {

        reverseString = this->solver->solve(problem);
        this->cacheManager->saveSolutionForProblem(parsedProblem, reverseString);
    }
}