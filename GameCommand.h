// GameCommand.h
/* 
    The GameCommand represents the Controller of the MVC pattern and provides multiple 
    functions that interpret user input in order to perform the appropriate actions. 
*/

#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "Student.h"
#include "Model.h"
#include "GameObject.h"
#include "ClassRoom.h"
// #include "View.h"
#include "DoctorsOffice.h"

extern bool commandLoop;

void DoMoveCommand(Model & model, int student_id, Point2D p1);

void DoMoveToDoctorCommand(Model & model, int student_id, int office_id);

void DoMoveToHospitalCommand(Model & model, int student_id, int hospital_id);

void DoMoveToClassCommand(Model & model, int student_id, int class_id);

void DoStopCommand(Model & model, int student_id);

void DoLearningCommand(Model & model, int student_id, unsigned int assignments);

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs);

void DoRecoverInHospitalCommand(Model& model, int student_id, unsigned int vaccine_needs);

// void DoNewCommand(char, int, Point2D);

void DoExitCommand(Model *model);

// void DoGoCommand(Model& model, View& view);

// void DoRunCommand(Model& model, View& view);

#endif