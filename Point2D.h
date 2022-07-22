#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include "Vector2D.h"

using namespace std;
 
class Point2D
{
    public:
        double x;
        double y;
        Point2D();
        Point2D(double, double);
};
 
double GetDistanceBetween(Point2D, Point2D);

bool operator== (Point2D, Point2D);

// bool operator!= (Point2D, Point2D); // (bonus) added for students.cpp

// bool operator<= (Point2D, Point2D); // (bonus) added for students.cpp
 
Point2D operator+ (Point2D, Vector2D);
 
Vector2D operator- (Point2D, Point2D);
 
ostream& operator<< (ostream&, Point2D);

#endif
