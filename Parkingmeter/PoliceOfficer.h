#ifndef POLICE_OFFICER_H
#define POLICE_OFFICER_H

#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"

#include <string>
using namespace std;

//This class simulates a police officer inspecting parked cars. The class’s
//responsibilities are:
//	*To know the police officer’s name and badge number
//	*To examine a ParkedCar object and a ParkingMeter object, 
//   and determine whether the car’s time has expired
//	*To issue a parking ticket (generate a ParkingTicket object) if the 
//   car’s time has expired. This is done internally to the class. It could
//   have been done separately as a private function, but that is just more
//   work for the calling function (whoever uses this class).

class PoliceOfficer {
private:

	//Class member variables:
	string name;
	string badge_number;

public:
	PoliceOfficer(string n, string bn); //Constructor

	//Mutators and accessors for the class member variables:

	string getName();
	string getBadge_Number();

	void setName(string n);
	void setBadge_Number(string bn);

	//Based on a ParkedCar object, and a ParkingMeter object, the officer checks
	//to see if there is a parking violation. If there is a violation, a
	//ParkingTicket is created, the fine is calculated and set, and the ticket
	//is printed. Otherwise, a message noting the car is legally parked is 
	//displayed.
	void checkParkingViolation(ParkedCar car, ParkingMeter meter);

};

#endif // POLICE_OFFICER_H#pragma once
