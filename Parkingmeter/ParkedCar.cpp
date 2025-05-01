#include "ParkedCar.h"


//Parked Car Constructor
//inputs=strings for the car's make, model, color and license plate number,
//and the total number of minutes the car has been parked.
//output=none
//preconditions=none. This is the class constructor.
//postcondition=the object is created for the car based on the 
//input parameters.
ParkedCar::ParkedCar(string m, string mod, string c, string ln, int pm) {
	make = m;
	model = mod;
	color = c;
	license_number = ln;
	parked_minutes = pm;
}

//Mutators and accessors for the class member variables: these
//simple functions either return one of the class member variables,
//or set one.

string ParkedCar::getMake() {
	return ParkedCar::make;
}

string ParkedCar::getModel() {
	return ParkedCar::model;
}

string ParkedCar::getColor() {
	return ParkedCar::color;
}

string ParkedCar::getLicense_Number() {
	return ParkedCar::license_number;
}

int ParkedCar::getParked_Minutes() {
	return ParkedCar::parked_minutes;
}

void ParkedCar::setMake(string new_make) {
	make = new_make;
}

void ParkedCar::setModel(string new_model) {
	model = new_model;
}

void ParkedCar::setColor(string new_color) {
	color = new_color;
}

void ParkedCar::setLicense_Number(string new_license_number) {
	license_number = new_license_number;
}

void ParkedCar::setParked_Minutes(int new_parked_minutes) {
	parked_minutes = new_parked_minutes;
}