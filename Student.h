//Student.h

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "HospitalVirusOnly.h"

using namespace std;

enum StudentStates
{ 
    STOPPED = 0, 
    MOVING = 1,
    INFECTED = 2,
    AT_DOCTORS = 3,
    IN_CLASS = 4,
    MOVING_TO_DOCTOR = 5,
    MOVING_TO_CLASS = 6,
    STUDYING_IN_CLASS = 7,
    RECOVERING_ANTIBODIES = 8,
    AT_HOSPITAL = 9,
    RECOVERING_ANTIBODIES_AT_HOSPITAL = 10,
    MOVING_TO_HOSPITAL = 11
};

class Student: virtual public GameObject, DoctorsOffice
{   // Private Members
    double speed;
    bool is_at_doctor;
    bool is_at_hospital;
    bool is_in_class;
    unsigned int antibodies;
    unsigned int credits;
    double dollars;
    unsigned int assignments_to_buy;
    unsigned int vaccines_to_buy;
    string name;
    DoctorsOffice* current_office;
    HospitalVirusOnly* current_hospital;
    ClassRoom* current_class;
    Point2D destination;
    Vector2D delta;

    int virus_qty; // Number of viruses in student

    protected:
        bool UpdateLocation();
        void SetupDestination(Point2D dest);

    public:
        Student();
        Student(char);
        Student(string, int, char, unsigned int, Point2D);
        virtual ~Student();

        void StartMoving(Point2D);
        void StartMovingToClass(ClassRoom*);
        void StartMovingToDoctor(DoctorsOffice*);
        void StartMovingToHospital(HospitalVirusOnly*);
        void StartLearning(unsigned int);
        void StartRecoveringAntibodies(unsigned int);
        void StartRecoveringAntibodiesAtHospital(unsigned int);
        void Stop();
        bool IsInfected();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
       
        void MercyDestroyer(); //if the student is at the location of 'DensmoreBoss' change antibodies to 5 (enough to reach a hospital).
        void IncrementVirusCount();
        void DecrementVirusCount();
        void KillAntibodies(unsigned int);

        string GetName();
};

double GetRandomAmountOfDollars(); //Returns a random number between 0.0 and 2.0 inclusive.

#endif
