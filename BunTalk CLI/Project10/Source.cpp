#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int ascii = 178, i = 0;
char ch = ascii;

// Structs
struct Product {
	int pid = 0;
	string pname;
	float pprice = 0;
};

struct Employee {
	int eid = 0;
	string ename, contact, birth;
	float salary = 0;
};

void login();
void registration();
void forgot();
void loginC();
void forgotC();
void aceMenu();

//heading function
void billHead() {
	for (int m = 1; m < 30; m++)
		cout << ch;
}


void entireHead() {
	system("cls");
	billHead();
	cout << " BUN TALK BILLING SYSTEM ";
	billHead();
}

//after administrator registration run code
void lrfMenu() { //admin Main Menu
	int op;
	billHead();
	cout << " BUN TALK BILLING SYSTEM ";
	billHead();
	cout << "\n\n\t" << ch << ch << " ADMINISTRATOR'S LOGIN PAGE";
	cout << "\n\n\t\t Press 1 To Login";
	cout << "\n\n\t\t Press 2 To Register";
	cout << "\n\n\t\t Press 3 To Forget Password";
	cout << "\n\n\t\t Press 4 To Role Menu";
	cout << "\n\n\t\t Press 5 To Exit";

	cout << "\n\n\n Enter The Number Which You Want To Do: ";
	cin >> op;

	switch (op) {
	case 1:
		login();
		break;

	case 2:
		registration();
		break;

	case 3:
		forgot();
		break;

	case 4:
		system("cls");
		billHead();
		aceMenu();
		break;

	default:
		system("cls");
		cout << "Invalid Input!! Please follow the instructions!! \n\n";
		lrfMenu();

	case 5:
		cout << "\n\n\t\t === Thank you!! Have a Great day!! ===\n\n";
		exit(op);
		break;
	}


}

void lfeMenu() { // cashier Main Menu
	int op;
	billHead();
	cout << " BUN TALK BILLING SYSTEM ";
	billHead();
	cout << "\n\n\t" << ch << ch << " CASHIER'S LOGIN PAGE";
	cout << "\n\n\t\t Press 1 To Login";
	cout << "\n\n\t\t Press 2 To Forget Password";
	cout << "\n\n\t\t Press 3 To Exit";

	cout << "\n\n\n Enter The Number Which You Want To Do: ";
	cin >> op;

	switch (op) {
	case 1:
		loginC();
		break;

	case 2:
		forgotC();
		break;

	case 3:
		cout << "\n\n\t\t === Thank you!! Have a Greate day!! ===\n\n";
		break;

	default:
		system("cls");
		cout << "Invalid Input!! Please follow the instructions!! \n\n";
		lfeMenu();
	}
}



void addProMenu() {
	Product addProduct[20];
	cout << "\n\n\t" << ch << ch << " ADD NEW ITEMS";
	cout << "\n\n ENTER PRODUCT ID: ";
	cin >> addProduct[i].pid;
	cout << "\n\n ENTER PRODUCT NAME: ";
	cin >> addProduct[i].pname;
	cout << "\n\n ENTER PRODUCT PRICE: Rs.";
	cin >> addProduct[i].pprice;

	ofstream products("product.txt", ios::app); // WRITING PRODUCTS IN A FILE CALLED "product.txt"
	products << endl << "Product ID: " << addProduct[i].pid << endl
		<< "Product Name: " << addProduct[i].pname << endl
		<< "Product Price: Rs." << addProduct[i].pprice << endl
		<< ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch;

	ofstream cashier("cashierSelectProducts.txt", ios::app); // WRITING PRODUCTS IN A FILE CALLED "cashierSelectProducts.txt" for showing product list to the cashier
	cashier << addProduct[i].pid << " " << addProduct[i].pname << " " << addProduct[i].pprice << endl;

	cout << "\n New procut is added successfuly!!!";
}




