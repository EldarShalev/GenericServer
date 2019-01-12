//
// Created by Eldar on 1/9/2019.
//

#include "SearchableMatrix.h"

SearchableMatrix::SearchableMatrix(int size, const Point &start, const Point &dest, const vector<vector<int>> &matrix)
        : Searchable<Point>(start, dest, matrixToStates(matrix)), size(size), start(&start), dest(&dest),
          matrix(matrix) {
}

map<Point, State<Point>*> SearchableMatrix::matrixToStates(const vector<vector<int>> &matrix) {
    map<Point, State<Point>*> points;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            Point pt = {i, j};
            State<Point> *state = new State<Point>(pt, matrix[i][j]);
            pair<Point, State<Point>*> p1(pt, state);
            points.insert(p1);
        }
    }
    return points;
}

template<>
vector<State<Point>*> Searchable<Point>::getAllPossibleStates(State<Point> *pred) {
    vector<State<Point>*> result;
    // These arrays are used to get row and column
    // numbers of 4 neighbours of a given cell
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    Point pt = pred->getState();

    for (int i = 0; i < 4; i++) {
        Point next = pt.calcNext({rowNum[i], colNum[i]});
        if (allStates.count(next) > 0) {
            result.push_back(allStates[next]);
        }
    }

    return result;
}