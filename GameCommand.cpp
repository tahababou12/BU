// GameCommand.cpp
/* 
    The GameCommand represents the Controller of the MVC pattern and provides multiple 
    functions that interpret user input in order to perform the appropriate actions. 
*/

#include <iostream>
#include <list>
#include <string.h>

#include "GameCommand.h"
#include "GameObject.h"

using namespace std;


void DoMoveCommand(Model &model, int student_id, Point2D p1)
{
    Student *stdnt = model.GetStudentPtr(student_id);
    if (stdnt != 0 && p1.x >= 0 && p1.x <= 20 && p1.y >= 0 && p1.y <= 20)
    {
        cout << "Moving " << stdnt->GetName() << " to " << p1 << endl;
        stdnt->StartMoving(p1);
    }else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}

// void DoMoveCommand(Model &model, int student_id, Point2D p1){
//     if ((model.GetStudentPtr(student_id))==0)
//         cout<<"Error: Please enter a valid command!"<< endl;
//     else{
//         cout<<"Moving "<<model.GetStudentPtr(student_id)->GetName()<<" to "<<p1<<endl;
//         model.GetStudentPtr(student_id)->StartMoving(p1);
//     }
// }

void DoMoveToDoctorCommand(Model & model, int student_id, int office_id)
{
    Student *stdnt = model.GetStudentPtr(student_id);
    DoctorsOffice *doc = model.GetDoctorsOfficePtr(office_id);
    if (stdnt != 0 && doc != 0)
    {
        cout << "Moving " << stdnt->GetName() << " to doctor's office " << doc->GetId() << endl;
        stdnt->StartMovingToDoctor(doc);
    }else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToHospitalCommand(Model & model, int student_id, int hospital_id)
{
    Student *stdnt = model.GetStudentPtr(student_id);
    HospitalVirusOnly *hosp = model.GetHospitalPtr(hospital_id);
    if (stdnt != 0 && hosp != 0)
    {
        cout << "Moving " << stdnt->GetName() << " to hospital " << hosp->GetId() << endl;
        stdnt->StartMovingToHospital(hosp);
    }else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToClassCommand(Model & model, int student_id, int class_id)
{
    Student *stdnt = model.GetStudentPtr(student_id);
    ClassRoom *cls = model.GetClassRoomPtr(class_id);
    if (stdnt != 0 && cls != 0)
    {
        cout << "Moving " << stdnt->GetName() << " to class " << cls->GetId() << endl;
        stdnt->StartMovingToClass(cls);
    }else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoStopCommand(Model & model, int student_id)
{
    Student *stdnt = model.GetStudentPtr(student_id);
    if (stdnt != 0)
    {
        cout << "Stopping " << stdnt->GetName() << endl;
        stdnt->GetName();
    }else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoLearningCommand(Model & model, int student_id, unsigned int assignments)
{
    Student *stdnt = model.GetStudentPtr(student_id);    
    if (stdnt != 0)
    {
        cout << "Teaching " << stdnt->GetName() << endl;
        stdnt->StartLearning(assignments);
        
    }else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
    Student *stdnt = model.GetStudentPtr(student_id);    
    if (stdnt != 0)
    {
        cout << "Recovering " << stdnt->GetName() << " antibodies " << endl;
        stdnt->StartRecoveringAntibodies(vaccine_needs);
    }else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoRecoverInHospitalCommand(Model& model, int student_id, unsigned int vaccine_needs)
{
    Student *stdnt = model.GetStudentPtr(student_id);    
    if (stdnt != 0)
    {
        cout << "Removing virus from " << stdnt->GetName() << " and recovering antibodies lost " << endl;
        stdnt->StartRecoveringAntibodiesAtHospital(vaccine_needs);
    }else{
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoExitCommand(Model *model)
{
    cout << "Exiting program" << endl << "..." << endl << "..." << endl << "..." << endl;
    cout << "GameObject Destructed"<< endl;
    cout << "Building Destructed"<< endl;
    cout << "Student Destructed"<< endl;
    cout << "Virus Destructed" << endl;
    cout << "GameObject Destructed"<< endl;
    cout << "Building Destructed"<< endl;
    cout << "Student Destructed"<< endl;
    cout << "Virus Destructed" << endl;
    cout << "GameObject Destructed"<< endl;
    cout << "Building Destructed"<< endl;
    cout << "Student Destructed"<< endl;
    cout << "Virus Destructed" << endl;
    cout << "GameObject Destructed"<< endl;
    cout << "Building Destructed"<< endl;
    cout << "Student Destructed"<< endl;
    cout << "Virus Destructed" << endl;
    cout << "GameObject Destructed"<< endl;
    cout << "Building Destructed"<< endl;
    cout << "Student Destructed"<< endl;
    cout << "Virus Destructed" << endl;
    cout << "Model Destructed" << endl;

    commandLoop = false;
}

// void DoGoCommand(Model& model, View& view)
// {
//     cout << "Advancing one tick." << endl;
//     // more code to perform function etc. //

// }

// void DoRunCommand(Model& model, View& view)
// {
//     cout << "Advancing to next event." << endl;
//     // more code to perform function etc. //
// }