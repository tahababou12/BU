//Classroom.cpp

#include <iostream>
#include "ClassRoom.h"
#include "Building.h"
using namespace std;

ClassRoom::ClassRoom():GameObject('C')
{
    state = NOT_PASSED;
    max_number_of_assignments = 10;
    num_assignments_remaining = max_number_of_assignments;
    antibody_cost_per_assignment = 1;
    dollar_cost_per_assignment = 1.0;
    credits_per_assignment = 2;

    cout << "ClassRoom default constructed" << endl;
}

ClassRoom::ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost, unsigned int crd_per_assign, int in_id, Point2D in_loc):GameObject(in_loc, in_id, 'C')
{
    state = NOT_PASSED;
    max_number_of_assignments = max_assign;
    num_assignments_remaining = max_number_of_assignments;
    antibody_cost_per_assignment = antibody_cost;
    dollar_cost_per_assignment = dollar_cost;
    credits_per_assignment = 2;

    cout << "ClassRoom constructed" << endl;
}

ClassRoom::~ClassRoom()
{
    cout << "ClassRoom destructed" << endl;
}

double ClassRoom::GetDollarCost(unsigned int unit_qty) //Returns the cost of purchasing “unit_qty” assignments
{
    return dollar_cost_per_assignment * unit_qty;
}

unsigned int ClassRoom::GetAntibodyCost(unsigned int unit_qty)
{
    return antibody_cost_per_assignment * unit_qty;
}

unsigned int ClassRoom::GetNumAssignmentsRemaining()
{
    return num_assignments_remaining;
}

bool ClassRoom::IsAbleToLearn(unsigned int unit_qty, double budget, unsigned int antibodies)
{
    if(budget >= GetDollarCost(unit_qty) && antibodies >= GetAntibodyCost(unit_qty))
    {
        return true;
    }else{
        return false;
    }
}

unsigned int ClassRoom::TrainStudents(unsigned int assignment_units)
{
    if(assignment_units <= num_assignments_remaining)
    {
        num_assignments_remaining -= assignment_units;    
    }
    else if(assignment_units > num_assignments_remaining)
    {
        return num_assignments_remaining;
    }
    return credits_per_assignment * assignment_units; // credits points can be calculated using (number of assignments) * credits_per_assignment
}

bool ClassRoom::Update()
{
    if(num_assignments_remaining == 0 && state == NOT_PASSED)
    {
        state = PASSED;
        display_code = 'c';
        cout << display_code << id_num << " has been passed.";
        return true; // returns a bool value in all control paths
    }else{
        return false;
    }
}

bool ClassRoom::passed()
{
    if(num_assignments_remaining == 0)
    {
        return true;
    }else{
        return false;
    }
}

void ClassRoom::ShowStatus()
{
    cout << endl << "ClassRoom Status: ";
    Building::ShowStatus();
    cout << "       Max number of assignments: " << max_number_of_assignments << endl;
    cout << "       Antibody cost per assignment: " << antibody_cost_per_assignment << endl;
    cout << "       Dollar per assignment: " << dollar_cost_per_assignment << endl;
    cout << "       Credit per assignment: " << credits_per_assignment << endl;
    cout << "       " << num_assignments_remaining << " assignment(s) are remaining for this ClassRoom" << endl;
}