void viewPro() {
	fstream products;
	products.open("product.txt", ios::in); // READ DATA IN "product.txt"
	if (products.is_open()) {
		string line;
		while (getline(products, line)) { // GET DATA
			cout << endl << line << endl;
		}
		products.close();
	}
	else {
		cout << "\n\n\t" << ch << ch << " No Products inserted!!";
	}
}

void viewCash() {
	fstream employees;
	employees.open("employee.txt", ios::in); // READ DATA IN "employee.txt"
	if (employees.is_open()) {
		string line;
		while (getline(employees, line)) { // GET DATA
			cout << endl << line << endl;
		}
		employees.close();
	}

	else {
		cout << "\n\n\t" << ch << ch << " No Employees inserted!!";
	}
}

void addCashierMenu() {
	Employee addemp[10];
	cout << "\n\n\t " << ch << ch << " ADD NEW CASHIERS";
	cout << "\n\n ENTER EMPLOYEE ID: ";
	cin >> addemp[i].eid;
	cout << "\n ENTER EMPLOYEE NAME: ";
	cin >> addemp[i].ename;
	cout << "\n ENTER EMPLOYEE CONTACT: ";
	cin >> addemp[i].contact;
	cout << "\n ENTER EMPLOYEE SALARY: Rs.";
	cin >> addemp[i].salary;
	cout << "\n ENTER EMPLOYEE BIRTHDATE: ";
	cin >> addemp[i].birth;

	ofstream employees("employee.txt", ios::app); // WRITING EMPLOYEES IN A FILE CALLED "employee.txt"
	employees << endl << "Employee ID: " << addemp[i].eid << endl
		<< "Employee Name: " << addemp[i].ename << endl
		<< "Employee Contact N0: " << addemp[i].contact << endl
		<< "Employee Salary: " << addemp[i].salary << endl
		<< "Employee Birthdate: " << addemp[i].birth << endl
		<< ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch << ch;

	ofstream cashier("cashierid&name.txt", ios::app); // WRITING EMPLOYEES NAME & ID IN A FILE CALLED "cashierid&name.txt" FOR CASHIER'S LOGIN PURPOSE
	cashier << addemp[i].ename << " " << addemp[i].eid << endl;

	cout << "\n New Cashier is added successfuly!!!";

}

