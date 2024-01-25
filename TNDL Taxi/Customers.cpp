#include "iostream"
#include "iomanip"
using namespace std;

class Customer {
	private:
		string ID, Name, Gender, Phone, Address;
		int Age;
	public:
		Customer() {
			ID = "";
			Name = "";
			Gender = "";
			Phone = "";
			Address = "";
			Age = 0;
		}
		Customer(string ID, string Name, string Gender, string Phone, string Address, int Age) {
			this->ID = ID;
			this->Name = Name;
			this->Gender = Gender;
			this->Phone = Phone;
			this->Address = Address;
			this->Age = Age;
		}
		string getID() {
			return ID;
		}
		string getGender() {
			return Gender;
		}
		void inputCus();
		void outputCus();
};

void Customer::inputCus() {

	cout<<"Enter CusID: "; getline(cin, ID); 
	cout<<"Enter Name: "; getline(cin, Name); 
	cout<<"Gender: "; getline(cin, Gender); 
	cout<<"Mobile Phone: "; getline(cin, Phone);
	cout<<"Address: "; getline(cin, Address); cin.ignore(0);
	cout<<"Your Age: "; cin>>Age; 

}

void Customer::outputCus() {
	cout<<left<<"| "<<setw(10)<<ID<<"|"<<setw(30)<<Name<<"|"<<setw(10)<<Gender<<"|"<<setw(15)<<Phone<<"|"<<setw(10)<<Address<<"|"<<setw(10)<<Age<<" |"<<endl;
}



