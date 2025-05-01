#ifndef PARKED_CAR_H
#define PARKED_CAR_H

#include <string>
using namespace std;

//This class simulates a parked car. The class’s responsibilities are to know the car’s 
//make, model, color, license number, and the number of minutes that the car has been parked.

class ParkedCar {
private:

    //Class member variables:
    string make; //the car's make, for example, Ford
    string model; //the car's model
    string color; //the car's color
    string license_number; //the car's license plate number
    int parked_minutes; //the total number of minutes this car has been parked

public:
    ParkedCar(string m = "", string mod = "", string c = "", string ln = "", int pm = 0); //Constructor

    //Mutators and accessors for the class member variables:

    string getMake();
    string getModel();
    string getColor();
    string getLicense_Number();
    int getParked_Minutes();

    void setMake(string new_make);
    void setModel(string new_model);
    void setColor(string new_color);
    void setLicense_Number(string new_license_number);
    void setParked_Minutes(int new_parked_minutes);
};

#endif // PARKED_CAR_H
