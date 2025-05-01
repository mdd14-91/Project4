#ifndef PARKING_METER_H
#define PARKING_METER_H

#include <string>
using namespace std;

//This class simulates a parking meter. The class’s only responsibility 
//is to know the number of minutes of parking time that has been purchased.

class ParkingMeter {
private:

	//Class member variables:
	int purchased_minutes; //how many minutes were purchased on the meter

public:
	ParkingMeter(int minutes = 0); //Constructor

	//Mutator and accessor for the class member variable:

	int getPurchased_Minutes();
	void setPurchased_Minutes(int minutes);

};

#endif // PARKING_METER_H#pragma once
