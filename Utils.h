//
// Created by Eldar on 05-Jan-19.
//

#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <string>
#include <vector>

using namespace std;

class Utils {

public:
    static vector<string> splitToVectorByDelimiter(string str, char delimiter);
};


#endif //SERVER_UTILS_H
