//Student.cpp
#include <iostream>
#include <string>
#include <random>
#include <time.h>

using namespace std;

#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"


// Constructors/Destructors
    Student::Student():GameObject('S')
    {
        speed = 5; //The speed this object travels, expressed as distance per update time unit.
        
        // Private Members Initializers
            is_at_doctor = false; // Set to true of the Student is in a DoctorsOffice
            is_at_hospital = false; // Set to true of the Student is in a Hospital
            is_in_class = false; // Set to true if this Student is in a ClassRoom.
            antibodies = 20; // Amount of antibodies a Student has.
            credits = 0; // The amount of credits points this Student has.
            dollars = 0; // The total amount of dollars this Student holds.
            assignments_to_buy = 0; // Stores the number of assignments to buy when in a ClassRoom.
            vaccines_to_buy = 0; // Stores the number of vaccines to buy when in a DoctorsOffice.
            
            current_office = NULL; // A pointer to the current DoctorsOffice.
            current_class = NULL; // A pointer to the current ClassRoom.
            current_hospital = NULL; // A pointer to the current Hospital.
            virus_qty = 0; // Number of viruses in student
        
            // num_students_INFECTED = 0;

        cout << "Student default constructed." << endl;
    }

    Student::Student(char in_code):GameObject(in_code)
    {
        speed = 5;
        state = STOPPED;
        
        // Private Members Initializers
            is_at_doctor = false; // Set to true of the Student is in a DoctorsOffice
            is_at_hospital = false; // Set to true of the Student is in a Hospital
            is_in_class = false; // Set to true if this Student is in a ClassRoom.
            antibodies = 20; // Amount of antibodies a Student has.
            credits = 0; // The amount of credits points this Student has.
            dollars = 0; // The total amount of dollars this Student holds.
            assignments_to_buy = 0; // Stores the number of assignments to buy when in a ClassRoom.
            vaccines_to_buy = 0; // Stores the number of vaccines to buy when in a DoctorsOffice.

            current_office = NULL; // A pointer to the current DoctorsOffice.
            current_class = NULL; // A pointer to the current ClassRoom.
            current_hospital = NULL; // A pointer to the current Hospital.
       
        cout << "Student constructed." << endl;
    }

    Student::Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc):GameObject(in_loc, in_id, in_code)
    {
        speed = in_speed;
        name = in_name;
        
        // Private Members Initializers
            is_at_doctor = false; // Set to true of the Student is in a DoctorsOffice
            is_at_hospital = false; // Set to true of the Student is in a Hospital
            is_in_class = false; // Set to true if this Student is in a ClassRoom.
            antibodies = 20; // Amount of antibodies a Student has.
            credits = 0; // The amount of credits points this Student has.
            dollars = 0; // The total amount of dollars this Student holds.
            assignments_to_buy = 0; // Stores the number of assignments to buy when in a ClassRoom.
            vaccines_to_buy = 0; // Stores the number of vaccines to buy when in a DoctorsOffice.

            current_office = NULL; // A pointer to the current DoctorsOffice.
            current_class = NULL; // A pointer to the current ClassRoom.
            current_hospital = NULL; // A pointer to the current Hospital.

        cout << "Student constructed" << endl;
    }

    Student::~Student()
    {
        cout << "Student destructed." << endl;
    }

    // Protected members functions
    bool Student::UpdateLocation()
    {
        antibodies--;

        dollars += GetRandomAmountOfDollars();

        if (is_in_class)
        {
            current_class->RemoveOneStudent();
            is_in_class = false;
        } else if (is_at_doctor)
        {
            current_office->RemoveOneStudent();
            is_at_doctor = false;
        } 
        else if (is_at_hospital)  
        {
            current_hospital->RemoveOneStudent();
            is_at_hospital = false;
        } 

        if (fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y))
        {
            location = destination;
            cout << display_code << id_num << ": I'm there!" << endl;
            return true;
        } else 
        {
            location = location + delta;
            cout << display_code << id_num << ": step..." << endl;
            return false;
        }
    }

    void Student::SetupDestination(Point2D dest) // Sets up the object to start moving to destination. (See “How the Student Moves”)
    {
       /* 
            The delta value contains the amount that the object’s 
            x and y coordinates will change on each update step
       */
      destination = dest;
      double dist = GetDistanceBetween(destination, location);
      delta = (destination - location) * (speed/dist);
    }

