#ifndef USERACCOUNT_H
#define USERACCOUNT_H
#include <stdlib.h>
#include <string>
using namespace std;

//class user account
class UserAccount {
	// declaring private variables
private:
	int ID;
	string username;
	string password;
	//public constructor and login to access it later
public:
	//constructor
	UserAccount(int accID, const string& user, const string& pass)
		: ID(accID), username(user), password(pass) {}

	//login function 
	bool Login(const string& inputUserName, const string& inputPass)
	{
		// return true if the values match else false
		return (inputUserName == username && inputPass == password);
	}


	int getAccountID() const {
		return ID;
	}
};

#endif