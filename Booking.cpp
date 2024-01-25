#include "bits/stdc++.h"
using namespace std;

class Booking 
{
	private:
		string Pickup, Drop, driverID, cusID;
		int Distance;
	public:
		Booking() {
			Pickup = "";
			Drop = "";
			driverID = "";
			cusID = "";
			Distance = 0;
		}
		Booking(string Pickup, string Drop, string driverID, string cusID, int Distance) {
			this->Pickup = Pickup;
			this->Drop = Drop;
			this->driverID = driverID;
			this->cusID = cusID;
			this->Distance = Distance;
		}
		int getDistance() {
			return Distance;
		}
		void setDriverID(string driverID){
			this->driverID = driverID;
		}
		
		string getDriverID() {
			return driverID;
		}
		string getCusID() {
			return cusID;
		}
		void inputBooking();
		void outputBooking();
		double total(int);
};

void Booking::inputBooking() {

	cout<<"Enter Pickup Destination: "; getline(cin, Pickup); 
	cout<<"Enter Drop Destination: "; getline(cin, Drop); 
//	cout<<"Enter Driver ID: "; getline(cin, driverID); 
	cout<<"Enter Customer ID: "; getline(cin, cusID); cin.ignore(0);
	cout<<"Distance: "; cin>>Distance;

}

void Booking::outputBooking() {
	cout<<left<<"| "<<setw(30)<<Pickup<<"|"<<setw(30)<<Drop<<"|"<<setw(15)<<driverID<<"|"<<setw(15)<<cusID<<"|"<<setw(10)<<Distance<<"|"<<endl;
}

double Booking::total(int Distance) {
	double Total = 0;
	if (Distance>0 && Distance<=30) {
		Total = 11000*Distance;
	}
	else {
		Total = 11000*Distance + (Distance-30)*9500;
	}
	return Total;
}


