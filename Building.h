//Building.h

#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>

#include "GameObject.h"

using namespace std;
 
class Building: virtual public GameObject
{   // Private Members
    unsigned int student_count;
    
    public:
        //Constructors
        Building();
        Building(char, int, Point2D);

        //Deconstructor
        virtual ~Building();
        
        //Public Member Functions
        void AddOneStudent();
        void RemoveOneStudent();
        void ShowStatus();
        bool ShouldBeVisible();
};

#endif
