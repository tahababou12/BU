//GameObject.h

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "Vector2D.h"
#include "Point2D.h"

using namespace std;
 
class GameObject
{
    protected:
        Point2D location; // The location of the object
        int id_num; // This object’s ID
        char display_code; // How the object is represented in the View.
        char state; // State of the object; more information provided in each derived class.
    
    public:        
        GameObject(char); // Initializes the display_code to in_code, id_num to 1, and state to 0. It outputs the message: “GameObject constructed”.
       
        GameObject(Point2D, int, char); // Initializes the display_ code, id_num, and location. The state should be 0. It outputs the message: “GameObject constructed”.
       
        virtual ~GameObject();

        Point2D GetLocation(); // Returns the location for this object.
       
        int GetId(); // Returns the id for this object.
       
        char GetState(); // Returns the state for this object.
       
        virtual void ShowStatus(); // Outputs the information contained in this class: display_code, id_num, location.

        void DrawSelf(char * ptr);

        virtual bool Update();
        
        virtual bool ShouldBeVisible();

        virtual bool get_is_in_student();

};

#endif
