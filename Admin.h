

#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

using namespace std;
#include <vector>

class Admin: public User{

	string role;
	public:

	/**
	constructs a new admin of faculty without assigning data
	*/
	Admin();

	/**
    constructs a new admin with assigning values

		@param data that describes new admin general information and new admin specific information
	*/
	Admin(string id, string password, string name, string faculty, string email, string phoneNo, string role);

	/**
    A function that displays the main page which is specific to admin

		@param list of system users objects, list of available faculties in the system
	*/
	void mainMenu(vector<User*> &user, vector<Faculty*> &faculty);

	/**
    Allows admin to view user's information from different faculties

		@param list of system users objects
	*/
	void print_User(vector<User*> &user);

	/**
    Allows admin to add new academician to the faculty

		@param list of system users objects
	*/
	void addAcademician(vector<User*> &user);

	/**
    Allows admin to delete existing academician from the faculty

		@param list of system users objects, faculty that admin manages
	*/
	void deleteAcademician(vector<User*> &user, Faculty* &faculty);

	/**
    Deletes academician courses after the academician is deleted by admin

		@param faculty that admin manages, academician id
	*/
	void deleteCourses(Faculty* &faculty, string id);

	/**
    Allows admin to add new student to the faculty

		@param list of system users objects
	*/
	void addStudent(vector<User*> &user);

	/**
    Allows admin to delete existing student from the faculty

		@param list of system users objects, faculty that admin manages
	*/
	void deleteStudent(vector<User*> &user);

	/**
    Allows admin to view courses information in selected trimester within his/her faculty

		@param list of system users objects, faculty that admin manages, selected trimester number
	*/
	void viewCourses(vector<User*> user, Faculty* faculty, int term);

	/**
    Allows admin to view student registered in specific courses in selected trimester within his/her faculty

		@param list of system users objects, faculty that admin manages, selected trimester number
	*/
	void viewStudentsInCourse(vector<User*> user, Faculty* faculty, int term);

	/**
    Allows admin to edit user's information form his/her faculties

		@param list of system users objects
	*/
	void editUsers(vector<User*> &user);

	/**
    Allows admin to view user's information form his/her faculties

		@param list of system users objects
	*/
	void print_faculty_user(vector<User*> &user);

	void viewRequests(Faculty* &faculty);

	void viewCourses(Faculty* faculty, int approvalStatus);

	void approveCourseDeletion(Faculty* &faculty);

	void approveNewCourses(Faculty* &faculty);
	/**
    A function that saves admin's data

		@param output file stream in which data will be saved
	*/
	void saveToFile(ofstream& saveFile){};
};

#include "Admin.cpp"
#endif
