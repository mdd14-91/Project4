#ifndef PARKING_TICKET_H
#define PARKING_TICKET_H

#include "ParkedCar.h"

#include <string>
using namespace std;

//This class simulates a parking ticket. The class’s responsibilities are:
//	*To report the make, model, color, and license number of the illegally parked car
//	*To report the amount of the fine, which is $25 for the first hour or part of 
//   an hour that the car is illegally parked, plus $10 for every additional hour 
//   or part of an hour that the car is illegally parked
//	*To report the name and badge number of the police officer issuing the ticket

class ParkingTicket {
private:

	//Class member variables:
	ParkedCar offending_vehicle; //the car who parked longer that the meter allowed
	float fine_amount; //the amount of fine calculated based on the amount of time not purchased
	string officer_name; //the name of the officer issuing the ticket
	string officer_badge_number; //the badsge number of the officer issuing the ticket

public:
	ParkingTicket(ParkedCar ov, string on, string obn); //Constructor

	//Mutators and accessors for the class member variables: these
	//simple functions either return one of the class member variables,
	//or set one. For this object, the mutators and accessors were
	//inlined to demonstate knowledge of the technique.

	ParkedCar getCar() { return offending_vehicle; }
	float getFine() { return fine_amount; }
	string getOfficer_Name() { return officer_name; }
	string getOfficer_Badge_Number() { return officer_badge_number; }

	void setCar(ParkedCar ov) { offending_vehicle = ov; }
	void setFine(float fa) { fine_amount = fa; }
	void setOfficer_Name(string on) { officer_name = on; }
	void setOfficer_Badge_Number(string obn) { officer_badge_number = obn; }

	//Calculate the fine owed; time is input in minutes and is the amount 
	//of time the car was parked after the meter expired.
	float calculate_fine(int time);

	//Prints out the parking ticket, if one exists.
	void print();
};

#endif // PARKING_TICKET_H#pragma once
