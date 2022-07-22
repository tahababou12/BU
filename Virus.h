//Virus.h

#ifndef VIRUS_H
#define VIRUS_H

enum VirusStates { 
    IN_ENVIRONMENT = 0, 
    DEAD = 1,
    IN_STUDENT = 2
};

class Virus : public GameObject
{
    protected:
        double virulence; // Initial value is 5
        double resistance; // Initial value is 2
        bool variant; // Initial value is false --> For extra credit you could actually make a derived class of Virus
        void DeltaSetup();
        double energy; // Initial value is 10
        Vector2D delta;
        bool is_in_student; // Returns true if the virus is inside a Student --> Default is false
        string name;
        Student * current_student; // Holds the current student it is infecting
        Point2D destination;
        double speed;
        bool UpdateLocation(); // verifies if the virus and student are in the same location.
    public:
        // Constructor
        Virus(string name, double virulence, double resistance, double energy, bool variant, int id, Point2D in_loc);
        
        // Destructor
        virtual ~Virus();
        
        void infect(Student*); // Virus enters the student's body
        void ChargeKill(); // Reduces antibodies in student's body
        bool get_variant(); // Return variant
        double get_virulence(); // Return virulence
        double get_resistance(); // Return resistance
        double get_energy(); // Return energy
        bool get_is_in_student(); // Returns is_in_student;
        string get_name(); // Gets name
        bool Update();
        void ShowStatus(); /* It outputs something like "Virus status:", then functions similar to
                            Student::show_status() where it calls Game_Object::show_status and that outputs state specific information, 
                            for example if the Virus is alive or not alive. Staff can provide specific details via demo video or on request.
                           */
        bool IsAlive(); // Check the energy of a virus and returns true if it is alive
        bool ShouldBeVisible(); // Makes sure the virus did not leave the environment -> state = IN_ENVIRONMENT
};








#endif