//
// Created by Eldar on 05-Jan-19.
//

#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Utils {

public:
    static vector<string> splitToVectorByDelimiter(string str, char delimiter);

    static string parseString(string toReverse, bool reverse);
};


#endif //SERVER_UTILS_H
