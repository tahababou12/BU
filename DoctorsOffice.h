//DoctorsOffice.h

#ifndef DOCTORSOFFICE_H
#define DOCTORSOFFICE_H

#include <iostream>
#include "Building.h"
#include "GameObject.h"
#include "Point2D.h"

using namespace std;

enum DoctorsOfficeStates { 
    VACCINE_AVAILABLE = 0, 
    NO_VACCINE_AVAILABLE = 1
};

class DoctorsOffice: virtual public Building
{   // Private Members
    unsigned int vaccine_capacity;
    unsigned int num_vaccine_remaining;
    double dollar_cost_per_vaccine;

    public:
        //Constructors
        DoctorsOffice();
        DoctorsOffice(int, double, unsigned int, Point2D);
        //Deconstructor
        ~DoctorsOffice();

        //Public Member Functions
        bool HasVaccine();
        unsigned int GetNumVaccineRemaining();
        bool CanAffordVaccine(unsigned int, double);
        double GetDollarCost(unsigned int);
        unsigned int DistributeVaccine(unsigned int);
        bool Update();
        void ShowStatus();
};

#endif
