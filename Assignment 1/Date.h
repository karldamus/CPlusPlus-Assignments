// Author: Darryl Hill (Prof)
// Author: Karl Damus

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

const int maxAllowedDuration = 3;

class Date {

	public:
		//constructor
		Date(int year = 1901, int month = 1, int day = 1, int hour = 0, int duration = 1);
		Date(Date&);
		~Date();

		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setHour(int);
		void setDuration(int);
		void setDate(int, int, int, int, int);
		void setDate(Date&);

		//getters
		int getDay();
		int getMonth();
		int getYear();
		int getHour();
		int getDuration();
		string getMonthName();

		//other
		bool lessThan(Date& d);
		bool overlaps(Date &d);
		void print();

	private:
		//functions
		int getMaxDay();

		//variables
		int day;
		int month;
		int year;
		int hour;
		int duration;

};
#endif
