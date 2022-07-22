// *** MUST COMPILE WITH g++ -std=c++11
// SHORTCUT TO COMPILE EVERYTHING: g++ -std=c++11 main.cpp GameCommand.cpp Model.cpp DensmoreBoss.cpp View.cpp HospitalVirusOnly.cpp Virus.cpp Student.cpp DoctorsOffice.cpp ClassRoom.cpp Building.cpp GameObject.cpp Vector2D.cpp Point2D.cpp

#include <iostream>
#include <string.h>
#include <list>

#include "Vector2D.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"
#include "Virus.h"
#include "HospitalVirusOnly.h"
#include "View.h"
#include "DensmoreBoss.h"
#include "Model.h"
#include "GameCommand.h"
#include "Input_Handling.h"

using namespace std;

/*
    The main program should include a loop that reads a command, executes 
    it, and then asks for another command. You do NOT have to detect 
    errors or bad input. PA4 will add these features. The program will 
    declare two Student objects, two DoctorsOffice objects, and two 
    ClassRoom objects as outlined in the Model class description. 
    These objects will persist throughout the execution of the program.
*/

string *separateCommands(string user_input, int &amount)
{
    string *output = new string[5];

    string str = "";
    for (auto n : user_input)
    {
        if (amount == 5)
        {
            throw Invalid_Input("ERROR: Please enter valid command!");
            return 0;
        }

        if (n == ' ')
        {
            output[amount] = str;
            str = "";
            amount++;
        }
        else
        {
            str = str + n;
        }
    }
    output[amount] = str;

    return output;
}

string *separateCommands(string, int &);

bool commandLoop = true;

int main()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2021" << endl;
    cout << "Programming Assignment 4" << endl;

    cout << " _______  _______          _________ ______" << endl;  
    cout << "(  ____ \\(  ___  )|\\     /|\\__   __/(  __  \\" << endl; 
    cout << "| (    \\/| (   ) || )   ( |   ) (   | (  \\  )" << endl;
    cout << "| |      | |   | || |   | |   | |   | |   ) |" << endl;
    cout << "| |      | |   | |( (   ) )   | |   | |   | |" << endl;
    cout << "| |      | |   | | \\ \\_/ /    | |   | |   ) |" << endl;
    cout << "| (____/\\| (___) |  \\   /  ___) (___| (__/  )" << endl;
    cout << "(_______/(_______)   \\_/   \\_______/(______/ " << endl;
    cout << endl;
    cout << " ______   _______  _______  _______  _        _______          _________" << endl;
    cout << "(  ___ \\ (  ____ )(  ____ \\(  ___  )| \\    /\\(  ___  )|\\     /|\\__   __/" << endl;
    cout << "| (   ) )| (    )|| (    \\/| (   ) ||  \\  / /| (   ) || )   ( |   ) (   " << endl;
    cout << "| (__/ / | (____)|| (__    | (___) ||  (_/ / | |   | || |   | |   | |   " << endl;
    cout << "|  __ (  |     __)|  __)   |  ___  ||   _ (  | |   | || |   | |   | |   " << endl;
    cout << "| (  \\ \\ | (\\ (   | (      | (   ) ||  ( \\ \\ | |   | || |   | |   | |   " << endl;
    cout << "| )___) )| ) \\ \\__| (____/\\| )   ( ||  /  \\ \\| (___) || (___) |   | |   " << endl;
    cout << "|/ \\___/ |/   \\__/(_______/|/     \\||_/    \\/(_______)(_______)   )_(   " << endl;
    cout << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    Model *model = new Model;
    model->ShowStatus();
    model->Display();

    do
    {
        string user_input;
        cout << endl << "Enter command: ";
        getline(cin, user_input);

        try
        {
            int command_number = 0;
            string *commands = separateCommands(user_input, command_number);
            if (commands == 0)
            {
                continue;
            }
            switch (commands[0][0])
            {
            case 'm':
                if (command_number != 3)
                {
                    throw Invalid_Input("Was expecting 3 arguments.");
                    break;
                }
                DoMoveCommand(*model, stoi(commands[1]), Point2D(stod(commands[2]), stod(commands[3])));
                model->Update();
                model->Display();
                break;

            case 'd':
                if (command_number != 2)
                {
                    throw Invalid_Input("Was expecting 2 arguments.");
                    break;
                }
                DoMoveToDoctorCommand(*model, stoi(commands[1]), stoi(commands[2]));
                model->Update();
                model->ShowStatus();
                model->Display();
                break;

            case 'h':
                if (command_number != 2)
                {
                    throw Invalid_Input("Was expecting 2 arguments.");
                    break;
                }
                DoMoveToHospitalCommand(*model, stoi(commands[1]), stoi(commands[2]));
                model->Update();
                model->ShowStatus();
                model->Display();
                break;

            case 'c':
                if (command_number != 2)
                {
                    throw Invalid_Input("Was expecting 2 arguments.");
                    break;
                }
                DoMoveToClassCommand(*model, stoi(commands[1]), stoi(commands[2]));
                model->Update();
            // model->ShowStatus();
            model->Display();
                break;

            case 's':
                if (command_number != 1)
                {
                    throw Invalid_Input("Was expecting 1 argument.");
                    break;
                }
                DoStopCommand(*model, stoi(commands[1]));
                model->Update();
                model->ShowStatus();
                break;

            case 'v':
                if (command_number != 2)
                {
                    throw Invalid_Input("Was expecting 2 arguments.");
                    break;
                }
                DoRecoverInOfficeCommand(*model, stoi(commands[1]), stoi(commands[2]));
                model->Update();
                model->ShowStatus();
                model->Display();
                break;

            case 'e': //'e' for eliminate (virus) command to recover vaccines in hospital only if student has a virus
                if (command_number != 2)
                {
                    throw Invalid_Input("Was expecting 2 arguments.");
                    break;
                }
                DoRecoverInHospitalCommand(*model, stoi(commands[1]), stoi(commands[2]));
                model->Update();
                model->ShowStatus();
                model->Display();
                break;

            case 'a':
                if (command_number != 2)
                {
                    throw Invalid_Input("Was expecting 2 arguments.");
                    break;
                }
                DoLearningCommand(*model, stoi(commands[1]), stoi(commands[2]));
                model->Update();
                break;

            case 'g':
                if (command_number != 0)
                {
                    throw Invalid_Input("Was expecting no arguments");
                    break;
                }
                cout << "Advancing one tick." << endl;
                model->Update();
                model->ShowStatus();
                model->Display();
                break;

            case 'r':
                if (command_number != 0)
                {
                    throw Invalid_Input("Was expecting no arguments");
                    break;
                }
                cout << "Advancing to the next event" << endl;
                for (int i = 0; i < 5; i++)
                {
                    if (model->Update())
                    {
                        break;
                    }
                }
                model->Update();
                model->ShowStatus();
                model->Display();
                break;

            case 'n':
                if (command_number != 4)
                {
                    throw Invalid_Input("Was expecting 4 arguments");
                    break;
                }
                model->NewCommand(commands[1][0], stoi(commands[2]), Point2D(stod(commands[3]), stod(commands[4])));
                model->Update();
                model->ShowStatus();
                model->Display();
                break;

            case 'q':
                if (command_number != 0)
                {
                    throw Invalid_Input("Was expecting no arguments");
                    break;
                }
                DoExitCommand(model);
                return 0;
                break;

            default:
                break;
            }
            cin.clear();
        }
        catch(Invalid_Input& except)
        {
            cout << "Invalid input: " << except.msg_ptr << endl;
        }
    } while (commandLoop);

    return 0;
}