//after admin login successful=====================================================================
void adminLogin() {
	int op, choice2, choice3;
	string choice, choice1;

	cout << "\n\n\t" << ch << ch << " ADMINISTRATOR'S MENU";
	cout << "\n\n\t\t Press 1 To View Bakery Items";
	cout << "\n\n\t\t Press 2 To Add New Bakery Items";
	cout << "\n\n\t\t Press 3 To Add Cashiers";
	cout << "\n\n\t\t Press 4 To View Cashier Details";
	cout << "\n\n\t\t Press 5 To Go To Main Manu";
	cout << "\n\n\t\t Press 6 To View The Instructions";
	cout << "\n\n\n\t Please Enter Your Choice: ";
	cin >> op;

	switch (op) {
	case 2:
		entireHead(); // BUN CLUB HEADING
		addProMenu(); // ADDING PRODUCTS

		cout << "\n Do you want to add another product? ( y / n )";
		cin >> choice;

		while (true) {
			if (choice == "y" || choice == "Y") {
				addProMenu(); // IF USER ENTER "y" OR "Y", AGAIN MOVE TO THE PRODUCT ADDING FUNCTION.
				cout << "\n Do you want to add another product? ( y / n ): ";
				cin >> choice;
			}
			else if (choice == "n" || choice == "N") {
				entireHead();
				adminLogin(); // BACK TO THE ADMIN MENU
			}
			else {
				cout << "\n Invalid input!! Please follow the instruction!!";
				cout << "\n Do you want to add another product? ( y / n ): ";
				cin >> choice;
			}
		}

	case 3:
		entireHead(); // BUN CLUB HEADING
		addCashierMenu(); // ADDING CASHIERS

		cout << "\n Do you want to add another cashier? ( y / n )";
		cin >> choice1;

		while (true) {
			if (choice1 == "y" || choice1 == "Y") {
				addCashierMenu(); // IF USER ENTER "y" OR "Y", AGAIN MOVE TO THE CASHIER ADDING FUNCTION.
				cout << "\n Do you want to add another cashier? ( y / n ): ";
				cin >> choice1;
			}
			else if (choice1 == "n" || choice1 == "N") {
				entireHead();
				adminLogin(); // BACK TO ADMIN MENU
			}
			else {
				cout << "\n Invalid input!! Please follow the instruction!!";
				cout << "\n Do you want to add another cashier? ( y / n ): ";
				cin >> choice1;
			}
		}

	case 4:
		entireHead();
		viewCash(); // SHOWING CASHIERS' INFO

		cout << "\n\n Press 1 to move to the administrator's menu: \n";
		cout << " Press 2 to move to the main menu \n";
		cout << "\n Insert your choice: ";
		cin >> choice3;

		while (true) {
			switch (choice3) {
			case 1:
				entireHead(); // IF USER ENTER "1", USER FALL TO THE ADMIN MENU (VIEW ITEMS / ADD ITEMS / ETC.)
				adminLogin();

			case 2:
				system("cls"); // SYSTEM CLEAR
				lrfMenu();	// IF USER ENTER "2", USER FALL TO THE ADMIN MAIN MENU (LOGIN / REGISTRATION / ETC.)

			default:
				cout << "\n\n Invalid Input!! Please follow the instructions!!";
				cout << "\n Press 1 to move to the administrator's menu: \n";
				cout << " Press 2 to move to the main menu \n";
				cout << "Insert your choice: ";
				cin >> choice3;
				continue;
			}
		}

	case 1:
		entireHead();
		viewPro();

		cout << "\n\n Press 1 to move to the administrator's menu: \n";
		cout << " Press 2 to move to the main menu \n";
		cout << "\n Insert your choice: ";
		cin >> choice2;

		while (true) {
			switch (choice2) {
			case 1:
				entireHead();
				adminLogin();

			case 2:
				system("cls");
				lrfMenu();

			default:
				cout << "\n Invalid Input!! Please follow the instructions!!";
				cout << "\n\n Press 1 to move to the administrator's menu: \n";
				cout << " Press 2 to move to the main menu \n";
				cout << "\n Insert your choice: ";
				cin >> choice2;
				continue;
			}
		}

	case 5:
		system("cls");
		lrfMenu();

	default:
		system("cls");
		cout << "Invalid Input!! Please follow the instructions!! \n\n";
		billHead();
		cout << " BUN TALK BILLING SYSTEM ";
		billHead();
		adminLogin();

	case 6:
		entireHead();
		cout << "\n\n\t " << ch << ch << " INSTRUCTIONS";
		cout << "\n\n\t\t " << "1) Administrator is key character of this system. \n"
			<< "\n\n\t\t " << "2) Administrator can add new bakery items and new cashiers. \n"
			<< "\n\n\t\t " << "3) He can also see the details of the added products and cashiers. \n"
			<< "\n\n\t\t " << "4) When entering products, if there are several words for the respective product, separate them with '_' sign.Never leave spaces between words. \n"
			<< "\n\n\t\t " << "5) When entering cashiers' names, separate parts of the name with a '_' sign.Never leave spaces between words. \n";

		cout << "\n\n Press 1 to move to the administrator's menu: \n";
		cout << " Press 2 to move to the main menu \n";
		cout << "\n Insert your choice: ";
		cin >> choice2;

		while (true) {
			if (choice2 == 1) {
				entireHead();
				adminLogin();
			}
			else if (choice2 == 2) {
				system("cls");
				lrfMenu();
			}
			else {
				cout << "\n\n Invalid Input!! Please follow the instructions!!";
				cout << "\n Press 1 to move to the administrator's menu: \n";
				cout << " Press 2 to move to the main menu \n";
				cout << "\n Insert your choice: ";
				cin >> choice2;
				continue;
			}
		}
	}
}

