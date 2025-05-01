#include "ParkingTicket.h"
#include <iostream>
using namespace std;

//Variable used in the print function below, set when the fine is calculated,
//calculate_fine() function.
int over_time = 0;

//Parking Ticket Constructor
//inputs=a ParkedCar object and strings that contain 1) the police officer's 
//full name and 2) the police officer's badge number.
//output=none
//preconditions=none. This is the class constructor.
//postcondition=the object is created for the parking ticket issued by
//the police officer whose name and badge number were sent as parameters to 
//the constructor, for the ParkedCar object that is sent as a parameter to the
//constructor.
ParkingTicket::ParkingTicket(ParkedCar ov, string on, string obn) {
	offending_vehicle = ov;
	officer_name = on;
	officer_badge_number = obn;
}

//Calculate_fine; time is input in minutes.
//inputs=the amount of time in minutes that was not purchased for parking
//output=the fine, in floating point format
//preconditions=none. 
//postcondition=the fine is calculated and the amount of time in
//violation has been saved in a variable global to this file for use
//if the ticket is printed, print() function.
float ParkingTicket::calculate_fine(int time) {
	float fine = 0.0;

	//First, save the time. It will be needed by the print function.
	//Them print function could be placed in another class, but it
	//makes more sense to have it in this class.
	over_time = time;

	if (time <= 0.0) //the meter still has time on it
		fine = 0.0;
	else if (time <= 60.0) //part or all of the first hour
		fine = 25.00;
	else { //more than an hour
		fine = 25.00 + (((time - 60) / 60) * 10.00);
		if (((time - 60) % 60) > 0) //account for partial hours
			fine = fine + 10;
	}

	return fine;
}

//ParkingTicket print: Prints out the parking ticket, if one exists.
//inputs=none
//output=none
//preconditions=the car must be in violation with a fine amount set. 
//postcondition=the parking ticket is printed.
void ParkingTicket::print() {
	if (fine_amount > 0.0) {
		cout << " * **Parking Ticket * **" << endl;
		cout << "Officer " << officer_name << " Badge Number "
			<< officer_badge_number << endl;
		cout << "Vehicle License Number : " << offending_vehicle.getLicense_Number() << endl;
		cout << "Make : " << offending_vehicle.getMake() << " Model : " << offending_vehicle.getModel()
			<< " Color : " << offending_vehicle.getColor() << endl;
		int meter_minutes = offending_vehicle.getParked_Minutes() - over_time;
		cout << "Meter Minutes : " << meter_minutes
			<< " Minutes Parked : " << offending_vehicle.getParked_Minutes() << endl;
		cout << "Parking Fee : $" << fine_amount << endl << endl;
	}
	//else, there is no point in printing a ticket without a fine
}
