//
// Created by Eldar on 05-Jan-19.
//

#include "Utils.h"

vector<string> Utils::splitToVectorByDelimiter(string str, char delimiter) {
    string temp = "";
    vector<string> result;
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it != delimiter) {
            temp += *it;
        } else {
            result.push_back(temp);
            temp = "";
        }
    }
    result.push_back(temp);
    return result;
}

string Utils::parseString(string str, bool shouldReverse) {
    string temp;
    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it == '\n' || *it == '\r' || *it == '\0') {
            continue;
        }
        temp += *it;
    }
    if (shouldReverse) {
        reverse(temp.begin(), temp.end());
    }
    return temp;
}