void table() { //===========================================================
	system("cls");
	entireHead();
	int pid;
	string  pname;
	float pprice;
	fstream products;
	products.open("cashierSelectProducts.txt", ios::in);
	cout << "\n\n\t" << ch << ch << " Products List \n\n";
	cout << " Product ID \t\t Product Name \t\t Product Price\n";


	while (products >> pid >> pname >> pprice) {
		cout << "  " << pid << "\t\t\t   " << pname << "\t\t\t" << pprice << endl;
	}
}

// after cashier login successful==================================================================
void cashierLogin() {
	int op, choice2, choice3 = 0;

	cout << "\n\n\t " << ch << ch << " CAHSIER'S MENU";
	cout << "\n\n\t\t Press 1 to View Bakery Items";
	cout << "\n\n\t\t Press 2 to Select Bakery Items";
	cout << "\n\n\t\t Press 3 to Exit";
	cout << "\n\n\t\t Press 4 to  View The Instructions";
	cout << "\n\n\t\t Please Enter Your Choice: ";
	cin >> op;

	switch (op) {
	case 1:
		entireHead();
		viewPro();

		cout << "\n\n Press 1 to move to the Cashier's menu: \n";
		cout << " Press 2 to move to the main menu \n";
		cout << "\n Insert your choice: ";
		cin >> choice2;

		while (true) {
			switch (choice2) {
			case 1:
				entireHead();
				cashierLogin();

			case 2:
				system("cls");
				lfeMenu();

			default:
				cout << "\n\t" << ch << ch << " Invalid Input!! Please follow the instructions!!";
				cout << "\n\n Press 1 to move to the Cashier's menu: \n";
				cout << " Press 2 to move to the main menu \n";
				cout << "\n Insert your choice: ";
				cin >> choice2;
				continue;
			}
		}


	case 2:
		while (true) {
			fstream products;
			int arrpcode[100], arrpquan[100]{}, count = 0;
			string choice, pname, choice2;
			int c = 0, pid;
			float amount = 0, total = 0, pprice;


			products.open("cashierSelectProducts.txt", ios::in);

			if (!products) {
				cout << "\n\n\t" << ch << ch << " Empty Products!!";
			}
			else {
				products.close();

				table();

				while (true) {
					count++;
					cout << "\n\n Enter Product Code: ";
					cin >> arrpcode[c];
					bool validProduct = false;
					products.open("cashierSelectProducts.txt", ios::in);

					if (!products) {
						cout << "\n\n\t" << ch << ch << " Empty Products!!";
						break;
					}

					while (products >> pid >> pname >> pprice) {
						if (pid == arrpcode[c]) {
							validProduct = true;
							break;
						}
					}

					products.close();

					if (!validProduct) {
						cout << "\n Wrong product id, please check and re-enter!!\n";
						continue;
					}

					cout << "\n Enter Product Quantity: ";
					cin >> arrpquan[c];
					c++;
					cout << " Do you want to add another product? (y / any key) ";
					cin >> choice;
					if (choice == "y" || choice == "Y") {
						continue;
					}
					else {
						break;
					}

				}
				system("cls");
				entireHead();
				cout << "\n\n\t\t************************* RECEIPT ************************* \n";
				cout << "\n Product No \t Product Name \t Product Quantity \t Product Price \t\t Total \n";

				products.open("cashierSelectProducts.txt", ios::in);

				for (int i = 0; i < count; i++) {
					products.clear();
					products.seekg(0, ios::beg);
					products >> pid >> pname >> pprice;
					while (products) {
						if (pid == arrpcode[i]) {
							amount = pprice * arrpquan[i];
							total += amount;
							cout << "  " << pid << "\t\t    " << pname << "\t\t" << arrpquan[i] << "\t\t\t" << pprice << "\t\t  " << amount << "\n";
							break;
						}
						products >> pid >> pname >> pprice;
					}
				}

				products.close();

				cout << "\n\t\t\t\t\t\t\t      Total Amount is: Rs." << total;

				cout << "\n\n\n\n  " << ch << ch << " Do you want to create another bill ? (y / n) ";
				cin >> choice2;


				if (choice2 == "y") {
					continue;
				}

				while (true) {
					if (choice2 == "y") {
						break;
					}
				
					else if (choice2 == "n") {
						system("cls");
						entireHead();
						cashierLogin();
					}
					else {
						cout << "\n\t" << ch << ch << " Invalid Input!! Please follow the instructions!!";
						cout << "\n\n\n\n  " << ch << ch << " Do you want to create another bill ? (y / n) ";
						cin >> choice2;
						continue;

					}
				}
				continue;
			}
		}

	case 3:
		cout << "\n\n\t\t === Thank you!! Have a Greate day!! ===\n\n";
		exit(op);

	default:
		system("cls");
		cout << "Invalid Input!! Please follow the instructions!! \n\n";
		billHead();
		cout << " BUN TALK BILLING SYSTEM ";
		billHead();
		cashierLogin();

	case 4:
		entireHead();
		cout << "\n\n\t " << ch << ch << " INSTRUCTIONS";
		cout << "\n\n\t\t " << "1) Cashier is the employee in this system. \n"
			<< "\n\n\t\t " << "2) The cashier should log in to the system using the username and password provided by the administrator. \n"
			<< "\n\n\t\t " << "3) If the cashier forgets the password given to him, he is given the convenience of retrieving the password by entering his username through the Forgot Password option. \n";

		cout << "\n\n Press 1 to move to the Cashier's menu: \n";
		cout << " Press 2 to move to the main menu \n";
		cout << "\n Insert your choice: ";
		cin >> choice2;

		while (true) {
			if (choice2 == 1) {
				entireHead();
				cashierLogin();
			}
			else if (choice2 == 2) {
				system("cls");
				lfeMenu();
			}
			else {
				cout << "\n\n Invalid Input!! Please follow the instructions!!";
				cout << "\n Press 1 to move to the Cashier's menu: \n";
				cout << " Press 2 to move to the main menu \n";
				cout << "\n Insert your choice: ";
				cin >> choice2;
				continue;
			}
		}
	}
}

