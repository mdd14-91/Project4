#include "ParkingMeter.h"

//Parking Meter Constructor
//inputs=the number of minutes that were purchased on this meter
//output=none
//preconditions=none. This is the class constructor.
//postcondition=the object is created for the parking meter with the
//number of minutes purchased on the meter, as passed in the parameter.
ParkingMeter::ParkingMeter(int minutes) {
	purchased_minutes = minutes;
}

//Mutators and accessors for the class member variables: these
//simple functions either return one of the class member variables,
//or set one.

int ParkingMeter::getPurchased_Minutes() {
	return purchased_minutes;
}

void ParkingMeter::setPurchased_Minutes(int minutes) {
	purchased_minutes = minutes;
}