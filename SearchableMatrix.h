//
// Created by Eldar on 1/9/2019.
//

#ifndef SERVER_SEARCHABLEMATRIX_H
#define SERVER_SEARCHABLEMATRIX_H

#include <vector>
#include "Searchable.h"
#include "Point.h"

class SearchableMatrix : public virtual Searchable<Point> {
private:
    int size;
    const Point* start;
    const Point* dest;
    vector<vector<int>> matrix;
    map<Point, State<Point>*> matrixToStates(const vector<vector<int>> &matrix);
public:
    SearchableMatrix(int size, const Point &start, const Point &dest, const vector<vector<int>> &matrix);
};


#endif //SERVER_SEARCHABLEMATRIX_H
