#include <iostream>
#include <list>
#include <iterator>

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
#include "Input_Handling.h"


using namespace std;

// Public members functions
    Model::Model()
    {
        time = 0;

// Student(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);
        Point2D S1(5,1);
        student_ptrs.push_back(new Student("Homer", 1, 'S', 2, S1));
        object_ptrs.push_back(student_ptrs.back());
        active_ptrs.push_back(student_ptrs.back());
        
        Point2D S2(10,1);
        student_ptrs.push_back(new Student("Marge", 2, 'S', 2, S2));
        object_ptrs.push_back(student_ptrs.back());
        active_ptrs.push_back(student_ptrs.back());

// ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost, unsigned int crd_per_assign, int in_id, Point2D in_loc)
        Point2D C1(0,0);
        class_ptrs.push_back(new ClassRoom(10, 1, 2, 3, 1, C1));
        object_ptrs.push_back(class_ptrs.back());
        active_ptrs.push_back(class_ptrs.back());

        Point2D C2(5,5);
        class_ptrs.push_back(new ClassRoom(20, 5, 7.5, 4, 2, C2));
        object_ptrs.push_back(class_ptrs.back());
        active_ptrs.push_back(class_ptrs.back());

// DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc)
        Point2D D1(1,20);
        office_ptrs.push_back(new DoctorsOffice(1, 1, 100, D1));
        object_ptrs.push_back(office_ptrs.back());
        active_ptrs.push_back(office_ptrs.back());

        Point2D D2(10,20);
        office_ptrs.push_back(new DoctorsOffice(2, 2, 200, D2));
        object_ptrs.push_back(office_ptrs.back());
        active_ptrs.push_back(office_ptrs.back());

// HospitalVirusOnly(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc)
        Point2D H1(0,10);
        hospital_ptrs.push_back(new HospitalVirusOnly(1, 15, 10, H1));
        object_ptrs.push_back(hospital_ptrs.back());
        active_ptrs.push_back(hospital_ptrs.back());

        Point2D H2(20,10);
        hospital_ptrs.push_back(new HospitalVirusOnly(2, 15, 10, H2));
        object_ptrs.push_back(hospital_ptrs.back());
        active_ptrs.push_back(hospital_ptrs.back());

// Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc):GameObject(in_loc, id, 'V')
        // Point2D Covid(10,12); //Initial Covid variant // had a segmentation error, not sure how to fix - so I decided to disable the "initial virus" locations
        // Virus* ptrVirus1 = new Virus("COVID", 30.0, 10.0, 10.0, true, 1, Covid);
        // object_ptrs.push_back(virus_ptrs.back());
        // active_ptrs.push_back(virus_ptrs.back());

        // Point2D Omicron(15,5); //Initial OmiCron variant
        // Virus* ptrVirus2 = new Virus("OMICRON", 60.0, 20.0, 20.0, true, 2, Omicron);
        // object_ptrs.push_back(virus_ptrs.back());
        // active_ptrs.push_back(virus_ptrs.back());

// DensmoreBoss(char in_code, int in_id, Point2D in_loc):GameObject(in_loc, in_id, in_code)
        Point2D DB1(20,20); // main spawner location (i.e. "DensmoreBoss Spawner")
        densmore_ptrs.push_back(new DensmoreBoss('V', 1, DB1));
        object_ptrs.push_back(densmore_ptrs.back());
        active_ptrs.push_back(densmore_ptrs.back());

        num_objects = 8;
        num_students = 2;
        num_classes = 2;
        num_offices = 2;
        num_hospital = 2;
        num_densmore = 1;
        num_viruses = 0;

        cout << "Model default constructed" << endl;

    }
Model::~Model() // Destructor deletes each object
{
    list <GameObject*>::iterator loop;
    for (loop = object_ptrs.begin(); loop != object_ptrs.end(); loop++)
    {
        delete *loop;
    } 
}

