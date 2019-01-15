//
// Created by Eldar on 05-Jan-19.
//

#include "Utils.h"

vector<string> Utils::splitToVectorByDelimiter(string str, char delimiter) {
    string temp;
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

vector<string> Utils::split(const string &s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

vector<vector<int>> Utils::vecStringToMatrix(vector<string> strings) {
    vector<vector<int>> matrix;
    vector<int> array;

    for (int i = 0; i < strings.size(); ++i) {
        vector<string> splitted = split(strings[i], ',');
        for (int j = 0; j < splitted.size(); ++j) {
            int num = stoi(splitted[j]);
            array.push_back(num);
        }
        matrix.push_back(array);
        array.clear();
    }

    return matrix;
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