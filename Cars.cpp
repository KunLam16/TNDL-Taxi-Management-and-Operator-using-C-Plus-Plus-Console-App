#include "iostream"
#include "iomanip"
using namespace std;

class Car {
	private:
		string ID, Type;
	public:
		Car() {
			ID = "";
			Type = "";
		}
		Car(string ID, string Type) {
			this->ID = ID;
			this->Type = Type;
		}
		string getID() {
			return ID;
		}

		void inputCar();
		void outputCar();
};

void Car::inputCar() {
	
	cout<<"Enter ID: "; getline(cin, ID); 
	cout<<"Type Car: "; getline(cin, Type);

}

void Car::outputCar() {
	cout<<left<<"| "<<setw(10)<<ID<<"|"<<setw(30)<<Type<<"|"<<endl;
}