//Public member functions
    void Student::StartMoving(Point2D destination)
    {
        //Tells the student to start moving.
        SetupDestination(destination);
        
        if(destination == location)
        {
            cout << display_code << id_num << ": I am already there. See?" << endl;
            state = STOPPED;
        }else if(IsInfected())
        {
            cout << display_code << id_num << ": I am infected. I may move but you cannot see me." << endl;
            state = INFECTED;
        }else{
            state = MOVING;
            cout << display_code << id_num << ": On my way." << endl;
        }
    }

    // void Student::StartMovingToClass(ClassRoom* classr)
    // {
    //     //Tells the student to start moving to a ClassRoom
    //     SetupDestination(classr->GetLocation());

    //     if(IsInfected())
    //     {
    //         cout << display_code << id_num << ": I am infected so I can't move to class..." << endl;
    //     }
    //     else if (location == destination)
    //     {
    //         state = IN_CLASS;
    //         //is_in_class = true;
    //          if(is_in_class)
    //          {
	//        current_class->AddOneStudent();
    //          }
    //         cout << display_code << id_num << ": I am already at the Classroom!" << endl;
    //     }
    //     else
    //     {
    //         state = MOVING_TO_CLASS;
    //         cout << display_code << id_num << ": on my way to class " << classr->GetId() << endl;
    //     }
    // }

    // void Student::StartMovingToDoctor(DoctorsOffice* office)
    // { // Tells the student to start moving to a DoctorsOffice.
    //     SetupDestination(office->GetLocation());

    //     if (IsInfected())
    //     {
    //         cout << display_code << id_num << ": I am infected so I should have gone to the doctor's..." << endl;
    //     }
    //     else if (destination == location)
    //     {
    //         state = AT_DOCTORS;
	//     // is_at_doctor = true;
    //         if(is_at_doctor)
    //         {
	//          current_office->AddOneStudent();
    //         }
    //         cout << display_code << id_num << ": I am already at the doctor's!" << endl;
    //     }
    //     else
    //     {
    //         state = MOVING_TO_DOCTOR;
    //         cout << display_code << id_num << ": On my way to doctor's " << office->GetId() << endl;
    //     }
    // }

    void Student::StartMovingToClass(ClassRoom *classr)
{
    if (classr->GetLocation().x == location.x && classr->GetLocation().y == location.y)
    {
        cout << display_code << id_num << ": I am already at the Classroom!" << endl;
    }
    else
    {
        if (IsInfected()) 
        {
            cout << display_code << id_num << ": I am infected so I can't move to class..." << endl;
        } else //In this case it moves
        {
            cout << display_code << id_num << ": On my way to class " << classr->GetId() << endl;
            SetupDestination(classr->GetLocation());
            state = MOVING_TO_CLASS;

            current_class = classr;
        }
    }
}

void Student::StartMovingToDoctor(DoctorsOffice *office)
{
    if (office->GetLocation().x == location.x && office->GetLocation().y == location.y)
    {
        cout << display_code << id_num << ": I am already at the Doctor's!" << endl;
    }
    else {
        if (IsInfected()) //antibodies = 0;
        {
            cout << display_code << id_num << ": I am infected so I should have gone to the doctor's..." << endl;
        } else
        {
            cout << display_code << id_num << ": On my way to doctor's " << office->GetId() << endl;
            SetupDestination(office->GetLocation());
            state = MOVING_TO_DOCTOR;

            current_office = office;
        }
    }
}

