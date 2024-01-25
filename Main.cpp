#include "iostream"
#include "conio.h"
#include "Controller.cpp"
#include "windows.h"
using namespace std;

void menu();

class ManageMenu
{
protected:
    string tenDangNhap, matKhau;
public:
    ManageMenu()
    {
    	char ch;        
        cout << "-------------------------Login Form--------------------------\n\n" << endl;
	    cout << "\t\tUsername: "; cin>>tenDangNhap;
	    cout << "\t\tPassword: "; 
	    while((ch = getch()) != 13)
		    {
		        matKhau += ch;
		        cout<<"*";
		    }

		cout<<endl<<endl;
	    if (tenDangNhap != "admin" || matKhau != "pass") {
	    	printf("-> Username or Password is wrong !!!\n");
	    	printf("\t\tPlease re-enter after 2 second");
	    	Sleep(2000);
	    	system("CLS");
	    	ManageMenu();
		}
		else {
			system("CLS");
       		menu();
		}
    }

    ~ManageMenu(){} 
};

void menu() {

	cout << "\t     * TNDL Taxi Management and Operator *\n" << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|\tCustomers Management  -> 1\t|" << endl;
    cout << "\t|\tDriver Management     -> 2\t|" << endl;
    cout << "\t|\tCars Management       -> 3\t|" << endl;
    cout << "\t|\tBookings Management   -> 4\t|" << endl;
    cout << "\t|\tExit                  -> 5\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
}

void menuCus() {
		cout << "------Customers------\n" << endl;
        cout << "1. Enter New Customer"<< endl;
        cout << "2. See All Customers"<< endl;
        cout << "3. Search Customers by Gender"<< endl;
        cout << "4. Delete Customer"<< endl;
        cout << "5. Return"<< endl;
        cout << "\nEnter choice: ";
}

void menuDri() {
		cout << "-------Driver-------\n" << endl;
        cout << "1. Enter New Driver"<< endl;
        cout << "2. See All Driver"<< endl;
        cout << "3. Search Driver by Gender"<< endl;
        cout << "4. Delete Driver"<< endl;
        cout << "5. Return"<< endl;
        cout << "\nEnter choice: ";
}


void menuCar() {
		cout << "--------Car--------\n" << endl;
        cout << "1. Enter New Car"<< endl;
        cout << "2. See All Car"<< endl;
        cout << "3. Delete Car"<< endl;
        cout << "4. Return"<< endl;
        cout << "\nEnter choice: ";
}

void menuBooking() {
	cout << "-------Booking-------\n" << endl;
    cout << "1. Enter New Booking"<< endl;
    cout << "2. See All Booking"<< endl;
    cout << "3. Search Bill"<< endl;
    cout << "4. Return"<< endl;
    cout << "\nEnter choice: ";
}

int main() {
	ManageMenu begin;
	Controller controller;
	int choose, inchoice;
	do{
		cin>>choose;
		system("cls");
		switch(choose)	
		{
			case 1:
				menuCus();
				cin>>inchoice;
				system("cls");
				if (inchoice == 1){
					cin.ignore();
					controller.addCus();
					getch();
				}
				else if (inchoice == 2){
					controller.getAllCus();
					getch();
				}
				else if (inchoice == 3){
					controller.searchCus();
					getch();
				}
				else if (inchoice == 4){
					controller.deleteCus();
					getch();
				}		
				system("cls");
				menu();
				break; 
			case 2:
				menuDri();
				cin>>inchoice;
				system("cls");
				if (inchoice == 1){
					cin.ignore();
					controller.addDriver();
					getch();
				}
				else if (inchoice == 2){
					controller.getAllDriver();
					getch();
				}
				else if (inchoice == 3){
					controller.searchDriver();
					getch();
				}
				else if (inchoice == 4){
					controller.deleteDriver();
					getch();
				}	
				system("cls");
				menu();
				break; 
			case 3:
				menuCar();
				cin>>inchoice;
				system("cls");
				if (inchoice == 1){
					cin.ignore();
					controller.addCar();
					getch();
				}
				else if (inchoice == 2){
					controller.getAllCar();
					getch();
				}	
				else if (inchoice == 3){
					controller.deleteCar();
					getch();
				}
				system("cls");
				menu();
				break;
			case 4:
				menuBooking();
				cin>>inchoice;
				system("cls");
				if (inchoice == 1){
					controller.addBooking();
					getch();
				}
				else if (inchoice == 2) {
					controller.getAllBooking();
					getch();
				}
				else if (inchoice == 3) {
					controller.searchBill();
					getch();
				}
				system("cls");
				menu();
				break;
			case 5:
					system("cls");
					cout<<"\n\n\t\t\tThank you !!!";
					Sleep(2000);
					return 0;
				break;
		}	
	}while(choose!=6);
	return 0;
}




