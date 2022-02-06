all: a1

a1: Room.o Date.o Student.o Reservation.o Library.o
	g++ -o a1 a1-global.cc Room.o Date.o Student.o Reservation.o Library.o

Room.o: Room.h Room.cc
	g++ -c Room.cc

Date.o: Date.h Date.cc
	g++ -c Date.cc

Student.o: Student.h Student.cc
	g++ -c Student.cc

Reservation.o: Reservation.h Reservation.cc
	g++ -c Reservation.cc

Library.o: Library.h Library.cc
	g++ -c Library.cc

clean:
	rm -f a1 *.o
