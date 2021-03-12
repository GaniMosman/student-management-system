
#ifndef USER_H
#define USER_H

using namespace std;

#include "Faculty.h"
#include <vector>

class User{

	string id;
	string password;
	string name;
	string faculty;
	string email;
	string phoneNo;

	public:

	/**
	constructs a new user without assigning data
	*/
	User();

	/**
    constructs a new user with assigning values

		@param data that describes new user
	*/
	User(string id, string password, string name, string faculty, string email,	string phoneNo);

	/**
    checks user authority to login to the system using user's ID and password

		@param user's ID and password
		@return returns true if user's ID and password are correct,
		returns fasle if user's ID or password is incorrect,
	*/
	bool login(string id, string password);

	/**
    returns user's ID to be used in other operations

		@return returns user's ID
	*/
	string getId();

	/**
    returns user's password to be used in other operations

		@return returns user's password
	*/
	string getPassword();

	/**
    returns user's name to be used in other operations

		@return returns user's name
	*/
	string getName();

	/**
    returns user's faculty to be used in other operations

		@return returns user's faculty
	*/
	string getFaculty();

	/**
    returns user's email to be used in other operations

		@return returns user's email
	*/
	string getEmail();

	/**
    returns user's phone number to be used in other operations

		@return returns user's number
	*/
	string getPhoneNo();

	/**
    sets new user's password or edits current user's password

		@param the new user's password
	*/
	void setPassword(string password);

	/**
    sets new user's name or edits current user's name

		@param the new user's name
	*/
	void setName(string name);

	/**
    sets new user's email or edits current user's email

		@param the new user's email
	*/
	void setEmail(string email);

	/**
    sets new user's phone number or edits current user's phone number

		@param the new user's phone number
	*/
	void setPhoneNo(string phoneNo);

	/**
    Allow user to select a trimester for list of available trimesters in order to be used for other operations

		@param the selected trimester number
	*/
	int selectTrimester(Faculty*  faculty);

	/**
    A virtual function that displays the main page of the user based on his/her access type(admin, academician or student)

		@param list of system users objects, list of available faculties in the system
	*/
	virtual void mainMenu(vector<User*> &user, vector<Faculty*> &Facult){};

	/**
    A virtual function that saves user's data based on his/her access type(admin, academician or student)

		@param output file stream in which data will be saved
	*/
	virtual void saveToFile(ofstream& saveFile){};
};

#include "User.cpp"
#endif

