#include <iostream>
#include <stdlib.h>
#include <string>
#include "UserAccount.h"
using namespace std;



int main() {
	int accountID;
	string userName, passWord;
	//loops until user enter all fields correctly
	while (true) {
		cout << "Enter Account ID: ";
		cin >> accountID;
		cin.ignore(); // Clear the newline from input buffer

		// this ensures no failure in Input to avoid crashing of program
		if (cin.fail()) {
			cin.clear(); // Clear error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
			system("cls"); //found this on internet to clear the console , makes program readable in console
			cout << "Invalid input. Please try again." << endl;
		}
		else {
			// there were no conditions how a username must look , so there is no validation for username and password 
			cout << "Enter Username: ";
			getline(cin, userName);

			cout << "Enter Password: ";
			getline(cin, passWord);
			system("cls");
			break; // breaks out of loop
		}
	}

	// Create a UserAccount object
	UserAccount acc(accountID, userName, passWord);

	// Login process
	string enteredUserName, enteredPassword;

	//again loops until everything meets
	while (true) {
		
		cout << "\nLog in to your account" << endl;
		cout << "Enter Username: ";
		getline(cin, enteredUserName);

		cout << "Enter Password: ";
		getline(cin, enteredPassword);

		if (acc.Login(enteredUserName, enteredPassword))  // using the login function that we created earlier 
		{
			cout << "Login successful!\n";
			cout << "Account ID: " << acc.getAccountID() << endl;
			break; // get out of loop
		}
		else {
			// if password and username doesnt meet , it will prompt user again to enter and keeps on looping
			system("cls");\

			cout << "Invalid username or password. Please try again.\n";
		}
	}

	return 0;
}

// i think its done

