//HospitalVirusOnly.h

#ifndef HOSPITALVIRUSONLY_H
#define HOSPITALVIRUSONLY_H

#include <iostream>
#include "Building.h"
#include "GameObject.h"
#include "Point2D.h"

using namespace std;

enum HospitalVirusOnlyStates { 
    VAX_AVAILABLE = 0, 
    NO_VAX_AVAILABLE = 1
};

class HospitalVirusOnly: virtual public Building
{   // Private Members
    unsigned int vaccine_capacity;
    unsigned int num_vaccine_remaining;
    double dollar_cost_per_vaccine;

    public:
        //Constructors
        HospitalVirusOnly();
        HospitalVirusOnly(int, double, unsigned int, Point2D);
        //Deconstructor
        ~HospitalVirusOnly();

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
