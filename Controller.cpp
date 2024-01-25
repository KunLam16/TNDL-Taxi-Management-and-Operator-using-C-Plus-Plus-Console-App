#include "iostream"
#include "iomanip"
#include "windows.h"
#include "Customers.cpp"
#include "Drivers.cpp"
#include "Cars.cpp"
#include "Booking.cpp"
using namespace std;

class Controller {
	private:
		list<Customer> customers;
		list<Driver> drivers;
		list<Car> cars;
		list<Booking> bookings;
	public:
		Controller() {
			Customer cus("ID1", "Thang", "Nam", "0388508755","Bac Ninh",12);
			Customer cus1("ID2", "Xuan", "Nu", "0388508755","Bac Ninh",16);
			customers.push_back(cus);
			customers.push_back(cus1);
			
			Driver dus("ID1", "Thang", "Nam", "0388508755","Bac Ninh",0,12);
			Driver dus1("ID2", "Xuan", "Nu", "0388508755","Bac Ninh",1, 16);
			Driver dus2("ID3", "Phan Anh", "Nam", "0388508755","Bac Ninh",0, 16);
			drivers.push_back(dus);
			drivers.push_back(dus1);
			drivers.push_back(dus2);
			
			Car car1("ID1", "Thang");
			cars.push_back(car1);
			
//			Booking book1("Bac Ninh", "Ha Noi","ID1","ID1",120);
//			bookings.push_back(book1);
		}
		// Check Method
		bool checkDriverID(string ID) {
			for(list<Driver>::iterator driV = drivers.begin();driV!= drivers.end();driV++) {
				if (ID == driV->getID()) {
					return false;
				}
			}
			return true;
		}
		
		bool checkCusID(string ID) {
			for(list<Customer>::iterator cusT = customers.begin();cusT!= customers.end();cusT++) {
				if (ID == cusT->getID()) {
					return false;
				}
			}
			return true;
		}
		
		bool checkCarID(string ID) {
			for(list<Car>::iterator carS = cars.begin();carS!= cars.end();carS++) {
				if (ID == carS->getID()) {
					return false;
				}
			}
			return true;
		}
		