Student*  Model::GetStudentPtr(int id){ // modified to work for linked lists
    list <Student*>::iterator loop;
    for (loop = student_ptrs.begin(); loop != student_ptrs.end(); loop++)
    {
        if ((*loop)->GetId() == id)
        {
            return *loop;
        }
    }
}
        
DoctorsOffice * Model::GetDoctorsOfficePtr(int id){ // modified to work for linked lists
    list <DoctorsOffice*>::iterator loopD;
    for (loopD = office_ptrs.begin(); loopD != office_ptrs.end(); loopD++)
    {
        if ((*loopD)->GetId() == id)
        {
            return *loopD;
        }
    }
}

HospitalVirusOnly * Model::GetHospitalPtr(int id){ // modified to work for linked lists
    list <HospitalVirusOnly*>::iterator loopH;
    for (loopH = hospital_ptrs.begin(); loopH != hospital_ptrs.end(); loopH++)
    {
        if ((*loopH)->GetId() == id)
        {
            return *loopH;
        }
    }
}

ClassRoom * Model::GetClassRoomPtr(int id){ // modified to work for linked lists
    list <ClassRoom*>::iterator loop;
    for (loop = class_ptrs.begin(); loop != class_ptrs.end(); loop++)
    {
        if ((*loop)->GetId() == id)
        {
            return *loop;
        }
    }
}

bool Model::Update()
{    
    time++;
    cout << "Time: " << time << endl;
    
    bool UpToDateCheck = false;
    
    // Constantly updates active_ptrs
    list <GameObject*>::iterator loopA;
    for (loopA = active_ptrs.begin(); loopA != active_ptrs.end(); loopA++)
    {
        if ((*loopA)->Update())
        {
            UpToDateCheck = true;
        }
    }

    // Checks if all students are infected -> Game lost.
    int num_students_INFECTED = 0;
    list <Student*>::iterator loopS;
    for (loopS = student_ptrs.begin(); loopS != student_ptrs.end(); loopS++)
    {
        if ((*loopS)->IsInfected())
        {
            num_students_INFECTED++;
        }
    }
    if(num_students == num_students_INFECTED)
    {
        ShowStatus();
        cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
        exit(0); //quits the game
    }

    // Checks if all classes passed -> Game won.
    int num_classes_PASSED = 0;
    list <ClassRoom*>::iterator loopC;
    for (loopC = class_ptrs.begin(); loopC != class_ptrs.end(); loopC++)
    {
        if ((*loopC)->passed())
        {
            num_classes_PASSED++;
        }
    }
    if(num_classes == num_classes_PASSED)
    {
        ShowStatus();
        cout << "GAME OVER: You win! All assignments done!" << endl;
        exit(0); //quits the game
    }

    //Spawned virus disrupts the ecosystem (i.e. virus infects the students)
    list <Virus*>::iterator loopV;
    for (loopV = virus_ptrs.begin(); loopV != virus_ptrs.end(); loopV++)
    {
        if ((*loopV)->ShouldBeVisible())
        {
            //Infect students
            list<Student *>::iterator loopS;
            for (loopS = student_ptrs.begin(); loopS != student_ptrs.end(); loopS++)
            {
                // Can only infect visable students
                if ((*loopS)->ShouldBeVisible())
                {
                    (*loopV)->infect(*loopS);
                }
            }
        }
        else if ((*loopV)->get_is_in_student())
        {
            (*loopV)->ChargeKill(); //Reduces # of antibodies in student body
        }     
    }

    list <DensmoreBoss*>::iterator loopDB;
    for (loopDB = densmore_ptrs.begin(); loopDB != densmore_ptrs.end(); loopDB++)
    {
        if ((*loopDB)->VariantMaker(virus_ptrs, num_viruses))
        {
            active_ptrs.push_back(virus_ptrs.back());
            num_viruses++;
            num_objects++;
            UpToDateCheck = true;
        }

        // If a student goes to the DensmoreBoss Virus Spawner location, the amount of antibodies reduces to 5. They still have the chance to reach a hospital to save themselves.
        list<Student *>::iterator loopS;
        for (loopS = student_ptrs.begin(); loopS != student_ptrs.end(); loopS++)
        {
            (*loopDB)->MercyDestroyerStudents(*loopS);
        }
    }
    
    return UpToDateCheck;
}

