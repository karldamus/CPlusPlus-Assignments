### COMP2406 (Software Engineering) Assignment 1
Karl Damus
- - -
### Compiling and Running
1. Open terminal to Root folder ("Assignment 1")
2. Run `make clean` (optional)
3. Run `make`
4. Run `./a1`
- - -
### File List / Dependency Hierarchy:
  a1-global.cc (main)
  |-- Library.cc Library.h
  |--|-- Reservation.cc Reservation.h
  |--|--|-- Date.cc Date.h
  |--|--|-- Room.cc Room.h
  |--|--|-- Student.cc Student.h

- - -
### Classes

##### Library
A collection of `Student`, `Room`, and `Reservation` object arrays

- See also `Reservation`, `Student`, `Room`, and `Date`

##### Reservation
A `Student`, `Room`, and `Date` object representing the who, where, and when of a `Reservation`

- See also `Library`

##### Student 
The name and student number of a `Student`

- See also `Reservation` and `Library`

##### Room
A single room with certain features: room name, max capacity, number of computers, and if it has a whiteboard

We can determine (using the `meetsCriteria` method) whether a Room meets the given criteria based on it's features

The default values are given as: `capacity=1`, `numComputers=0`, `hasWhiteboard=false`

- See also `Reservation`, `Library`, and `Date`

##### Date
A single Date which stores: year, month, day, hour, and duration

Used along the Reservation class to create a booking in a Room for a given time, place, and give the Reservation a fixed duration

We can determine (using the `overlaps` method) if two dates overlap (aka clash)

- See also `Reservation`, `Library`, and `Room`

- - -
##### Main (a1-global)
This c++ file tests our class structure and implementation. 

Test methods:
- `testDate`
- `populate`
- `testReservations`

In our main method, there are 10 Date objects implemented to test using the `testDate` method

There is then a Library object implemented which is populated using the `populate` method and Reservation objects are added / tested within the instantiated Library object using the `testReservations` method

- - -
##### Makefile / Usage
Each Class file is compiled into Object files and the executable (a1) is created from the source code in a1-global.cc and implements its methods and constructors from all of the individual classes

To add more tests, see the main method inside a1-global to see how the tests are laid out.
