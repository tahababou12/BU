// View.cpp

#include <iostream>
#include "math.h"
#include "View.h"

using namespace std;

// Private member function
    bool View::GetSubscripts(int &out_x, int &out_y, Point2D location)
    {
        Vector2D cw = (location - origin) / scale;
        out_x = cw.x;
        out_y = cw.y;

        if(out_x > -1 && out_x <= size - 1 && out_y > -1 && out_y <= size - 1)
        {
            return true;
        }else{
            cout << "An object is outside the display." << endl;
            return false;
        }
    }

// Public members functions
    
    // Constructor
        View::View()
        {
            origin = Point2D(0,0);
            size = 11;
            scale = 2;
        }

    void View::Clear()
    {
        for(int i = 0; i < view_maxsize; i++)
        {
            for(int j = 0; j < view_maxsize; j++)
            {
                grid[i][j][0] = '.';
                grid[i][j][1] = ' ';
            }
        }
    }
    
    void View::Plot(GameObject * ptr)
    {
        int x,y;
        bool valid = GetSubscripts(x,y, ptr-> GetLocation());

        if (grid[x][y][0] == '.' && valid)
        {
             ptr->DrawSelf(&grid[x][y][0]);
        }
        else if(grid[x][y][0] == valid)
        {
            grid[x][y][0] = '*';
            grid[x][y][1] = ' ';
        }
    }
    
    void View::Draw()
    {
        for (int j = size-1; j >= -1; j--) {
            for (int i = -1; i <= size-1; i++) {
                //grid axis
                if (i == -1 && j%2 == 0) {
                    cout << j*2;
                    if (j/5 == 0) {
                        cout << " ";
                    }
                }
                else if (i == -1 && j%2 != 0) {
                    cout << "  ";
                }
                else if (j == -1 && i%2 == 0) {
                    cout << i*2;
                    if (i/5 == 0) {
                        cout << " ";
                    }
                    cout << "  ";
                }
                //draw objects
                if (i >= 0 && j >=0) {
                    cout << grid[i][j][0] << grid[i][j][1];
                }
            }
            cout << endl;
        }
    }