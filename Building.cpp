//Building.cpp

#include <iostream>
#include "Building.h"
using namespace std;

unsigned int student_count = 0; // The number of Students currently within this Building. Initial set at 0.

Building::Building():GameObject('B')
{
    student_count = 0;
    cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc):GameObject(in_loc, in_Id, in_code)
{
    student_count = 0;
    cout << "Building constructed" << endl;
}

Building::~Building()
{
    cout << "Building destructed" << endl;
}

void Building::AddOneStudent()
{
    student_count++;
}

void Building::RemoveOneStudent()
{
    student_count--;
}

void Building::ShowStatus()
{
    GameObject::ShowStatus();

    if (student_count == 1)
    {
        cout << endl << "       " << student_count << " student is in this building" << endl;
    }else if (student_count > 1 || student_count == 0){
        cout << endl << "       " << student_count << " students are in this building" << endl;
    }
}

bool Building::ShouldBeVisible()
{
    return true;
}


