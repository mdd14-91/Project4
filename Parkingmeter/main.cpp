#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

#include <iostream>
#include <string>
using namespace std;

//Main function: The purpose of this function is to test the parking ticket simulator classes.
//It tests both the classes working together as described in the exercise. I made a separate test to test the mutators not required for the
//main test.
int main() {

	//Main test- this part tests the classes functioning together, as
	//suggested in the class handout "Parking Ticket Simulator Collaborations"
	cout << "Scenario 1:Car is parked legally\n" << endl;
	ParkedCar redToyota = ParkedCar("Toyota", "Camry", "Red", "XYZ123", 30);
	cout << "Toyota, Camry, Red, XYZ123, 30 minutes parked" << endl;
	cout << "Maximum parking allowed 40 minutes." << endl;
	ParkingMeter meter1 = ParkingMeter(40);
	PoliceOfficer OfficerDoe = PoliceOfficer("John Doe", "5678\n");
	cout << "Officer John Doe, Badge No:5678 inspects the car" << endl;

	OfficerDoe.checkParkingViolation(redToyota, meter1);

	//-------------------------------------------------------------------------
	cout << "Scenario 2: Car is parked illegally under an hour\n" << endl;

	ParkedCar blueHonda = ParkedCar("Honda", "Accord", "Blue", "ABC987", 70);
	ParkingMeter meter2 = ParkingMeter(60);
	PoliceOfficer OfficerSmith = PoliceOfficer("Jane Smith", "1234\n");

	OfficerSmith.checkParkingViolation(blueHonda, meter2);

	//-------------------------------------------------------------------------
	cout << " Scenario 3: Car is parked illegally for multiple hours over the limit\n" << endl;

	ParkedCar blackMustang = ParkedCar("Ford", "Mustang", "Black", "LMN456", 190);
	ParkingMeter meter3 = ParkingMeter(60);
	PoliceOfficer OfficerBrown = PoliceOfficer("James Brown", "4321");

	OfficerBrown.checkParkingViolation(blackMustang, meter3);

	//-------------------------------------------------------------------------
	//Now Officer Jones will walk around and inspect multiple cars in the lot:
	cout << "Scenario 4: Officer Jones, Badge No.2468 is inspecting multiple cars in the lot now \n" << endl;
	PoliceOfficer OfficerJones = PoliceOfficer("Joe Jones", "2468");

	ParkedCar silverTesla = ParkedCar("Tesla", "Model 3", "Silver", "NOGAS", 25);
	ParkingMeter meter4 = ParkingMeter(30);

	OfficerJones.checkParkingViolation(silverTesla, meter4);

	ParkedCar blackBMW = ParkedCar("BMW", "325", "Black", "SOGOOD", 125);
	ParkingMeter meter5 = ParkingMeter(0);

	OfficerJones.checkParkingViolation(blackBMW, meter5);

	ParkedCar greenMazda = ParkedCar("Mazda", "Miata", "Green", "BCD-234", 67);
	ParkingMeter meter6 = ParkingMeter(60);

	OfficerJones.checkParkingViolation(greenMazda, meter6);

	ParkedCar whiteGMC = ParkedCar("GMC", "truck", "White", "CDE-345", 60);
	ParkingMeter meter7 = ParkingMeter(60);

	OfficerJones.checkParkingViolation(whiteGMC, meter7);

	ParkedCar whiteHonda = ParkedCar("Honda", "Civic", "White", "DEF-456", 60);
	ParkingMeter meter8 = ParkingMeter(30);

	OfficerJones.checkParkingViolation(whiteHonda, meter8);

	ParkedCar silverChevy = ParkedCar("Chevrolet", "Venture", "Silver", "EFG-567", 375);
	ParkingMeter meter9 = ParkingMeter(60);

	OfficerJones.checkParkingViolation(silverChevy, meter9);

	ParkedCar whiteJeep = ParkedCar("Jeep", "Wagoner", "White", "FGH-678", 317);
	ParkingMeter meter10 = ParkingMeter(60);

	OfficerJones.checkParkingViolation(whiteJeep, meter10);

	cout << "End of test 4" << endl;

	//-------------------------------------------------------------------------
	//TEST PART 2: this part tests the functions in the classes that were not
	//tested above, mainly mutators and accessors.

	PoliceOfficer OfficerDuvall = PoliceOfficer("Olivia Duvall", "1111");
	cout << "Officer " << OfficerDuvall.getName() << " Badge Number "
		<< OfficerDuvall.getBadge_Number() << endl;
	OfficerDuvall.setName("Olivia D. Bond");
	OfficerDuvall.setBadge_Number("1010");
	cout << "Officer " << OfficerDuvall.getName() << " Badge Number "
		<< OfficerDuvall.getBadge_Number() << endl << endl;

	//-------------------------------------------------------------------------

	ParkingMeter meter20 = ParkingMeter(); //use the defaults for the parameters
	cout << "Parking Meter 20: " << meter20.getPurchased_Minutes()
		<< " minutes purchased" << endl;
	meter20.setPurchased_Minutes(120);
	cout << "Parking Meter 20: " << meter20.getPurchased_Minutes()
		<< " minutes purchased" << endl << endl;

	//-------------------------------------------------------------------------

	ParkedCar testCar = ParkedCar(); //use the defaults for the parameters
	cout << "testCar: Make " << testCar.getMake() << " Model "
		<< testCar.getModel() << " Color " << testCar.getColor()
		<< " License Number " << testCar.getLicense_Number()
		<< " Minutes Purchased " << testCar.getParked_Minutes() << endl;
	testCar.setMake("Ford");
	testCar.setModel("F150");
	testCar.setColor("navy blue");
	testCar.setLicense_Number("USAF 00413");
	testCar.setParked_Minutes(60);
	cout << "testCar: Make " << testCar.getMake() << " Model "
		<< testCar.getModel() << " Color " << testCar.getColor()
		<< " License Number " << testCar.getLicense_Number()
		<< " Minutes Purchased " << testCar.getParked_Minutes() << endl << endl;

	//-------------------------------------------------------------------------

	//In the first part of the test, the parking ticket was dynamically allocated.
	//In this test, we are not manually allocating memory. Also, this test includes
	//creating a ticket for a car not in violation.

	ParkingTicket ticket = ParkingTicket(testCar, OfficerDuvall.getName(),
		OfficerDuvall.getBadge_Number());
	int over_time = testCar.getParked_Minutes() - meter20.getPurchased_Minutes();
	ticket.setFine(ticket.calculate_fine(over_time));

	cout << "ticketed car: Make " << ticket.getCar().getMake() << " Model "
		<< ticket.getCar().getModel() << " Color " << ticket.getCar().getColor()
		<< " License Number " << ticket.getCar().getLicense_Number()
		<< " Minutes Purchased " << ticket.getCar().getParked_Minutes() << endl;
	cout << " Ticket fine: $" << ticket.getFine() << " Officer "
		<< ticket.getOfficer_Name() << " Officer Badge Number "
		<< ticket.getOfficer_Badge_Number() << endl << endl;

	//This is should not print anything because the fine is $0 
	//(the car is not in violation).
	ticket.print();

	ticket.setCar(silverTesla);
	ticket.setFine(300.0); //they are realy bad at following laws
	ticket.setOfficer_Name(OfficerDoe.getName());
	ticket.setOfficer_Badge_Number(OfficerDoe.getBadge_Number());

	cout << "ticketed car: Make " << ticket.getCar().getMake() << " Model "
		<< ticket.getCar().getModel() << " Color " << ticket.getCar().getColor()
		<< " License Number " << ticket.getCar().getLicense_Number()
		<< " Minutes Purchased " << ticket.getCar().getParked_Minutes() << endl;
	cout << " Ticket fine: $" << ticket.getFine() << " Officer "
		<< ticket.getOfficer_Name() << " Officer Badge Number "
		<< ticket.getOfficer_Badge_Number() << endl << endl;

	ticket.print();
}