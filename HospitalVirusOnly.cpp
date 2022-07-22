//HospitalVirusOnly.cpp

#include <iostream>
#include "HospitalVirusOnly.h"

using namespace std;

HospitalVirusOnly::HospitalVirusOnly():GameObject('H')
{
    vaccine_capacity = 10;
    num_vaccine_remaining = vaccine_capacity;
    dollar_cost_per_vaccine = 10;
    state = VAX_AVAILABLE;

    cout << "HospitalVirusOnly default constructed" << endl;
}

//Check the function header below
HospitalVirusOnly::HospitalVirusOnly(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc):GameObject('H')
{
    id_num = in_id;
    location = in_loc;
    dollar_cost_per_vaccine = vaccine_cost;
    num_vaccine_remaining = vaccine_cap;

    cout << "HospitalVirusOnly constructed" << endl;

    state = VAX_AVAILABLE;
}

HospitalVirusOnly::~HospitalVirusOnly()
{
    cout << "HospitalVirusOnly destructed" << endl;
}

bool HospitalVirusOnly::HasVaccine()
{
    if(num_vaccine_remaining > 0)
    {
        return true;
    }else{
        return false;
    }
}

unsigned int HospitalVirusOnly::GetNumVaccineRemaining()
{
    return num_vaccine_remaining;
}

bool HospitalVirusOnly::CanAffordVaccine(unsigned int vaccine, double budget)
{
    if(GetDollarCost(vaccine) <= budget)
    {
        return true;
    }else{
        return false;
    }
}

double HospitalVirusOnly::GetDollarCost(unsigned int vaccine) // if you can afford the vaccine
{
    return dollar_cost_per_vaccine * vaccine; // should always be equal to $15
}

unsigned int HospitalVirusOnly::DistributeVaccine(unsigned int vaccine_needed)
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

bool HospitalVirusOnly::Update()
{
    if(num_vaccine_remaining == 0)
    {
        state = NO_VAX_AVAILABLE;
        GameObject::display_code = 'h';
        cout << "Hospital " << id_num << " has ran out of vaccine." << endl;
        return true; //returns true if vaccine is depleted.
    }else{
        return false; //returns false if vaccine is not depleted.
    }
}

void HospitalVirusOnly::ShowStatus()
{
    // Prints out the status of the object:
    cout << endl << "HospitalVirusOnly Status: ";
    // GameObject::ShowStatus();
    Building::ShowStatus();
    cout << "       Dollars per vaccine: " << dollar_cost_per_vaccine << endl;
    cout << "       has " << num_vaccine_remaining << " vaccine(s) remaining." << endl;
}