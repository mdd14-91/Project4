#include "Date_Header.h"
#include <sstream>
#include <iostream>
using namespace std;


//Date-Constructor
//inputs=values for the month, day, and year.
//output=none
//preconditions=none. 
//postcondition=The date is stored as three integers using the values
//for month, day, and year passed in as parameters.
Date::Date(int m, int d, int y) {

    setDate(m, d, y);
}

//setDate-This function sets the date making sure that the month integer 
//is between 1 and 12, that the day integer is between 1 and the 
//last day of the month as is correct for that month, and the year
//is a positive integer.
//inputs=positive integers for the month, day and year
//output=none
//preconditions=the date must first be created by the constructor
//postcondition=if the inputs for month, day, and year are all valid,
//the date is stored; otherwise, a brief error message is printed 
//and the default date of 1/1/1900 is stored.
void Date::setDate(int m, int d, int y) {

    if (m < 1 || m > 12) {
        cout << "Month invalid";
        month = 1;
        day = 1;
        year = 1900;
    }
    else if (d < 1 || d > getLastDay(m, y)) {
        cout << "Day invalid";
        month = 1;
        day = 1;
        year = 1900;
    }
    else if (y < 1) {
        cout << "Year invalid";
        month = 1;
        day = 1;
        year = 1900;
    }
    else {
        month = m;
        day = d;
        year = y;
    }
}



// overloaded isLeapYear function-Evaluates if the input year is a leap year.
//inputs=year to be evaluated
//output=returns true if the input year is a leap year, false otherwise.
//preconditions=the date must first be created by the constructor.
//postcondition=true or false is returned, depending if the input year is a leap year.
bool Date::isLeapYear(int y) {

    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
}

//getLastday(int m,y) function-Returns the last day of the month of the input date.
//inputs=the month and year for which the last day of the month 
//should be determined.
//output=none
//preconditions=the date must first be created by one of the constructors,
//(except if the contructor is using this function).
//postcondition=the last day of the month is returned.
int Date::getLastDay(int m, int y) {

    if (m == 2) {
        if (isLeapYear(y))
            return 29;
        else
            return 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

//printDate function-This member function prints the date in the following form: 12/25/2021
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the date is printed to the returned string.
string Date::printDate1() {
    ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}

//printDate2 function-This member function prints the date in the following form: December 25, 2021 
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the date is printed to the returned string.
std::string Date::printDate2() {
    const std::string months[] = { "January", "February", "March", "April", "May", "June",
                                   "July", "August", "September", "October", "November", "December" };
    std::ostringstream oss;
    oss << months[month - 1] << " " << day << ", " << year;
    return oss.str();
}

//printDate3 function-This member function prints the date in the following form: 25 December 2021
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the date is printed to the returned string.
std::string Date::printDate3() {
    const std::string months[] = { "January", "February", "March", "April", "May", "June",
                                   "July", "August", "September", "October", "November", "December" };
    std::ostringstream oss;
    oss << day << " " << months[month - 1] << " " << year;
    return oss.str();
}

//Prefix increment operator. This operator increments the object’s day member. 
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the day is incremented by one, and as necessary, the month
//and year.
Date& Date::operator++() {
    ++day;
    if (day > getLastDay()) {
        //we just entered a new month
        if (month == 12) { //and a new year
            day = 1;
            month = 1;
            year = year + 1;
        }
        else {
            day = 1;
            month = month + 1;
        }
    }
    return *this;
}

//Postfix increment operator. This operator increments the object’s day member. 
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the day is incremented by one, and as necessary, the month
//and year.
Date Date::operator++(int) {
    Date temp = *this;
    day++;
    if (day > getLastDay()) {
        // entered a new month
        if (month == 12) { //and a new year
            day = 1;
            month = 1;
            year = year + 1;
        }
        else {
            day = 1;
            month = month + 1;
        }
    }
    return temp;
}

//Prefix decrement operator,  This operator decrements the object’s day member. 
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the day is decremented by one, and as necessary the month
//and year.
Date& Date::operator--() {
    --day;
    if (day == 0) {
        //we just entered the previous month
        if (month == 1) { //and the previous year
            day = 31;
            month = 12;
            year = year - 1;
        }
        else {
            month = month - 1;
            day = getLastDay();
        }
    }
    return *this;
}

//Postfix decrement operator. This operator decrements the object’s day member. 
//inputs=none
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the day has been decremented by one, and as necessary, the month
//and year.
Date Date::operator--(int) {
    Date temp = *this;
    day--;
    if (day == 0) {
        //we just entered the previous month
        if (month == 1) { //and the previous year
            day = 31;
            month = 12;
            year = year - 1;
        }
        else {
            month = month - 1;
            day = getLastDay();
        }
    }
    return temp;
}

//TotalDays-Calculates the number of days since 1/1/1 to the input date, which is
//the earliest day this class will store. This function is only
//used in the subtraction operator; it is not
//declared publicly.
//inputs=m, d, and y, month, day, and year, respectively, all int values.
//output=the number of days since 1/1/1 to the input date.
//preconditions=the date must first be created by the constructor.
//postcondition=the total number of days is returned.
int Date::totalDays(int m, int d, int y) {

    Date tempDate(m, d, y);
    int totalDays = 0;

    //array of cumulative days by month
    int cumDays[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

    //first, count the number of days in the input date's year:
    totalDays = cumDays[m - 1] + d;
    if (Date::isLeapYear(y))
        totalDays++;

    // add the right number of days for each year prior to the
    //input date's year:
    for (int i = 1; i < y; i++) {
        totalDays = totalDays + 365;
        if (isLeapYear(i))
            totalDays++;
    }

    return totalDays;
}

//Overloaded subtraction operator for Date - Date.
//Basically, calculate the total days since the first possible
//date for each year, then subtract the two to obtain the number
//of days.
//inputs=the second date.
//output=the difference between the dates in days.
//preconditions=the date must first be created by the constructor.
//postcondition=the difference in days is returned.
int Date::operator-(Date& second) {

    int firstDateTotal = totalDays(month, day, year);
    int secondDateTotal = totalDays(second.getMonth(), second.getDay(), second.getYear());

    return abs(secondDateTotal - firstDateTotal);
}

//cout’s stream insertion operator
//inputs=a date object
//output=none
//preconditions=the date must first be created by the constructor.
//postcondition=the date is inserted in the ostream (printed out)
ostream& operator<<(ostream& out, Date& d) {
    out << d.printDate2();
    return out;
}

//cin’s stream extraction operator
//inputs=none
//output=the date input using this overloaded operator and error message if needed
//preconditions=the date must first be created by the constructor and be valid.
//postcondition=the date is input, error message output if invalid date is entered
istream& operator>>(istream& input, Date& d) {
    int newDay = 0;
    int newMonth = 0;
    int newYear = 0;

    cout << "Enter month: ";
    input >> newMonth;
    cout << "Enter day: ";
    input >> newDay;
    cout << "Enter year: ";
    input >> newYear;

    //Let setDate() do all our error checking.
    d.setDate(newMonth, newDay, newYear);

    return input;
}