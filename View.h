// View.h

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "Point2D.h"
#include "GameObject.h"

using namespace std;

const int view_maxsize = 20; // The maximum size of the grid array

class View
{
    int size; // The current size of the grid to be displayed; not all of the grid array will be displayed in this project.
    double scale; // The distance represented by each cell of the grid
    Point2D origin; // The coordinates of the lower left-hand corner of the grid
    char grid[view_maxsize][view_maxsize][2]; // An array to hold the characters that make up the display grid.
    bool GetSubscripts(int &out_x, int &out_y, Point2D location);

    public:
        View();
        void Clear();
        void Plot(GameObject * ptr);
        void Draw();
};

#endif

