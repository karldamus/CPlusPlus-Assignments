// Author: Darryl Hill (Prof)
// Author: Karl Damus

#include "Date.h"

#include <cmath>

// constructors
Date::Date(int year, int month, int day, int hour, int duration){
	setDate(year, month, day, hour, duration);
}

Date::Date(Date& d){
	setDate(d.year,d.month,d.day,d.hour,d.duration);
}

// deconstructor
Date::~Date() {
	// free(year);
	// free(month);
	// free(day);
	// free(hour);
	// free(duration);
}


// setters
void Date::setDay(int d){
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	if (y < 1901) y = 1901;
	year = y;
}

void Date::setHour(int h) {
    if (h < 0)
        h = 0;
    if (h > 23)
        h = 23;
    hour = h;
}

void Date::setDuration(int d) {
    if (d < 1)
        d = 1;
    if (d > maxAllowedDuration)
        d = maxAllowedDuration;

    duration = d;
}

void Date::setDate(int year, int month, int day, int hour, int duration){
		setMonth(month);
		setDay(day);
		setYear(year);
    setHour(hour);
    setDuration(duration);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day, d.hour, d.duration);
}


// getters
int Date::getDay(){ return day; }
int Date::getMonth(){ return month; }
int Date::getYear(){ return year; }
int Date::getHour() { return hour; }
int Date::getDuration() { return duration; }
string Date::getMonthName(){
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};

	return months[month-1];
}

// other

bool Date::lessThan(Date& d){
	if (year < d.year) return true;
	if (year > d.year) return false;
	//if years are equal
	if (month < d.month) return true;
	if (month > d.month) return false;
	//if months are equal
    if (day < d.day) return true;
    if (day > d.day) return true;
    // if days are equal
    return (hour < d.hour);
}

bool Date::overlaps(Date &d) {
    if (year != d.year) return false;
    if (month != d.month) return false;
    if (day != d.day) return false;

    // events are at the same time, day, month, & year
    if (hour == d.hour) return true;

    // this event is before d
    if (hour < d.hour) {
        if ((hour + duration) > d.hour)
            return true;
    }

    // d event is before this
    if (d.hour < hour) {
        if ((d.hour + d.duration) > hour)
            return true;
    }

    // events do not overlap
    return false;
}


void Date::print(){
	cout << getMonthName()<<" "<<getDay()<<", "<<getYear() << " | " << getHour() << ":00 -- " << getDuration() << " hours" <<endl;
}


int Date::getMaxDay(){
	switch(getMonth()){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}
