# pa-4

Use the make file to compile.
This is the continuation of PA3.

# Step-1 / Extra-credit
For Step 1 of this assignment, I decided to implement methods 1 and 4.

For extra-credit, I added two new classes, DensmoreBoss and HospitalVirusOnly. DensmoreBoss acts as a virus spawner which originates from one location only (20,20) and spreads to 4 possible destinations: 
    • (0,20) -> Left
    • (0,0) -> Diagonal
    • (20,0) -> Down
    • (0,10) -> Half y-axis
    • (10,0) -> Half x-axis

However, the DensmoreBoss spawner does not always spawn a new virus. There is a 50% chance that it will spawn a new virus every new tick. When DensmoreBoss decides to spawn a new virus, there is a 50% chance that it will either spawn a COVID variant or an OmiCron variant. The OmiCron variant is twice as strong as the COVID variant. Below are their specifications:

    COVID:
        • Virulence = 30
        • Resistance = 10
        • Energy = 10
    
    OmiCron:
        • Virulence = 60
        • Resistance = 20
        • Energy = 20

Everytime a new virus is spawned into the environment, the ShowStatus() function tells the user if how many COVID/OmiCron variants are in the environment. Lastly, if the user decides to go to the DensmoreBoss spawner location (20,20), the user's number of antibodies reduces to 5 (if it is above 5 antibodies originally). By making it 5, we are giving a chance for the user to go to a hospital (5 blocks away) and recover from a hospital vaccine.

Next, I implemented two new Hospitals to the game, H1 and H2. Only students that have a Virus inside their body can buy a vaccine from the hospital. The cost for each vaccine is $15; it is expensive, but one single vaccine removes the virus from the student's body and recovers 20 antibodies to the student. Further, the student is not allowed to buy more than 1 vaccine at once.

Some extra commands I added to the GameCommands.cpp file (extra-credit) are:
    • h - works the same way as 'd'
    • e - works the same way as 'v', but only for hospital vaccines