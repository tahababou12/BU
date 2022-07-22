//Virus.cpp

#include <iostream>
#include <math.h>
#include <time.h>

#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"
#include "View.h"
#include "Virus.h"
#include "DensmoreBoss.h"
#include "Model.h"
#include "GameCommand.h"

using namespace std;

Virus::Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc):GameObject(in_loc, id, 'V')
{
    this->energy = energy;
    this->virulence = virulence;
    this->name = name;
    this->resistance = resistance;
    this->is_in_student = false;
    this->speed = 1;
    this->variant = variant;
    this->state = IN_ENVIRONMENT;

    do {
        srand(time(NULL));
        int num = rand() % 5 + 1;

        switch (num)
        {
            case 1:
                destination = Point2D(0, 20); //left
                break;

            case 2:
                destination = Point2D(0, 20); //diagonal
                break;

            case 3:
                destination = Point2D(20, 0); //down
                break;

            case 4:
                destination = Point2D(0, 10); //half y-axis, x=0
                break;

            case 5:
                destination = Point2D(10, 0); //half x-axis, y=0
                break;
        }
    } while (in_loc == destination); // until virus reaches its destination
    
    DeltaSetup();

    cout << "Virus constructed" << endl;
}

Virus::~Virus()
{
    cout << "Virus destructed" << endl;
}

void Virus::infect(Student* student) // Virus enters the student's body
{
    if (is_in_student == false && ShouldBeVisible() == true)
    {
        // Verifies if the student and virus are in the same location.
        if ((student->GetLocation()) == (location))
        {
            is_in_student = true;
            current_student = student;
            state = IN_STUDENT;
            student->IncrementVirusCount();
        }
    }
}

void Virus::ChargeKill() // reduces antibodies in student's body
{
    if (is_in_student)
    {
        unsigned int VE = virulence / energy;
        current_student->KillAntibodies(VE);
    }
}

bool Virus::get_variant()
{
    return variant;
}


double Virus::get_virulence()
{
    return virulence;
}


double Virus::get_resistance()
{
    return resistance;
} 


double Virus::get_energy()
{
    return energy;
}

bool Virus::get_is_in_student()
{
    return is_in_student;
}

string Virus::get_name()
{
    return name;
}

bool Virus::UpdateLocation()
{
    if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y) && !is_in_student)
    {
        location = destination;
        energy = 0;
        cout << display_code << id_num << ": Your immune system is weak. Eat your vegetables... *sigh* I'm leaving this body." << endl;
        return true;
    }
    else
    {
        location = location + delta;
        cout << display_code << id_num << ": step..." << endl;
        return false;
    }
}

bool Virus::Update()
{
    UpdateLocation();    
    if (energy <= 0 || !IsAlive())
    {
        state = DEAD; // When the Virus’ energy is 0 or below
        cout << "Virus " << id_num << " is dead" << endl;
        if (is_in_student)
        {
            current_student->DecrementVirusCount();
        }
        current_student = NULL; 
    }
    else if (is_in_student)
    {
        state = IN_STUDENT; // When the Virus is in a student
        return true;
    }
    return false;
}


void Virus::ShowStatus()
{
    if (IsAlive())
    {
        cout << "Virus status: ";
        GameObject::ShowStatus();

        switch (state) // Correct???
        {
        case DEAD:
            cout << " Virus is dead." << endl;
            break;

        case IN_STUDENT:
            is_in_student = true;
            cout << " Virus is in the student." << endl;
            break;
            
        case IN_ENVIRONMENT:
            cout << " Virus is in the environment." << endl;
            break;

        default:
            break;
        }

        cout << "       Name: " << name << endl;
        cout << "       Virulence: " << virulence << endl;
        cout << "       Resistance: " << resistance << endl;
        cout << "       Energy: " << energy << endl;

        if (is_in_student)
        {
            cout << "       Virus is in student: " << current_student->GetName() << endl;
        }
    } else {
        cout << "Virus is dead." << endl;
    }
}


bool Virus::IsAlive()
{
    // Checks the energy of a virus and returns true if it is alive.
    if(energy > 0)
    {
        return true;
    } else {
        return false;
    }
}

void Virus::DeltaSetup()
{
    double distance = GetDistanceBetween(destination, location);
    delta = (destination - location) * (speed/distance);
}

bool Virus::ShouldBeVisible() //makes sure that the virus is in the environment
{
    if (state == IN_ENVIRONMENT)
    {
        return true;
    } else
    {
        return false;
    }
}
