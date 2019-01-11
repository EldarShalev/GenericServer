//
// Created by Eldar on 1/9/2019.
//

#ifndef SERVER_ASTAR_H
#define SERVER_ASTAR_H

#include <stack>
#include <cmath>
#include <cstring>
#include <climits>
#include <set>
#include "Utils.h"

#include "Searcher.h"

template<typename T>
class Astar : public Searcher<T> {
private:
    void calcLogic(const map<T, State<T>> data, State<T> curr, set<State<T>> &openList){
        SearcherResult infoPrev = Utils::getSearcherResult(curr.getPrevious());
        SearcherResult infoCurr = Utils::getSearcherResult(curr);
        int fPrev = infoPrev.distance + infoPrev.cost;
        int fCurr = infoCurr.distance + infoCurr.cost;

        // If it isn’t on the open list, add it to
        // the open list. Make the current square
        // the parent of this square. Record the
        // f, g, and h costs of the square cell
        //                OR
        // If it is on the open list already, check
        // to see if this path to that square is better,
        // using 'f' cost as the measure.
        if (fPrev >= INT_MAX || fPrev > fCurr) {
            openList.insert(curr);
        }
    }
public:
    SearcherResult search(Searchable<T> searchable) {
        map<T, State<T>> data = searchable.getAllPossibleStates();
        int m = data.size();
        int n = m;
        T start = searchable.getInitialState();
        T dest = searchable.getGoalState();

        // If the destination cell is the same as source cell
        if (start == dest) {
            return Utils::getSearcherResult(data[start]);
        }

        // Create a closed list and initialise it to false which means
        // that no cell has been included yet
        // This closed list is implemented as a boolean 2D array
        map<T, bool> closedList;

        // These arrays are used to get row and column
        // numbers of 4 neighbours of a given cell
        int rowNum[] = {-1, 0, 0, 1};
        int colNum[] = {0, -1, 1, 0};

        set<State<T>> openList;

        // Put the starting cell on the open list and set its
        // 'f' as 0
        openList.insert(data[start]);

        while (!openList.empty()) {
            State<T> p = *openList.begin();

            // Remove this vertex from the open list
            openList.erase(openList.begin());

            // Add this vertex to the closed list
            closedList[p] = true;

            for (int i = 0; i < 4; i++) {
                T next = p.getState().calcNext({rowNum[i], colNum[i]});
                data[next].setPrevious(p);

                // If the destination cell is the same as the
                // current successor
                if (next == dest) {
                    return Utils::getSearcherResult(data[next]);
                } else if (!closedList[next]  && data[next].getCost() > -1) {
                    calcLogic(data, data[next], openList);
                }
            }
        }

        // When the destination cell is not found and the open
        // list is empty, then we conclude that we failed to
        // reach the destination cell. This may happen when the
        // there is no way to destination cell (due to blockages)
        return {-1, -1};
    }
};

#endif //SERVER_ASTAR_H