void Model::ShowStatus() // It outputs the time and outputs the status of all of the GameObjects by calling their ShowStatus() function.
{
    cout << "Time: " << time << endl;
    list <GameObject*>::iterator loopA;
    for (loopA = active_ptrs.begin(); loopA != active_ptrs.end(); loopA++)
    {
        (*loopA)->ShowStatus();
    }
}

void Model::Display()
{
    view.Clear();    

    list <GameObject*>::iterator loopA;
    for (loopA = active_ptrs.begin(); loopA != active_ptrs.end(); loopA++)
    {
        if (!(*loopA)->get_is_in_student())
        {
            view.Plot(*loopA);
        }
    }

    // Removes 'dead' viruses from active pointers
    list <Virus*>::iterator loopV;
    for (loopV = virus_ptrs.begin(); loopV != virus_ptrs.end(); loopV++)
    {
        if ((*loopV)->ShouldBeVisible() == false && (*loopV)->get_is_in_student() == false)
        {
            active_ptrs.remove(*loopV);
        }
    }

    // Removes 'dead' students from active pointers
    list <Student*>::iterator loopS;
    for (loopS = student_ptrs.begin(); loopS != student_ptrs.end(); loopS++)
    {
        if (!(*loopS)->ShouldBeVisible())
        {
            active_ptrs.remove(*loopS);
        }
    } 
    view.Draw();
}


