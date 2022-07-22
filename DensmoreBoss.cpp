// DensmoreBoss.cpp is the cpp file that allows the computer to spawn viruses at a specific location.

#include <iostream>
#include <string>
#include <list>
#include <time.h>

#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "HospitalVirusOnly.h"
#include "Student.h"
#include "View.h"
#include "Virus.h"
#include "DensmoreBoss.h"
#include "Model.h"
#include "GameCommand.h"

using namespace std;

//Constructor
DensmoreBoss::DensmoreBoss(char in_code, int in_id, Point2D in_loc):GameObject(in_loc, 0, 'V')
{
    COVIDVariantInEnvironment = 0;
    OMICRONVariantInEnvironment = 0;
}

//Deconstructor
DensmoreBoss::~DensmoreBoss()
{
    cout << "DensmoreBoss deconstructed." << endl;
}

void DensmoreBoss::MercyDestroyerStudents(Student *student) // Reduces the student's antibodies to 5. (Enough to reach a hospital)
{
    if (student->GetLocation() == location)
    {
        student->MercyDestroyer();
    }
}


bool DensmoreBoss::VariantMaker(list <Virus*> &virus_ptrs, int &num_viruses) // Virus spawner
{
    srand(time(NULL));
    int* spawner = new int(rand() % 2); // 50% chance for new virus to spawn -> Generates a random number between 0 and 1. 0 = false, 1 = true.
    if(*spawner == 1)
    {
        delete spawner;
        int* variant = new int(rand() % 2);
        if (*variant == 0) //Spawns a COVID variant
        {
            delete variant;
            num_viruses++;
        // Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc):GameObject(in_loc, id, 'V')        
            virus_ptrs.push_back(new Virus("COVID", 30, 10, 10, true, num_viruses, location));
            COVIDVariantInEnvironment++;
            cout << "DensmoreBoss" << id_num << " spawned a Covid variant" << endl;
            return true;
        } else if (*variant == 1)
        {
            delete variant;
            num_viruses++;
            virus_ptrs.push_back(new Virus("OMICRON", 60, 20, 20, true, num_viruses, location));
            OMICRONVariantInEnvironment++;
            cout << "DensmoreBoss" << id_num << " spawned an Omicron variant" << endl;
            return true;
        } else {
            return false;
        }
    } 
    else if (*spawner == 0)
    {
        delete spawner;
        return false;
    }

}

void DensmoreBoss::ShowStatus()
{
    cout << endl << "DensmoreBoss status: ";
    GameObject::ShowStatus();
    cout << endl;
    cout << "       Number of COVID variants in environment: " << COVIDVariantInEnvironment << endl;
    cout << "       Number of OMICRON variants in environment: " << OMICRONVariantInEnvironment << endl << endl;
}

