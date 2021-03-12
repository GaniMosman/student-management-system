

#ifndef FACULTY_H
#define FACULTY_H

using namespace std;

#include "Trimester.h"
#include <vector>

class Faculty{

	string id;
	string name;
	vector<Trimester*> trimester;

	public:

	/**
	constructs a new faculty without assigning data
	*/
	Faculty();

	/**
    constructs a new faculty with assigning values

		@param data that describes new faculty
	*/
	Faculty(string id, string name, vector<Trimester*> trimester);

	/**
    returns faculty's ID to be used in other operations

		@return returns faculty's ID
	*/
	string getId();

	/**
    returns faculty's name to be used in other operations

		@return returns faculty's name
	*/
	string getName();

	/**
    returns faculty's trimesters list to be used in other operations

		@return returns faculty's trimesters
	*/
	vector<Trimester*> getTrimester();
};

#include "Faculty.cpp"
#endif