//=========================================================================================================================
int main() {

	billHead();
	aceMenu();

	return 0;
}
//=========================================================================================================================

// login form
void login() { //================================================== ADMIN LOGIN =============================================
	int count = 0;
	string userID, password, id, pass;
	entireHead();

	cout << "\n\n\t\t Please Enter Username and Password: " << endl;
	cout << "\n\t\t XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	cout << "\n\t\t X *Remember You have only THREE attempts to insert your username and password!! X";
	cout << "\n\t\t X So, please insert your username and password with attention                   X";
	cout << "\n\t\t XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;


	for (int i = 0; i < 3; i++) {
		cout << "\t\t\t USERNAME: ";
		cin >> userID;
		cout << "\t\t\t PASSWORD: ";
		cin >> password;

		ifstream input("records.txt");

		while (input >> id >> pass) {
			if (id == userID && pass == password) {
				count = 1;
			}
		}
		input.close();

		if (count == 1) {
			entireHead();
			cout << endl << endl << " " << userID << " Your login is successfull \n Thanks for login in! \n";
			adminLogin();
		}
		else {
			cout << "\n\t Login error \n\t Please check your username and password \n\n";
		}
	}
	cout << "\n\t\t" << ch << ch << " Your attempts are finish!! please re-start the program. \n\n";
	exit(count);
}

