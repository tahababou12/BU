//ClassRoom.h

#ifndef CLASSROOM_H
#define CLASSROOM_H

#include <iostream>

// #include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
// #include "DoctorsOffice.h"

using namespace std;

enum ClassRoomStates 
{ 
    NOT_PASSED = 0, 
    PASSED = 1
};

class ClassRoom: public Building // ClassRoom objects should inherit from Building.
{   // Private Members
    unsigned int num_assignments_remaining;
    unsigned int max_number_of_assignments;
    unsigned int antibody_cost_per_assignment;
    double dollar_cost_per_assignment;
    unsigned int credits_per_assignment;

    public:
        //Constructors
        ClassRoom();
        ClassRoom(unsigned int, unsigned int, double, unsigned int, int, Point2D);
        //Deconstructor
        ~ClassRoom();

        //Public Member Functions
        double GetDollarCost(unsigned int);
        unsigned int GetAntibodyCost(unsigned int);
        unsigned int GetNumAssignmentsRemaining();
        bool IsAbleToLearn(unsigned int, double, unsigned int);
        unsigned int TrainStudents(unsigned int);
        bool Update();
        bool passed();
        static int num_classes_PASSED; // bonus public member (added for model.cpp)
        void ShowStatus();
};

#endif
