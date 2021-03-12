


#ifndef ACADEMICIAN_H
#define ACADEMICIAN_H

#include "User.h"
#include <vector>

using namespace std;

class Academician: public User{
	
	string officeNo;
	string speciality;
	int totalCourses[4];
	//Trimester
	public:
	
	/**
	constructs a new academician without assigning data
	*/
	Academician();
	
	/**
    constructs a new academician with assigning values 

		@param data that describes new user general information and new academician specific information
	*/
	Academician(string id, string password, string name, string faculty, string email,	string phoneNo, string officeNo, string speciality);
		
	/**
    A function that displays the main page which is specific to academician

		@param list of system users objects, list of available faculties in the system
	*/	
	void mainMenu(vector<User*> &user, vector<Faculty*> &faculty);
	
	/**
    Allows academician to add new course to the selected trimester 

		@param academician faculty, selected trimester number
	*/
	void addCourse(Faculty* &faculty, int term);
	
	/**
    Allows academician to view all courses taugh by him/her in the selected trimester within the faculty

		@param academician faculty, selected trimester number
	*/
	void viewCourses(Faculty* faculty, int term);
	
	/**
    Allows academician to delete his/here course in the selected trimester within the faculty

		@param academician faculty, selected trimester number
	*/
	void deleteCourse(Faculty* &faculty, int term);
	
	/**
    Allows academician to edit his/here course information in the selected trimester within the faculty

		@param academician faculty, selected trimester number
	*/
	void editCourse(Faculty* &faculty, int term);
	
	/**
    Allows academician to edit his/here course status in the selected trimester within the faculty

		@param academician faculty, selected trimester number
	*/
	void editCourseStatus(Faculty* &faculty, int term);
	
	/**
    Allows academician to view all students registered in his/her courses in the selected trimester within the faculty

		@param list of system users objects, academician faculty, selected trimester number
	*/
	void viewYourStudents(vector<User*> user, Faculty* faculty, int term);
	
	/**
    calculates the total number of courses academician teach in each trimester within the faculty

		@param academician faculty
	*/
	void calTotalCourses(Faculty* faculty);
	
	/**
    Allows academician to view all courses in the selected trimester within the faculty

		@param list of system users objects, academician faculty, selected trimester number
	*/
	void viewAllCourses(vector<User*> user, Faculty* faculty, int term);
	
	/**
    Allows academician to view all courses in the selected trimester within the faculty

		@param list of system users objects, academician faculty, selected trimester number
	*/
	void viewAllCourses(Faculty* faculty);
	
	/**
    A function that saves academician's data

		@param output file stream in which data will be saved
	*/
	void saveToFile(ofstream& saveFile);
};

#include "Academician.cpp"
#endif