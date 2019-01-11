//
// Created by Eldar on 1/9/2019.
//

#include "SearchableMatrix.h"

SearchableMatrix::SearchableMatrix(int size, const Point &start, const Point &dest, const vector<vector<int>> &matrix)
        : Searchable<Point>(start, dest, matrixToStates(matrix)), size(size), start(start), dest(dest), matrix(matrix) {
}

map<Point, State<Point>> SearchableMatrix::matrixToStates(const vector<vector<int>> &matrix) {
    map<Point, State<Point>> points;
    for(int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            Point pt = {i, j};
            State<Point> state(pt, matrix[i][j]);
            points.insert(pair<Point, State<Point>>(pt, state));
        }
    }
    return points;
}
