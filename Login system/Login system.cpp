#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgot();

int main() {
	int c;
	cout << "\t\t\t____________________________________\n\n\n";
	cout << "\t\t\t      Welcome to the login page     \n\n\n";
	cout << "\t\t\t________________Menu________________\n\n";
	cout << "                                          \n\n";
	cout << "\t| Press 1 to Login                      |" << endl;
	cout << "\t| Press 2 to Register                   |" << endl;
	cout << "\t| Press 3 if you forgot your Password   |" << endl;
	cout << "\t| Press 4 to Exit                       |" << endl;
	cout << "\n\t\t\t Please enter your choice : ";
	cin >> c;
	cout << endl;

	switch (c) {
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
		cout << "\t\t\t Thank You! \n\n";
		break;

	default:
		system("cls");
		cout << "\t\t\t Please select from the options given above \n" << endl;
		main();
	}
}

void login() {
	int count;
	string userID, password, id, pass;
	system("cls");
	cout << "\t\t\t Please enter the username and password : " << endl;
	cout << "\t\t\t Username : ";
	cin >> userID;
	cout << "\t\t\t Password : ";
	cin >> password;

	ifstream input("credential.txt");

	while (input >> id >> pass) {
		if (id == userID && pass == password) {
			count = 1;
			system("cls");
		}
	}
	input.close();

	if (count == 1) {
		cout << userID << "\n Your Login is successfull \n Thank you! \n";
		main();
	}
	else {
		cout << "\n Login error \n Please check your credential \n";
		main();
	}
}

void registration() {
	string registerUserID, registerPassword, rid, rpass;
	system("cls");
	cout << "\t\t\t Enter the username : ";
	cin >> registerUserID;
	cout << "\t\t\t Enter the password : ";
	cin >> registerPassword;

	ofstream file1("credential.txt", ios::app);
	file1 << registerUserID << ' ' << registerPassword << endl;
	system("cls");
	cout << "\n\t\t\t Registration is successfull! \n";
	main();

}
void forgot() {
	int option;
	system("cls");
	cout << "\t\t\t You forgot the password? No worries \n";
	cout << "Press 1 to search your ID by username" << endl;
	cout << "Press 2 to go back to the main menu" << endl;
	cout << "\t\t\t Enter your choice : ";
	cin >> option;
	switch (option) {
	case 1 : {
			int count = 0;
			string forgotUserID, forgotPassword, fid, fpass;
			cout << "\n\t\t\t Enter the username which you remembered : ";
			cin >> forgotUserID;

			ifstream file2("credential.txt");
			while (file2 >> fid >> fpass) {
				if (fid == forgotUserID) {
					count = 1;
				}
			}
			file2.close();
			if (count = 1) {
				cout << "\n\n Your account is found! \n";
				cout << "\n\n Your password is : " << fpass;
				main();
			}
			else {
				cout << "\n\t Sorry! your account is not found! \n";
				main();
			}
			break;
		}
	case 2 : {
		main();
	}
	default:
		   cout << "\t\t\t wrong choice! Please try again" << endl;
		   forgot();
  }
}