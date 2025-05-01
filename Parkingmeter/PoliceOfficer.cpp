#include "PoliceOfficer.h"

#include <iostream>
#include <string>
using namespace std;

//PoliceOfficer Constructor
//inputs=strings that contain 1) the police officer's full name and
//2) the police officer's badge number.
//output=none
//preconditions=none. This is the class constructor.
//postcondition=the object is created for the police officer whose
//name and badge number were sent as parameters to the constructor.
PoliceOfficer::PoliceOfficer(string n, string bn) {
	name = n;
	badge_number = bn;
}

//Mutators and accessors for the class member variables: these
//simple functions either return one of the class member variables,
//or set one. 

string PoliceOfficer::getName() {
	return name;
}

string PoliceOfficer::getBadge_Number() {
	return badge_number;
}

void PoliceOfficer::setName(string n) {
	name = n;
}
void PoliceOfficer::setBadge_Number(string bn) {
	badge_number = bn;
}

//checkParkingViolation-Based on a ParkedCar object, and a ParkingMeter object, the officer checks
//to see if there is a parking violation. If there is a violation, a
//ParkingTicket is created, the fine is calculated and set, and the ticket
//is printed. Otherwise, a message noting the car is legally parked is 
//displayed.
//inputs=a ParketCar object and a ParkingMeter object
//output=none
//preconditions=both the ParkedCar and ParkingMeter objects must have been created using
//their constructors.
//postcondition=Either a ParkingTicket is created and printed (if the car at
//that meter was in violation) or a message indicating the car is parked legally
//is displayed.
void PoliceOfficer::checkParkingViolation(ParkedCar car, ParkingMeter meter) {
	ParkingTicket* t = NULL;

	if (car.getParked_Minutes() > meter.getPurchased_Minutes()) {
		t = new ParkingTicket(car, name, badge_number);
		int over_time = car.getParked_Minutes() - meter.getPurchased_Minutes();
		t->setFine(t->calculate_fine(over_time));
	}

	//If t is not null at this point in the code, then the officer has found a
	//parking violation and created a ticket. So, he prints the ticket then deletes
	//it from his ticket writing machine.
	if (t != NULL) {
		t->print();
		delete t;
	}
	else { //The car is parked legally, no need for the officer to create a ticket.
		cout << "The " << car.getColor() << " " << car.getMake() << " "
			<< car.getModel() << " is parked legally." << endl << endl;
	}
}