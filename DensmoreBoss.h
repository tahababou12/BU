// DensmoreBoss.h is the header file that allows the computer to spawn viruses at a specific location.

#ifndef DENSMOREBOSS_H
#define DENSMOREBOSS_H
#include <list>
#include "Virus.h"
class DensmoreBoss:public GameObject
{
    protected:
        int COVIDVariantInEnvironment; //number of COVID variants in environment
        int OMICRONVariantInEnvironment; //number of OMICRON variants in environment


    public:
        //Constructor
        DensmoreBoss(char, int, Point2D);
        
        //Deconstructor
        virtual ~DensmoreBoss();

        void MercyDestroyerStudents(Student *); // Reduces the student's antibodies to 5. (Enough to reach a hospital)
        bool VariantMaker(list <Virus*> &, int &); // Virus spawner
        void ShowStatus();        



};





#endif