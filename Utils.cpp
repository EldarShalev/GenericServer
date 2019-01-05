//
// Created by Eldar on 05-Jan-19.
//

#include "Utils.h"

vector<string> Utils::splitToVectorByDelimiter(string str, char delimiter) {
    string temp = "";
    vector<string> resutlt;
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it != delimiter) {
            temp += *it;
        } else {
            resutlt.push_back(temp);
            temp = "";
        }
    }
    return resutlt;
}