		bool checkAvailableDriver(string ID) {
			for(list<Driver>::iterator driV = drivers.begin();driV!= drivers.end();driV++) {
				if (ID == driV->getID()) {
					if (driV->getIsBooking() == 1) {
						return false;
					}
				}
			}
			return true;
		}
		// Customer Method
		void addCus() {
			Customer cus;
			cus.inputCus();
			Sleep(2000);
			if (checkCusID(cus.getID())==true) {
				customers.push_back(cus);
				cout<<"\nSaved \nNOTE: We saved your Customer Infomation.\n" << endl;
				cout<<"Press any key to return to the menu";
			} 
			else {
				cout<<"\nYour ID Customer was registered.\n";
				cout<<"Please re-enter your data !!!";
			}
		}
		void getAllCus() {
			cout <<"------------------------------------------Customers-------------------------------------------\n\n";
			cout<<"----------------------------------------------------------------------------------------------\n";
			cout<<left<<"| "<<setw(10)<<"ID"<<"|"<<setw(30)<<"Name"<<"|"<<setw(10)<<"Gender"<<"|"<<setw(15)<<"Phone"<<"|"<<setw(10)<<"Address"<<"|"<<setw(10)<<"Age"<<" |"<<endl;
			cout<<"----------------------------------------------------------------------------------------------\n";
			for(list<Customer>::iterator cusT = customers.begin();cusT!= customers.end();cusT++) {
		        cusT->outputCus();
		        cout<<"----------------------------------------------------------------------------------------------\n";
		    }
		    cout<<"\n Press any key to return to the menu";
		}
		void searchCus() {
			string searchGender;
			cout<<"Please enter the gender you want to find (Nam, Nu): "; cin.ignore(); getline(cin,searchGender);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			cout<<"We are looking for your request, Please wait\n";
			Sleep(1000);
			cout<<"--> YOUR REQUEST !!!\n";
			cout<<"----------------------------------------------------------------------------------------------\n";
			cout<<left<<"| "<<setw(10)<<"ID"<<"|"<<setw(30)<<"Name"<<"|"<<setw(10)<<"Gender"<<"|"<<setw(15)<<"Phone"<<"|"<<setw(10)<<"Address"<<"|"<<setw(10)<<"Age"<<" |"<<endl;
			cout<<"----------------------------------------------------------------------------------------------\n";
			for(list<Customer>::iterator cusT = customers.begin();cusT!= customers.end();cusT++) {
				if (cusT->getGender() == searchGender) {
					cusT->outputCus();
		        	cout<<"----------------------------------------------------------------------------------------------\n";	
				}
		    }
		    cout<<"\n Press any key to return to the menu";
		}
		void deleteCus() {
			string deleteID;
			list<Customer>::iterator cusT;
			bool checkValid = false; // To check ID valid
			cout<<"Please enter ID Cutomer you want to delete: "; cin.ignore(); getline(cin, deleteID);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			cout<<"We are looking for your request, Please wait\n";
			Sleep(1000);
			cout<<"--> Customer Infomation you want to delete !!!\n";
			cout<<"----------------------------------------------------------------------------------------------\n";
			for(cusT = customers.begin();cusT!= customers.end();cusT++) {
				if (cusT->getID() == deleteID) {
					checkValid = true;
					cusT->outputCus();
		        	cout<<"----------------------------------------------------------------------------------------------\n";
		        	break;
				}
		    }
		    if (checkValid == true) {
		    	string deleteChoice;
		    	cout<<"Do you want to Delete this Customer Infomation ?(Accept/No): "; getline(cin, deleteChoice);
		    	if (deleteChoice == "Accept") {
			    	customers.erase(cusT);
			    	Sleep(1000);
			    	cout<<"Done !!!\n";
				}
			}
		    else {
		    	cout<<"\n We don't find Customer Information !!!";
			}
			cout<<"\nPress any key to return to the menu";
		}
		
		// Driver Method
		void addDriver() {
			Driver dri;
			dri.inputDriver();
			
			Sleep(2000);
			if (checkDriverID(dri.getID())==true) {
				drivers.push_back(dri);
				cout<<"\nSaved \nNOTE: We saved your Driver Infomation.\n" << endl;
				cout<<"Press any key to return to the menu";
			} 
			else {
				cout<<"\nYour ID Driver was registered.\n";
				cout<<"Please re-enter your data !!!";
			}
		}
		void getAllDriver() {
			cout <<"-------------------------------------------Driver--------------------------------------------\n\n";
			cout<<"---------------------------------------------------------------------------------------------------------\n";
			cout<<left<<"| "<<setw(10)<<"ID"<<"|"<<setw(30)<<"Name"<<"|"<<setw(10)<<"Gender"<<"|"<<setw(15)<<"Phone"<<"|"<<setw(10)<<"Address"<<"|"<<setw(10)<<"Status"<<"|"<<setw(10)<<"Age"<<" |"<<endl;
			cout<<"---------------------------------------------------------------------------------------------------------\n";
			for(list<Driver>::iterator driV = drivers.begin();driV!= drivers.end();driV++) {
		        driV->outputDriver();
		        cout<<"---------------------------------------------------------------------------------------------------------\n";
		    }
		    cout<<"\n Press any key to return to the menu";
		}
		void searchDriver() {
			string searchGender;
			cout<<"Please enter the gender you want to find (Nam, Nu): "; cin.ignore(); getline(cin,searchGender);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			cout<<"We are looking for your request, Please wait\n";
			Sleep(1000);
			cout<<"--> YOUR REQUEST !!!\n";
			cout<<"---------------------------------------------------------------------------------------------------------\n";
			cout<<left<<"| "<<setw(10)<<"ID"<<"|"<<setw(30)<<"Name"<<"|"<<setw(10)<<"Gender"<<"|"<<setw(15)<<"Phone"<<"|"<<setw(10)<<"Address"<<"|"<<setw(10)<<"Status"<<"|"<<setw(10)<<"Age"<<" |"<<endl;
			cout<<"---------------------------------------------------------------------------------------------------------\n";
			for(list<Driver>::iterator driV = drivers.begin();driV!= drivers.end();driV++) {
				if (driV->getGender() == searchGender){
					driV->outputDriver();
		        	cout<<"---------------------------------------------------------------------------------------------------------\n";
				}
		    }
		    cout<<"\n Press any key to return to the menu";
		}
		