void Student::StartMovingToHospital(HospitalVirusOnly *hospital)
{
    if (hospital->GetLocation().x == location.x && hospital->GetLocation().y == location.y)
    {
        cout << display_code << id_num << ": I am already at the Doctor's!" << endl;
    }
    else
    {
        if (IsInfected()) //antibodies = 0;
        {
            cout << display_code << id_num << ": I am infected so I should have gone to the doctor's..." << endl;
        } else
        {
            cout << display_code << id_num << ": On my way to doctor's " << hospital->GetId() << endl;
            SetupDestination(hospital->GetLocation());
            state = MOVING_TO_HOSPITAL;

            current_hospital = hospital;
        }
    }
}

    // void Student::StartLearning(unsigned int num_assignments)
    // { // Tells the Student to start learning (num_assignments) in a ClassRoom.

    //     if (IsInfected())
    //     {
    //         cout << display_code << id_num << ": I am infected so no more school for me..." << endl;
    //     }else if (state != IN_CLASS)
    //     {
    //         cout << display_code << id_num << ": I can only learn in a ClassRoom!" << endl;
    //     }else if (current_class->GetDollarCost(num_assignments) > dollars)
    //     {
    //         cout << display_code << id_num << ": Not enough money for school" << endl;
    //     }else if (current_class->GetNumAssignmentsRemaining()==0)
    //     {
    //         cout << display_code << id_num << ": This class has no more assignments!" << endl;
    //     }else{
    //         state = STUDYING_IN_CLASS;

    //         // if (num_assignments > current_class->GetNumAssignmentsRemaining())
    //         // {
    //         //     num_assignments = current_class->GetNumAssignmentsRemaining();
    //         // }

    //         cout << display_code << ": Started to learn at the ClassRoom " << current_class->GetId() << " with " << num_assignments << "assignments" << endl;

    //         assignments_to_buy = num_assignments;
    //     }
    // }

    void Student::StartLearning(unsigned int num_assignments)
    {
        if (IsInfected())
        {
            cout << display_code << id_num << ": I am infected so no more school for me..." << endl;
        } else if (state != IN_CLASS)
        {
            cout << display_code << id_num << ": I can only learn in a class room!" << endl;
        } else if (!current_class->IsAbleToLearn(num_assignments, dollars, antibodies))
        {
            cout << display_code << id_num << ": Not enough antibodies and/or money for school" << endl;
        } else if (current_class->GetNumAssignmentsRemaining() == 0)
        {
            cout << display_code << id_num << ": Cannot learn! This class has no more assignments!" << endl;
        } else
        {
            state = STUDYING_IN_CLASS;
            if (current_class->GetNumAssignmentsRemaining() < num_assignments)
            {
                assignments_to_buy = current_class->GetNumAssignmentsRemaining();
            } else
            {
                assignments_to_buy = num_assignments;
            }
            cout << display_code << id_num << ": Started to learn at the ClassRoom " << current_class->GetId() << " with " << assignments_to_buy << " assignments" << endl;
        }
    }

    // void Student::StartRecoveringAntibodies(unsigned int num_vaccines) // Tells the Students to start recovering at a DoctorsOffice.
    // {
    //     if (!CanAffordVaccine(num_vaccines, dollars)) /* This student does not have enough dollars print: */
    //     {
    //         cout << display_code << id_num << ": Not enough money to recover antibodies" << endl;
    //     }else if (DoctorsOffice::state == NO_VACCINE_AVAILABLE)/* The Doctor’s Office does not have at least one vaccine remaining otherwise print: */
    //     {
    //         cout << display_code << id_num << ": Cannot recover! No vaccine remaining in this Doctor’s Office" << endl;
    //     }else if (state != AT_DOCTORS) /* This Student is not in a Doctor’s Office otherwise print: */
    //     {
    //         cout << display_code << id_num << "I can only recover antibodies at a Doctor’s Office!" << endl;
    //     }
    //     else
    //     {
    //         state = RECOVERING_ANTIBODIES;
    //         cout << display_code << id_num << ": Started recovering " << num_vaccines << " vaccines at Doctor's Office " << current_office->GetId() << endl;
        
    //     /* Five antibodies are gained for each vaccine purchased. */
    //         antibodies = antibodies + (num_vaccines*5);
    //         vaccines_to_buy = num_vaccines;
    //         DistributeVaccine(vaccines_to_buy);
    //     }
    // }

    void Student::StartRecoveringAntibodies(unsigned int num_vaccines)
    {
        if (state != AT_DOCTORS)
        {
            cout << display_code << id_num << ": I can only recover antibodies at a doctor's office!" << endl;
        } else if (!current_office->HasVaccine())
        {
            cout << display_code << id_num << ": Cannot recover! No vaccine remaining at the Doctor's Office" << endl;
        } else if (!current_office->CanAffordVaccine(num_vaccines, dollars))
        {
            cout << display_code << id_num << ": Not enough money to recover antibodies" << endl;
        }
        else
        {
            state = RECOVERING_ANTIBODIES;
            vaccines_to_buy = current_office->DistributeVaccine(num_vaccines);
            cout << display_code << id_num << ": Started recovering " << vaccines_to_buy << " vaccines at Doctor's Office " << current_office->GetId() << endl;
        }        
    }

    void Student::StartRecoveringAntibodiesAtHospital(unsigned int num_vaccines)
    {
        if(location == Point2D(0,10) || location == Point2D(20,10)) //if student is not at the hospital location
        {
            if (get_is_in_student()==false)
            {
                cout << "You don't have a virus. Only those with a virus inside them can enter the hospital." << endl;
            }
            else if(num_vaccines > 1)
            {
                cout << "You can only buy 1 vaccine from the hospital at a time. One vaccine is sufficient to fully recover." << endl;
            } 
            else if(num_vaccines==1)
            {
                if (!current_hospital->CanAffordVaccine(num_vaccines, dollars))
                {
                    cout << display_code << id_num << ": Not enough money to recover antibodies" << endl;
                }
                else if (!current_hospital->HasVaccine())
                {
                    cout << display_code << id_num << ": Cannot recover! No vaccine remaining at this hospital" << endl;
                }
                else
                {
                    state = RECOVERING_ANTIBODIES_AT_HOSPITAL;
                    vaccines_to_buy = current_hospital->DistributeVaccine(num_vaccines);
                    cout << display_code << id_num << ": Started recovering " << vaccines_to_buy << " vaccines at hospital " << current_hospital->GetId() << endl;
                }
            }
        }
        else
        {
            cout << display_code << id_num << ": I can only fully recover from a virus at a hospital!" << endl;
        }
    }


    void Student::Stop() // Tells this Student to stop doing whatever it was doing.
    {
        state = STOPPED;
        cout << display_code << id_num << ": Stopping..." << endl;
    }

    bool Student::IsInfected()
    {
        if(antibodies == 0)
        {
            cout << name << " is out of antibodies and can’t move." << endl;
            state = INFECTED;
            return true;
        }else{
            return false;
        }
    }

    bool Student::ShouldBeVisible()
    {
        if (IsInfected() == false)
        {
            return true;
        }else{
            return false;
        }
    }


    void Student::ShowStatus() // Print state specific status information. Refer to "How Student Objects Behave" for complete details.
    {
        cout << endl << name << " status: " ;//<< endl;
        GameObject::ShowStatus();
    
        switch (state)
        {
        case STOPPED: // STOPPED
            cout << " stopped" << endl;
            break;
        
        case MOVING: // MOVING
            cout << " moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << "." << endl;
            antibodies--;
            dollars += GetRandomAmountOfDollars();
            break;

        case AT_DOCTORS: // AT_DOCTORS
            cout << " inside Doctor's Office " << current_office << endl; 
            break;

        case AT_HOSPITAL: // AT_DOCTORS
            cout << " inside Hospital " << current_hospital << endl; 
            break;

        case IN_CLASS: // IN_CLASS
            cout << " inside Classroom " << current_class << endl;
            break;

        case MOVING_TO_DOCTOR: // MOVING_TO_DOCTOR
            cout << " heading to Doctor's Office " << current_office << " at a speed of " << speed << "at each step of " << delta << endl;
            break;

        case MOVING_TO_HOSPITAL: // MOVING_TO_HOSPITAL
            cout << " heading to Hospital " << current_hospital << " at a speed of " << speed << "at each step of " << delta << endl;
            break;

        case MOVING_TO_CLASS: // MOVING_TO_CLASS
            UpdateLocation();
            cout << " heading to Classroom " << current_class << " at a speed of " << speed << "at each step of " << delta << endl;
            break;

        case STUDYING_IN_CLASS: // STUDYING_IN_CLASS
            cout << " studying in Classroom " << current_class << endl;
            break;

        case RECOVERING_ANTIBODIES: // RECOVERING_ANTIBODIES
            cout << " recovering antibodies in Doctor's Office " << current_office << endl;
            break;

        case RECOVERING_ANTIBODIES_AT_HOSPITAL: // RECOVERING_ANTIBODIES_AT_HOSPITAL
            cout << " recovering antibodies in Hospital " << current_hospital << endl;
            break;           
        
        default:
            break;
        }

        cout << "       Antibodies: " << antibodies << endl;
        cout << "       Dollar: " << dollars << endl;
        cout << "       Credits: " << credits << endl;
        cout << "       Virus: " << virus_qty << endl;


    }

    bool Student::Update()
    {
        /* 
            Check "How Student objects behave part". Then the next time the Update() function is called, the Student will do 
            the appropriate thing for the current state. Thus, the Update() function contains nothing but a big switch statement.
        */

        switch (state)
        {
            case STOPPED: // STOPPED
                return false;
                break;
            
            case MOVING: // MOVING
                UpdateLocation();
                if (destination==location)
                {
                    state = STOPPED;
                    return true;
                }else{
                    state = MOVING;
                }
                break;

            case AT_DOCTORS: // AT_DOCTORS
                return false;
                break;
            
            case AT_HOSPITAL: // AT_DOCTORS
                return false;
                break;

            case IN_CLASS: // IN_CLASS
                return false;
                break;

            case MOVING_TO_DOCTOR: // MOVING_TO_DOCTOR
                if (UpdateLocation())
                {
                    current_office->AddOneStudent();
                    is_at_doctor = true;
                    state = AT_DOCTORS;
                    return true;
                } else {
                    return false;
                }
                break;
            
            case MOVING_TO_HOSPITAL: // MOVING_TO_HOSPITAL
                if (UpdateLocation())
                {
                    current_hospital->AddOneStudent();
                    is_at_hospital = true;
                    state = AT_DOCTORS;
                    return true;
                } else {
                    return false;
                }
                break;

            case MOVING_TO_CLASS: // MOVING_TO_CLASS
                if (UpdateLocation())
                {
                    current_class->AddOneStudent();
                    is_in_class = true;
                    state = IN_CLASS;
                    return true;
                } else {
                    return false;
                }
                break;

            case STUDYING_IN_CLASS:
                {
                    antibodies = antibodies - current_class->GetAntibodyCost(assignments_to_buy);
                    dollars = dollars - current_class->GetDollarCost(assignments_to_buy);
                    int creditsGained = current_class->TrainStudents(assignments_to_buy);
                    credits = credits + creditsGained;
                    cout << "** " << name << " completed " << assignments_to_buy << " assignment(s)! **" <<  endl;
                    cout << "** " << name << " gained " << creditsGained << " credit(s)! **" << endl;
                    state = IN_CLASS;
                    return true;
                }
                break;

            case RECOVERING_ANTIBODIES:
                {
                    antibodies += vaccines_to_buy * 5;
                    dollars = dollars - current_office->GetDollarCost(vaccines_to_buy);
                    cout << "** " << name << " recovered " << (vaccines_to_buy * 5) << " antibodies! **" << endl;
                    cout << "** " << name << " bought " << vaccines_to_buy << " vaccines(s)! **" << endl;
                    state = AT_DOCTORS;
                    return true;
                    break;
                }

            case RECOVERING_ANTIBODIES_AT_HOSPITAL:
                {
                    dollars = dollars - current_hospital->GetDollarCost(1);
                    DecrementVirusCount();
                    cout << "** " << name << " recovered " << 20 << " antibodies! **" << endl;
                    cout << "** " << name << " bought 1 vaccine! **" << endl;
                    state = AT_HOSPITAL;
                    return true;
                    break;
                }
        }
    }

    string Student::GetName()
    {
        return name;
    }

    void Student::MercyDestroyer() //if the student is at the location of 'DensmoreBoss' change antibodies to 5
    {
        if(antibodies < 5)
        {
            antibodies = 0;
        } else {
            antibodies = 5; //if the student is at the same location 
        }
    }

    void Student::KillAntibodies(unsigned int antKiller)
    {
        if(antKiller >= antibodies)
        {
            antibodies = 0;
        } else
        {
            antibodies -= antKiller;
        }
    }

    void Student::IncrementVirusCount()
    {
        virus_qty++;
    }

    void Student::DecrementVirusCount()
    {
        virus_qty--;
    }

    // Non-members (static):
    double GetRandomAmountOfDollars() // Returns a random number between 0.0 and 2.0 inclusive.
    {
        srand(time(NULL));
        double randValue = (double)rand() / RAND_MAX;
        double randDollars = 0.0 + randValue * (2.0 - 0.0);
        return randDollars;
    }