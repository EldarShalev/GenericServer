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

Point Utils::getPointFromString(string str) {
    string first = splitStringByDelimiterAndIndex(str, ',', 1);
    string second = splitStringByDelimiterAndIndex(str, ',', 2);
    Point p1(std::stoi(first), std::stoi(second));
    return p1;
}

vector<vector<int>> Utils::vecStringToInt(vector<string> vector1, int matrixSize) {
    vector<vector<int>> vic1;
    vector<int> temp;
    int row = 0;
    int col = 0;
    for (vector<string>::iterator it = vector1.begin(); it != vector1.end(); ++it) {
        for (int i = 0; i < matrixSize; i++) {
            int num = stoi(splitStringByDelimiterAndIndex(*it, ',', i + 1));
            temp.push_back(num);
        }

        vic1.push_back(temp);
        temp.clear();
    }
}

string Utils::splitStringByDelimiterAndIndex(string str, char delimiter, int index) {
    int counter = 0;
    string temp;
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it != delimiter) {
            temp += *it;
        } else if (*it == ' ') {
            continue;
        } else if (counter == index - 1) {
            return temp;
        } else {
            counter++;
            temp = "";
        }
    }
    return temp;
}