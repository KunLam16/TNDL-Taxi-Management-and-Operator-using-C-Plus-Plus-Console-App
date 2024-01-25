#include "iostream"
#include "iomanip"
using namespace std;

class Driver {
	private:
		string ID, Name, Gender, Phone, Address;
		bool isBooking;
		int Age;
	public:
		Driver() {
			ID = "";
			Name = "";
			Gender = "";
			Phone = "";
			Address = "";
			isBooking = false;
			Age = 0;
		}
		Driver(string ID, string Name, string Gender, string Phone, string Address, bool isBooking, int Age) {
			this->ID = ID;
			this->Name = Name;
			this->Gender = Gender;
			this->Phone = Phone;
			this->Address = Address;
			this->isBooking = isBooking;
			this->Age = Age;
		}
		string getID() {
			return ID;
		}
		string getGender() {
			return Gender;
		}
		void setIsBooking(bool isBooking) {
			this->isBooking = isBooking;
		}
		bool getIsBooking() {
			return isBooking;
		}
		void inputDriver();
		void outputDriver();
};

void Driver::inputDriver() {

	cout<<"Enter CusID: "; getline(cin, ID); 
	cout<<"Enter Name: "; getline(cin, Name); 
	cout<<"Gender: "; getline(cin, Gender); 
	cout<<"Mobile Phone: "; getline(cin, Phone);
	cout<<"Address: "; getline(cin, Address); cin.ignore(0);
	cout<<"Enter Driver Status (1: Booking, 0: Not Booking): "; cin>>isBooking;
	cout<<"Your Age: "; cin>>Age; 

}

void Driver::outputDriver() {
	cout<<left<<"| "<<setw(10)<<ID<<"|"<<setw(30)<<Name<<"|"<<setw(10)<<Gender<<"|"<<setw(15)<<Phone<<"|"<<setw(10)<<Address<<"|"<<setw(10)<<isBooking<<"|"<<setw(10)<<Age<<" |"<<endl;
}



