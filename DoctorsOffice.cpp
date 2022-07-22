//DoctorsOffice.cpp

#include <iostream>
#include "DoctorsOffice.h"

using namespace std;

DoctorsOffice::DoctorsOffice():GameObject('D')
{
    vaccine_capacity = 100;
    num_vaccine_remaining = vaccine_capacity;
    dollar_cost_per_vaccine = 5;
    state = VACCINE_AVAILABLE;

    cout << "DoctorsOffice default constructed" << endl;
}

//Check the function header below
DoctorsOffice::DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc):GameObject('D')
{
    id_num = in_id;
    location = in_loc;
    dollar_cost_per_vaccine = vaccine_cost;
    num_vaccine_remaining = vaccine_cap;

    cout << "DoctorsOffice constructed" << endl;

    state = VACCINE_AVAILABLE;
}

DoctorsOffice::~DoctorsOffice()
{
    cout << "DoctorsOffice destructed" << endl;
}

bool DoctorsOffice::HasVaccine()
{
    if(num_vaccine_remaining > 0)
    {
        return true;
    }else{
        return false;
    }
}

unsigned int DoctorsOffice::GetNumVaccineRemaining()
{
    return num_vaccine_remaining;
}

bool DoctorsOffice::CanAffordVaccine(unsigned int vaccine, double budget)
{
    if(GetDollarCost(vaccine) <= budget)
    {
        return true;
    }else{
        return false;
    }
}

double DoctorsOffice::GetDollarCost(unsigned int vaccine) // if you can afford the vaccine
{
    return dollar_cost_per_vaccine * vaccine; // returns a value in all control paths
}

unsigned int DoctorsOffice::DistributeVaccine(unsigned int vaccine_needed)
{
    if(num_vaccine_remaining >= vaccine_needed)
    {
        num_vaccine_remaining -= vaccine_needed;
        return vaccine_needed;
    }else{
        return num_vaccine_remaining;
        num_vaccine_remaining = 0;
    }
}

bool DoctorsOffice::Update()
{
    if(num_vaccine_remaining == 0)
    {
        state = NO_VACCINE_AVAILABLE;
        GameObject::display_code = 'd';
        cout << "DoctorsOffice " << id_num << " has ran out of vaccine." << endl;
        return true; //returns true if vaccine is depleted.
    }else{
        return false; //returns false if vaccine is not depleted.
    }
}

void DoctorsOffice::ShowStatus()
{
    // Prints out the status of the object:
    cout << endl << "DoctorsOffice Status: ";
    Building::ShowStatus();
    cout << "       Dollars per vaccine: " << dollar_cost_per_vaccine << endl;
    cout << "       has " << num_vaccine_remaining << " vaccine(s) remaining." << endl;
}