// login form
void loginC() { //====================================================== CASHIER LOGIN ===================================================
	int count = 0;
	string userID, password, id, pass;
	entireHead();

	cout << "\n\n\t\t Please Enter Username and Password: " << endl;
	cout << "\n\t\t XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	cout << "\n\t\t X *Remember You have only THREE attempts to insert your username and password!! X";
	cout << "\n\t\t X So, please insert your username and password with attention                   X";
	cout << "\n\t\t XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;


	for (int i = 0; i < 3; i++) {
		cout << "\t\t\t NAME: ";
		cin >> userID;
		cout << "\t\t\t CASHIER ID: ";
		cin >> password;

		ifstream cashier("cashierid&name.txt");//read

		while (cashier >> id >> pass) {
			if (id == userID && pass == password) {
				count = 1;
				system("cls");
			}
		}
		cashier.close();

		if (count == 1) {
			entireHead();
			cout << endl << endl << " " << userID << " Your login is successfull \n Thanks for login in! \n";
			cashierLogin();
		}
		else {
			cout << "\n\t Login error \n\t Please check your username and password \n\n";
		}
	}
	cout << "\n\t\t" << ch << ch << " Your attempts are finish!! please re-start the program. \n\n";
	exit(count);
}

//register form
void registration() {
	string ruserID, rpassword, rid, rpass;
	system("cls");
	billHead();
	cout << " BUN TALK BILLING SYSTEM ";
	billHead();

	cout << "\n\n\t\t Enter The username: ";
	cin >> ruserID;
	cout << "\t\t Enter the password: ";
	cin >> rpassword;

	ofstream f1("records.txt", ios::app);//write 
	f1 << ruserID << " " << rpassword << endl;
	system("cls");

	cout << "\n\t\t\t    Registration is successful! \n\n";
	lrfMenu();
}

// Forgot form
void forgot() { //================================================ Admin Forgot =======================================
	int option;
	entireHead();
	cout << "\n\n\t\t\t You forgot the password? Don't worry!! \n";
	cout << "\n\t" << ch << ch << " Press 1 to search your password by username \n";
	cout << "\n\t" << ch << ch << " Press 2 to go back to main menu \n";
	cout << "\n\t\t\t Enter Your choice: ";
	cin >> option;

	while (true) {
		switch (option) {
		case 1: {
			int count = 0;
			string suserId, sid, spass;
			cout << "\n\t Enter the Username which you remembered: ";
			cin >> suserId;

			ifstream f2("records.txt");
			while (f2 >> sid >> spass) {
				if (sid == suserId) {
					count = 1;
					cout << "\n Your account is found!! \n";
					cout << " Your Password is: " << spass << endl << endl;
				}
			}
			f2.close();

			if (count == 0) {
				cout << "\n Sorry, Your account is not found!! \n";
				cout << " First of all, You have to Register!! \n\n";
			}

			lrfMenu();
			break;
		}

		case 2: {
			system("cls");
			billHead();
			aceMenu();
		}

		default:
			cout << "\n\t\t\t\t Wrong input!!! Please follow the instructions!!! \n";
			cout << "\n\t\t\t Enter Your Choice: ";
			cin >> option;
			continue;
		}
	}
}

