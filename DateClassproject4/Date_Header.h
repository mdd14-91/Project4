#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <cstdlib> //for abs()
using namespace std;

//class description- The class stores a date in three integers : month, day, and year. 
//There are member functions to set the date, and to print it in three forms. In addition,
//there are operators to increment and decrement the date, subtract two dates,
//and work with cout/cin to insert/extract dates to/from the iostreams.
class Date {
private:

    //Class member variables:
    int day;
    int month;
    int year;

    //Class private function:

    //Calculates the number of days since 1/1/1 to the input date, which is
    //the earliest day this class will store. 
    int totalDays(int m, int d, int y);

public:

    Date(int m = 1, int d = 1, int y = 1900); //Constructor

    void setDate(int m, int d, int y); //Set date function

    //GetMonth function-Returns the month of the date.
    //inputs=none
    //output=the month, in integer format (1 to 12)
    //preconditions=the date must first be created by the constructor.
    //postcondition=the month of the stored date is returned.
    int getMonth() { return month; } 

    //GetDay function - Returns the day of the date.
    //inputs=none
    //output=the day, in integer format (1 to 28, 29, 30, or 31, depending on the month)
    //preconditions=the date must first be created by the constructor.
    //postcondition=the day of the stored date is returned.
    int getDay() { return day; } 

    //GetYear function-Returns the year of the date.
    //inputs=none
    //output=the year, in positive integer format
    //preconditions=the date must first be created by the constructor.
    //postcondition=the year of the stored date is returned.
    int getYear() { return year; } 

    //isLeapYear function-Evaluates if the stored year is a leap year.
    //inputs=none
    //output=returns true if the year in the stored date is a leap year, false otherwise.
    //preconditions=the date must first be created by the constructor.
    //postcondition=true or false is returned, depending if the stored date is a leap year.
    bool isLeapYear() { return (isLeapYear(year)); } 
    bool isLeapYear(int year); //Returns true if the input year is a leap year

    //GetLastDayfunction-Returns the last day in the month of the stored date.
    //inputs=none
    //output=the last day in the month of the stored date, in integer format.
    //preconditions=the date must first be created by one of the constructors,
    //(except if the contructor is using this function). 
    int getLastDay() { return (getLastDay(month, year)); } 
    int getLastDay(int m, int y); //Returns the last day of the month of the input date.

    string printDate1(); //Format 1: MM/DD/YYYY
    string printDate2(); //Format 2: Month DD, YYYY
    string printDate3(); //Format 3: DD Month YYYY

    //Overloaded operators:

    Date& operator++();   //Prefix increment operator
    Date operator++(int); //Postfix increment operator
    Date& operator--();   //Prefix decrement operator
    Date operator--(int); //Postfix decrement operator

    int operator-(Date& second); //Subtraction operator for Date - Date

    friend ostream& operator<<(ostream& out, Date& d); //cout’s stream insertion operator
    friend istream& operator>>(istream& input, Date& d); //cin’s stream extraction operator
};

#endif // DATE_H#pragma once
