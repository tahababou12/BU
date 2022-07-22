//GameObject.cpp

#include <iostream>
#include "GameObject.h"
using namespace std;

GameObject::GameObject(char in_code)
{
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout << "GameObject Constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    state = 0;
    id_num = in_id;
    display_code = in_code;
    location = in_loc;
    cout << "GameObject Constructed" << endl;
}

GameObject::~GameObject()
{
    cout << "GameObject Destructed" << endl;
}

Point2D GameObject::GetLocation()
{
    return location;
}

int GameObject::GetId()
{
    return id_num;
}

char GameObject::GetState()
{
    return state;
}

void GameObject::ShowStatus()
{
    cout << display_code << id_num << " located at " << location;//<< endl;
}

 void GameObject::DrawSelf(char * ptr)
 {
     /*
         The function puts the display_code at the character pointed
         to by ptr, and then the ASCII character for the id_num in 
         the next character.
     */
    *ptr = display_code;
    *(ptr+1) = '0' + id_num;
 }

bool GameObject::Update()
{
    /*
        The default behavior is to do nothing.
    */

    return false;
}

bool GameObject::ShouldBeVisible()
{
    /*
        The default behavior is to return true.
    */
    return true;
}

bool GameObject::get_is_in_student()
{
    return false;
}