// Creating new objects during program execution
void Model::NewCommand(char type, int in_id, Point2D p1)
{
    if (type == 'v') // Virus
    {
        // Program verifies if this Virus already exists by checking their id
        list <Virus*>::iterator loopV;
        for (loopV = virus_ptrs.begin(); loopV != virus_ptrs.end(); loopV++)
        {
            if ((*loopV)->GetId() == in_id)
            {
                throw Invalid_Input("This virus id is already exists");
                return;
            }
        }
        // Creating new virus object
        cout << "Enter virus name: ";
        string name;
        if (!(cin >> name))
        {
            throw Invalid_Input("Was expecting a string");
        }
        cout << "Virulence: ";
        double virulence;
        if (!(cin >> virulence))
        {
            throw Invalid_Input("Was expecting a double");
        }
        cout << "Resistance: ";
        double resistance;
        if (!(cin >> resistance))
        {
            throw Invalid_Input("Was expecting a double");
        }
        cout << "Energy: ";
        double energy;
        if (!(cin >> energy))
        {
            throw Invalid_Input("Was expecting a double");
        }
        cout << "Is this virus a variant? (1 for yes, 0 for no): ";
        int variant;
        if (!(cin >> variant))
        {
            throw Invalid_Input("Was expecting an integer");
        }
        virus_ptrs.push_back(new Virus(name, virulence, resistance, energy, variant, in_id, p1));
        object_ptrs.push_back(virus_ptrs.back());
        active_ptrs.push_back(virus_ptrs.back());
        num_objects++;
        num_viruses++;
    }
    else if (type == 'h') // Hospital
    {
        // Program verifies if this Hospital already exists by checking their id
        list <HospitalVirusOnly*>::iterator loopH;
        for (loopH = hospital_ptrs.begin(); loopH != hospital_ptrs.end(); loopH++)
        {
            if ((*loopH)->GetId() == in_id)
            {
                throw Invalid_Input("This hospital id is already being used");
                return;
            }
        }
        // Creating new Hospital object
        cout << "Dollar(s) per vaccine: ";
        double cost_per_vaccine;
        if (!(cin >> cost_per_vaccine))
        {
            throw Invalid_Input("Was expecting a double");
        }
        cout << "Vaccine capacity: ";
        unsigned int vaccine_cap;
        if (!(cin >> vaccine_cap))
        {
            throw Invalid_Input("Was expecting an integer");
        }
        hospital_ptrs.push_back(new HospitalVirusOnly(in_id, cost_per_vaccine, vaccine_cap, p1));
        object_ptrs.push_back(hospital_ptrs.back());
        active_ptrs.push_back(hospital_ptrs.back());
        num_objects++;
        num_offices++;
    }
    else if (type == 'd') // DoctorOffice
    {
        // Program verifies if this DoctorOffice already exists by checking their id
        list <DoctorsOffice*>::iterator loopD;
        for (loopD = office_ptrs.begin(); loopD != office_ptrs.end(); loopD++)
        {
            if ((*loopD)->GetId() == in_id)
            {
                throw Invalid_Input("This doctor's office id already exists");
                return;
            }
        }
        // Creating new DoctorOffice object
        cout << "Dollar(s) per vaccine: ";
        double cost_per_vaccine;
        if (!(cin >> cost_per_vaccine))
        {
            throw Invalid_Input("Was expecting a double");
        }
        cout << "Vaccine capacity: ";
        unsigned int vaccine_cap;
        if (!(cin >> vaccine_cap))
        {
            throw Invalid_Input("Was expecting an integer");
        }
        office_ptrs.push_back(new DoctorsOffice(in_id, cost_per_vaccine, vaccine_cap, p1));
        object_ptrs.push_back(office_ptrs.back());
        active_ptrs.push_back(office_ptrs.back());
        num_objects++;
        num_offices++;
    }
    else if (type == 'c') // ClassRoom
    {
        // Program verifies if this ClassRoom already exists by checking their id
        list <ClassRoom*>::iterator loopC;
        for (loopC = class_ptrs.begin(); loopC != class_ptrs.end(); loopC++)
        {
            if ((*loopC)->GetId() == in_id)
            {
                throw Invalid_Input("This class id is already being used.");
            }
        }
        // Creating new class object
        cout << "Maximum number of assignments: ";
        unsigned int num_assignments_max;
        if (!(cin >> num_assignments_max))
        {
            throw Invalid_Input("Was expecting an integer");
        }
        cout << "Antibody cost per assignment: ";
        unsigned int antibody_cost_per_assignment;
        if (!(cin >> antibody_cost_per_assignment))
        {
            throw Invalid_Input("Was expecting an integer");
        }
        cout << "Dollar(s) per assignment: ";
        double dollar_cost_per_assignment;
        if (!(cin >> dollar_cost_per_assignment))
        {
            throw Invalid_Input("Was expecting a double");
        }
        cout << "Credit(s) per assignment: ";
        unsigned int credits_per_assignment;
        if (!(cin >> credits_per_assignment))
        {
            throw Invalid_Input("Was expecting an integer");
        }
        class_ptrs.push_back(new ClassRoom(num_assignments_max, antibody_cost_per_assignment, dollar_cost_per_assignment, credits_per_assignment, in_id, p1));
        object_ptrs.push_back(class_ptrs.back());
        active_ptrs.push_back(class_ptrs.back());
        num_objects++;
        num_classes++;
    }
    else if (type == 's') // Student
    {
        // Program verifies if this student already exists by checking their id
        list <Student*>::iterator loopS;
        for (loopS = student_ptrs.begin(); loopS != student_ptrs.end(); loopS++)
        {
            if ((*loopS)->GetId() == in_id)
            {
                throw Invalid_Input("ERROR: This student already exists. Try again.");
                return;
            }
        }
        // Creating new student object
        string name;
        cout << "Student name: ";
        if (!(cin >> name))
        {
            throw Invalid_Input("Was expecting a string");
        }
        cout << "Speed: ";
        unsigned int speed;
        if (!(cin >> speed))
        {
            throw Invalid_Input("Was expecting an integer");
        }
        student_ptrs.push_back(new Student(name, in_id, 'S', speed, p1));
        object_ptrs.push_back(student_ptrs.back());
        active_ptrs.push_back(student_ptrs.back());
        num_objects++;
        num_students++;
    }
    else
    {
        throw Invalid_Input("Was expecting one of the following types: s (Student) c (ClassRoom) d (DoctorOffice) h (Hospital) v (Virus)");
    }
}