// Forgot form
void forgotC() { //================================================ Cashier Forgot =======================================
	int option;
	entireHead();
	cout << "\n\n\t\t\t You forgot the password? Don't worry!! \n";
	cout << "\n\t" << ch << ch << " Press 1 to search your id by your name \n";
	cout << "\n\t" << ch << ch << " Press 2 to exit from the system \n";
	cout << "\n\t\t\t Enter Your choice: ";
	cin >> option;

	while (true) {
		switch (option) {
		case 1: {
			int count = 0;
			string suserId, sid, spass;
			cout << "\n\t Enter Your Name: ";
			cin >> suserId;

			ifstream f2("cashierid&name.txt");
			while (f2 >> sid >> spass) {
				if (sid == suserId) {
					count = 1;
					cout << "\n Your account is found!! \n";
					cout << " Your Password is: " << spass << endl << endl;
				}
			}
			f2.close();

			if (count == 0) {
				cout << "\n Sorry Your account is not found!! \n\n";
			}

			lfeMenu();
			break;
		}

		case 2: {
			cout << "\n\n\t\t === Thank you!! Have a Greate day!! ===\n\n";
			exit(option);
		}

		default:
			cout << "\n\t\t\t\t Wrong input!!! Please follow the instructions!!! \n";
			cout << "\n\t\t\t Enter Your Choice: ";
			cin >> option;
			continue;
		}

	}
}

//main menu		ADMIN | CASHIER
void aceMenu() { // FIRST EXECUTION
	int option;
	cout << " BUN TALK BILLING SYSTEM ";
	billHead();
	cout << "\n\n\t" << ch << ch << " ROLE MENU";
	cout << "\n\n\t\t 1) Administrator \n";
	cout << "\n\n\t\t 2) Cashier \n";
	cout << "\n\n\t\t 3) Exit \n\n";
	billHead(); billHead();
	cout << "\n\n\t Please Enter Your Job Role: ";
	cin >> option;

	switch (option) {
	case 1: //=================================================  ADMIN ============================================
		int op;
		entireHead();
		cout << "\n\n\t" << ch << ch << " ADMINISTRATOR'S LOGIN PAGE";
		cout << "\n\n\t\t Press 1 To Login";
		cout << "\n\n\t\t Press 2 To Register";
		cout << "\n\n\t\t Press 3 To Forget Password";
		cout << "\n\n\t\t Press 4 To Role Menu";
		cout << "\n\n\t\t Press 5 To Exit";

		cout << "\n\n\n Enter The Number Which You Want To Do: ";
		cin >> op;

		switch (op) {
		case 1:
			login(); //ADMIN LOGIN
			break;

		case 2:
			registration(); //ADMIN REGISTRATION
			break;

		case 3:
			forgot(); //ADMIN FORGOT PASSWORD
			break;

		case 4:
			system("cls"); // AGAIN MOVE TO THE ROLE MENU
			billHead();
			aceMenu();
			break;

		case 5:
			cout << "\n\n\t\t === Thank you!! Have a Greate day!! ===\n\n"; // GREETING & EXIT
			exit(option);
			break;

		default:
			system("cls"); // INVALID INPUT
			cout << "Invalid Input!! Please follow the instructions!! \n\n";
			lrfMenu();
		}

	case 2: //============================================== CASHIER =======================================
		int op1;
		entireHead();
		cout << "\n\n\t" << ch << ch << " Cashier'S LOGIN PAGE";
		cout << "\n\n\t\t Press 1 To Login";
		cout << "\n\n\t\t Press 2 To Forget Password";
		cout << "\n\n\t\t Press 3 To Exit";

		cout << "\n\n\n Enter The Number Which You Want To Do: ";
		cin >> op1;

		switch (op1) {
		case 1:
			loginC(); // CASHIER LOGIN
			break;

		case 2:
			forgotC(); // CASHIER FORGOT PASSWORD
			break;

		case 3:
			cout << "\n\n\t\t === Thank you!! Have a Greate day!! ===\n\n"; //GREETING & EXIT
			exit(op1);
			break;

		default:
			system("cls"); // INVALID INPUT
			cout << "Invalid Input!! Please follow the instructions!! \n\n";
			lfeMenu();
		}

	case 3:
		cout << "\n\n\t\t === Thank you!! Have a Greate day!! ===\n\n"; // MAIN MENU GREETING & EXIT
		break;

	default:
		system("cls"); // MAIN MENU INVALID INPUT
		cout << " Invalid Input!! Please follow the instructions!! \n\n";
		billHead();
		aceMenu();
	}
}