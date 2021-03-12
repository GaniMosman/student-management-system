

#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include <vector>

using namespace std;

class Student : public User{
	
	string degree;
	int creditHour[4]; // array that stores student's total credit hours for each trimester
	int currentTerm; // stores current trimester
	
	public:
	
	/**
	constructs a new student without assigning data
	*/
	Student();
	
	/**
    constructs a new student with assigning values 

		@param data that describes new user general information and new student specific information
	*/
	Student(string id, string password, string name, string faculty, string email,	string phoneNo, string degree, int currentTerm);
		
	/**
    A function that displays the main page which is specific to students

		@param list of system users objects, list of available faculties in the system
	*/	
	void mainMenu(vector<User*> &user, vector<Faculty*> &faculty);
	
	/**
    Allows students to register new courses in the selected trimester within their faculties

		@param list of system users objects, student faculty, trimester number in which courses will be registered
	*/
	void registerCourse(vector<User*> user, Faculty* &faculty, int term);
	
	/**
    Allows students to view his/her registered courses in the selected trimester within their faculties

		@param list of system users objects, student faculty, trimester number in which registered courses will be displayed
	*/
	void viewEnrollment(vector<User*> user, Faculty* faculty, int term);
	
	/**
    Calculates student's credit hours for each trimester

		@param student faculty
	*/
	void calculateCH(Faculty* faculty);
	
	/**
    Checks if student's ID exists in the given list of IDs or not

		@param List of student IDs 
		@return true if student's ID exists in the given list of IDs,
		false if student's ID does not exist in the given list of IDs 
	*/
	bool findStudent(vector<string> studentIDs);
	
	/**
    Checks if student finishes all the prerequisites or not before registering to new course

		@param student faculty, list of all prerequisites IDs
		@return true if student finishes all the prerequisites of the course
		false if student does not finish at least one prerequisite of the course
	*/
	bool checkPrerequisites(Faculty* faculty, vector<string> prerequisites);
	
	/**
    A function that saves students's data

		@param output file stream in which data will be saved
	*/
	void saveToFile(ofstream& saveFile);
	
};

#include "Student.cpp"
#endif