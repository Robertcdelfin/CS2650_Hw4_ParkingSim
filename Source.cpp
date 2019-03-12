#include<iostream>
#include<string>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
//Beginning of ParkedCar class with the make, model, color, license number, and minutes parked.
//////////////////////////////////////////////////////////////////////////////////////////

class ParkedCar
{
private:
	// make of car
	string make;     
	// model of car
	string model;                
	// color of car
	string color;                
	// license plate of car
	string licensePlate;

	// number of minutes the car has been parked
	int parkedTime;           

public:
	//Default constructor
	ParkedCar()                    
	{
		make = " ";
		model = " ";
		color = " ";
		licensePlate = " ";

		parkedTime = 0;
	}
	ParkedCar(string constructorMake, string constructorModel, string constructorColor, string constructorPlate, int constructorParkedTime)    
	{
		make = constructorMake;

		model = constructorModel;
		color = constructorColor;
		licensePlate = constructorPlate;
		parkedTime= constructorParkedTime;
	}
	
	// returns the number of minutes the car has been parked
	int getparkedTime()             
	{
		return parkedTime;
	}

	//print function to display elements of car
	void print()                   
	{
		cout << "************* Car Information *************\n" << endl;
		cout << "Make: " << make << endl;
		cout << "Model: " << model << endl;
		cout << "Color: " << color << endl;
		cout << "License Plate Number: " << licensePlate << endl;
	}
};
///////////////////////////////////////////////////////////////////////
//End of Car class
/////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////
//Parking meter class
///////////////////////////////////////////////////////////////

class ParkingMeter
{
private:
	// How long the tickets covers you for
	int parkingMinutes;                     

public:
	//Default Constructor
	ParkingMeter()                               
	{
		parkingMinutes = 0;
	}

	ParkingMeter(int purchasedMinutes)          
	{
		parkingMinutes = purchasedMinutes;
	}

	int getParkingMinutes()  
	{
		return parkingMinutes;
	}

	void print()                                 
	{
		cout << "********* Meter Recepit *********\n" << endl;
		cout << "Number of minutes purchased : " << parkingMinutes << endl;
	}
};

//////////////////////////////////////////////////////////////////////////////////
// End of Parkingmeter class
///////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
//Beginning of PoliceOfficer class
///////////////////////////////////////////////////////////////////////////////////

class PoliceOfficer
{
private:
	// police officer's last name
	string firstName;                      
	// police officer's first name
	string lastName;                       
	// police officer's badge number
	string badgeNumber;                        

public:
	//default constructor
	PoliceOfficer()                       
	{
		firstName = " ";
		lastName = " ";
		badgeNumber = " ";
	}

	PoliceOfficer(string constructorFirstName, string constructorLastName, string constructorBadgeNum)         
	{
		firstName = constructorFirstName;
		lastName = constructorLastName;
		badgeNumber = constructorBadgeNum;
	}

	//Checks if car gets a ticket
	bool ticket(ParkedCar& carWait, ParkingMeter& meterTime) 
	{
		//If the ticket given minus the time the car has been waiting exceeds the time a ticket is given
		if ((meterTime.getParkingMinutes() - carWait.getparkedTime()) < 0)
		{
			return true;
		}
		//the ticket remains valid
		else
		{
			return false;
		}
	}

	void print()                       
	{
		cout << "******* Officer Information ********\n" << endl;
		cout << "First Name: " << firstName << endl;
		cout << "Last Name: " << lastName << endl;
		cout << "Badge Number: " << badgeNumber << endl;
	}
};
////////////////////////////////////////////////////////////////////////////////////////
//End of PoliceOfficer class
////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////
//Beginning of ParkingTicket class
///////////////////////////////////////////////////
class ParkingTicket
{
private:
	// parked car object
	ParkedCar car;                    
	// parking meter object
	ParkingMeter meter;               
	// police officer object
	PoliceOfficer officer;            
	// amount of the fine
	int fineAmount;                   

public:
	ParkingTicket(ParkedCar &carTicket, ParkingMeter &meterTicket, PoliceOfficer &officerTicket)      
	{
		car = carTicket;                 
		meter = meterTicket;
		officer = officerTicket;
		fineAmount = fineAmountFormula();
	}

	int fineAmountFormula()              
	{
		//price of the ticket for hour 1
		int initialTicketCost = 25;
		//rounded time for how long the car is waiting in minutes
		int carWaitTime = (ceil((car.getparkedTime() - meter.getParkingMinutes()) / 60.0) - 1);
		int totalTicketCost = (initialTicketCost + (10 * carWaitTime));
		return totalTicketCost;
	}

	void print()         
	{
		cout << "\n\n***** Ticket Information *****\n" << endl;
		car.print(); //prints car information
		officer.print(); //prints officer information
		cout << "\n****** Ticket Fine Cost *********" << "Amount: $" << fineAmount << endl;
	}
};
/*
End Parking Ticket Class
*/

int main()
{
	// make of the parked car
	string carMake;                        
	// model of the parked car
	string carModel;
	// color of the parked car
	string carColor;
	// license number of the parked car
	string carLicensePlate;                 
	// police officer's first name
	string firstName;
	// police officer's last name
	string lastName;
	// police officer's badge number
	string badgeNumber;

	// number of minutes the parked car has been parked
	int parkedMinutes;                  
	// minutes of purchased parking time
	int purchasedMinutes;     
 
	cout << "Enter Car information \n" << endl;
	cout << "Make: ";
	cin >> carMake;
	cout << "Model: ";
	cin >> carModel;
	cout << "Color: ";
	cin >> carColor;
	cout << "License Number: ";
	cin >> carLicensePlate;

	do
	{
		//to prevent negative input
		cout << "Number of minutes car has been parked: ";
		cin >> parkedMinutes;
	} while (parkedMinutes < 0);

	//create car 1 object
	ParkedCar car1(carMake, carModel, carColor, carLicensePlate, parkedMinutes);

	cout << "\n Meter Reciept information\n" << endl;     

	do
	{
		cout << "Number of minutes purchased: ";
		cin >> purchasedMinutes;

	} while (purchasedMinutes < 0);

	//creates meter 1 object
	ParkingMeter meter1(purchasedMinutes);         

	cout << "\n Police Officer Information:\n" << endl;            
	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;
	cout << "Badge Number: ";
	cin >> badgeNumber;
	
	//Create office 1 object
	PoliceOfficer officer1(lastName, firstName, badgeNumber);  

	//checks if a ticket is needed
	if (officer1.ticket(car1, meter1) == true)        
	{
		//creates a ticket1 object
		ParkingTicket ticket1(car1, meter1, officer1);           
		ticket1.print();                                        
	}
	//car does not need a ticket
	else                                                        
	{
		cout << "\n No fine given. Car is parked legally. *" << endl;
	}
	return 0;
}