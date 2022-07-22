//Model.h

#ifndef MODEL_H
#define MODEL_H

#include <list>
#include "DensmoreBoss.h"
#include "Virus.h"
#include "View.h"

class Model
{   //private members
    private:
        int time; // the simulation time

        list<GameObject *> object_ptrs;
        list<GameObject *> active_ptrs; 
        int num_objects;
        
        list<Student *> student_ptrs;
        int num_students;
        
        list<ClassRoom *> class_ptrs;
        int num_classes;

        list<DoctorsOffice *> office_ptrs;
        int num_offices;

        list<HospitalVirusOnly *> hospital_ptrs;
        int num_hospital;
        
        list<DensmoreBoss *> densmore_ptrs;
        int num_densmore;
        
        list<Virus *> virus_ptrs;
        int num_viruses;

        View view;
    
    public:
        Model();
        ~Model();
        Student* GetStudentPtr(int);
        DoctorsOffice* GetDoctorsOfficePtr(int);
        HospitalVirusOnly* GetHospitalPtr(int);
        ClassRoom* GetClassRoomPtr(int id);
        void ShowStatus();
        void Display();
        bool Update();
        void NewCommand(char, int, Point2D);
};

#endif