		void deleteDriver() {
			string deleteID;
			list<Driver>::iterator driV;
			bool checkValid = false; // To check ID valid
			cout<<"Please enter ID Driver you want to delete: "; cin.ignore(); getline(cin, deleteID);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			cout<<"We are looking for your request, Please wait\n";
			Sleep(1000);
			cout<<"--> Driver Infomation you want to delete !!!\n";
			cout<<"---------------------------------------------------------------------------------------------------------\n";
			for(driV = drivers.begin();driV!= drivers.end();driV++) {
				if (driV->getID() == deleteID) {
					checkValid = true;
					driV->outputDriver();
		        	cout<<"---------------------------------------------------------------------------------------------------------\n";
		        	break;
				}
		    }
		    if (checkValid == true) {
		    	string deleteChoice;
		    	cout<<"Do you want to Delete this Customer Infomation ?(Accept/No): "; getline(cin, deleteChoice);
		    	if (deleteChoice == "Accept") {
			    	drivers.erase(driV);
			    	Sleep(1000);
			    	cout<<"Done !!!\n";
				}
			}
		    else {
		    	cout<<"\n We don't find Customer Information !!!";
			}
			cout<<"\nPress any key to return to the menu";
		}
		// Car Method
		void addCar() {
			Car car;
			car.inputCar();
	
			Sleep(2000);
			if (checkCarID(car.getID())==true) {
				cars.push_back(car);
				cout<<"\nSaved \nNOTE: We saved your Car Infomation.\n" << endl;
				cout<<"Press any key to return to the menu";
			} 
			else {
				cout<<"\nYour ID Car was registered.\n";
				cout<<"Please re-enter your data !!!";
			}
		}
		void getAllCar() {
			cout <<"-------------------------------------------Car--------------------------------------------\n\n";
			cout<<"--------------------------------------------\n";
			cout<<left<<"| "<<setw(10)<<"ID"<<"|"<<setw(30)<<"Type"<<"|"<<endl;
			cout<<"--------------------------------------------\n";
			for(list<Car>::iterator carS = cars.begin();carS!= cars.end();carS++) {
		        carS->outputCar();
		        cout<<"--------------------------------------------\n";
		    }
		    cout<<"\n Press any key to return to the menu";
		}
		void deleteCar() {
			string deleteID;
			list<Car>::iterator carS;
			bool checkValid = false; // To check ID valid
			cout<<"Please enter ID Car you want to delete: "; cin.ignore(); getline(cin, deleteID);
			cout<<"\n----------------------------------------------------------------------------------------------\n";
			cout<<"We are looking for your request, Please wait\n";
			Sleep(1000);
			cout<<"--> Car Infomation you want to delete !!!\n";
			cout<<"--------------------------------------------\n";
			for(carS = cars.begin();carS!= cars.end();carS++) {
				if (carS->getID() == deleteID) {
					checkValid = true;
					carS->outputCar();
		        	cout<<"--------------------------------------------\n";
		        	break;
				}
		    }
		    if (checkValid == true) {
		    	string deleteChoice;
		    	cout<<"Do you want to Delete this Customer Infomation ?(Accept/No): "; getline(cin, deleteChoice);
		    	if (deleteChoice == "Accept") {
			    	cars.erase(carS);
			    	Sleep(1000);
			    	cout<<"Done !!!\n";
				}
			}
		    else {
		    	cout<<"\n We don't find Car Information !!!";
			}
			cout<<"\nPress any key to return to the menu";
		}
		// Booking methods
		void addBooking() {
			string choice, choice1;
			Booking booking;
			cin.ignore();
			booking.inputBooking();
			if (checkCusID(booking.getCusID())==true) {
				cout<<"\nWe don't find the Customer ID\n";
				cout<<"Press any key to return to the menu";
				return;
			}
			
//			cout<<"---------------------------------------------------------------------------------------------------------\n";
			for(list<Driver>::iterator driV = drivers.begin();driV!= drivers.end();driV++) {
					if (checkAvailableDriver(driV->getID()) == true) {
							cout<<"\nWe are finding Driver !!!\n";
							Sleep(1000);
							cout<<"--> Result \n\n";
							cout<<endl;
							cout<<"---------------------------------------------------------------------------------------------------------\n";
							driV->outputDriver();
							cout<<"---------------------------------------------------------------------------------------------------------\n\n";
							cout<<"Do you want to booking this driver ? (Y/N): "; cin>>choice;
							if (choice == "Y") {
								Sleep(1000);
								cout<<"\nDone!\n";
								booking.setDriverID(driV->getID());
								bookings.push_back(booking);
								driV->setIsBooking(1);
								cout<<"Do you want to print Bill ? (Y/N): "; cin>>choice1;
									if (choice1 == "Y") {
										Sleep(1000);
										getBill(booking.getCusID());
									}
								cout<<"We are going to Main Menu...";
								break;
						}
							else {
								continue;
							}	
					}
				}
		}
		void getAllBooking() {
			cout <<"---------------------------------------------------Booking-------------------------------------------------\n\n";
			cout<<"-----------------------------------------------------------------------------------------------------------\n";
			cout<<left<<"| "<<setw(30)<<"Pickup"<<"|"<<setw(30)<<"Drop"<<"|"<<setw(15)<<"DriverID"<<"|"<<setw(15)<<"CusID"<<"|"<<setw(10)<<"Distance"<<"|"<<endl;
			cout<<"-----------------------------------------------------------------------------------------------------------\n";
			for(list<Booking>::iterator bookS = bookings.begin();bookS!= bookings.end();bookS++) {
		        bookS->outputBooking();
		        cout<<"-----------------------------------------------------------------------------------------------------------\n";
		    }
		    cout<<"\n Press any key to return to the menu";
		}
		// Bill
		void searchBill() {
			string ID;
			cout<<"Enter Customer ID to find Bill: ";
			cin>>ID;
			if (getBill(ID)) {
				cout<<"\n\nPress any key to return to the menu";
			}
			else {
				cout<<"We don't find bill";
				cout<<"\n\nPress any key to return to the menu";
			}
		}
		bool getBill(string ID){
			for(list<Booking>::iterator bookS = bookings.begin();bookS!= bookings.end();bookS++) {
		    	if (ID == bookS->getCusID()) {
		    			cout << "\n---------TNDL Taxi Agency--------" << endl;
					    cout << "--------------Bill---------------" << endl;
					    cout << "_________________________________" << endl;
					
					    cout << "Customer ID:   \t\t " << bookS->getCusID() << endl << endl;
					    cout << "Description\t\t Total" << endl;
					    cout << "Taxi (cab) cost:\t " << setprecision(1) << fixed << bookS->total(bookS->getDistance()) << endl;
					    cout << "VAT:\t\t\t 10%"<<endl;
					
					    cout << "_________________________________" << endl;
					    cout << "Total Charge:\t\t " << setprecision(1) << fixed << bookS->total(bookS->getDistance()) + bookS->total(bookS->getDistance())*0.1 << endl;
					    cout << "_________________________________" << endl;
					    cout << "------------THANK YOU------------" << endl;
				}
			}
		}
};

