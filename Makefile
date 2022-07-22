CC=g++ -g

OBJS=main.o Building.o Point2D.o Vector2D.o GameObject.o HospitalVirusOnly.o GameCommand.o DoctorsOffice.o Model.o Student.o ClassRoom.o View.o Virus.o DensmoreBoss.o

default: PA4

PA4: $(OBJS)
	$(CC) -o PA4 $(OBJS) 

Vector2D.o: Vector2D.cpp Vector2D.h
	$(CC) -c Vector2D.cpp -o Vector2D.o 
	
Point2D.o: Point2D.cpp Point2D.h Vector2D.h
	$(CC) -c Point2D.cpp -o Point2D.o 

Building.o: Building.cpp Building.h
	$(CC) -c Building.cpp -o Building.o

GameObject.o: GameObject.cpp GameObject.h Point2D.h Vector2D.h
	$(CC) -c GameObject.cpp -o GameObject.o 

DoctorsOffice.o: DoctorsOffice.cpp DoctorsOffice.h GameObject.h Point2D.h
	$(CC) -c DoctorsOffice.cpp -o DoctorsOffice.o

Virus.o: Virus.cpp Virus.h 
	$(CC) -c Virus.cpp -o Virus.o

HospitalVirusOnly.o: HospitalVirusOnly.cpp HospitalVirusOnly.h Virus.h
	$(CC) -c HospitalVirusOnly.cpp -o HospitalVirusOnly.o

Model.o: Model.cpp Model.h GameObject.h Student.h ClassRoom.h DoctorsOffice.h View.h HospitalVirusOnly.h
	$(CC) -c Model.cpp -o Model.o 

ClassRoom.o: ClassRoom.cpp ClassRoom.h GameObject.h Point2D.h
	$(CC) -c ClassRoom.cpp -o ClassRoom.o

View.o: View.cpp View.h GameObject.h Point2D.h
	$(CC) -c View.cpp -o View.o 

Student.o: Student.cpp Student.h GameObject.h Point2D.h Vector2D.h DoctorsOffice.h ClassRoom.h HospitalVirusOnly.h
	$(CC) -c Student.cpp -o Student.o

GameCommand.o: GameCommand.cpp GameCommand.h Model.h GameObject.h Student.h ClassRoom.h HospitalVirusOnly.h DoctorsOffice.h
	$(CC) -c GameCommand.cpp -o GameCommand.o

DensmoreBoss.o: DensmoreBoss.cpp DensmoreBoss.h Virus.h
	$(CC) -c DensmoreBoss.cpp -o DensmoreBoss.o
	
main.o: main.cpp Building.h Point2D.h Vector2D.h HospitalVirusOnly.h GameCommand.h DoctorsOffice.h HospitalVirusOnly.h Model.h Student.h ClassRoom.h GameObject.h View.h
	$(CC) -c main.cpp -o main.o

clean: 
	rm $(OBJS) PA4 *.exe

