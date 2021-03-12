

#ifndef COURSE_H
#define COURSE_H

using namespace std;

#include "Session.h"
#include <vector>

class Course{
	
	string id;
	string name;
	string program;
	int creditHour;
	bool status;
	Session* lecture;
	Session* tutorial;
	vector<string> student;
	vector<string> prerequisites;
	int courseApproval; // change to 0 when is added by lecturer, to 1 when it is add by admin and to 2 when it is deleted by lecturer 
	
	public:
	
	/**
	constructs a new course without assigning data
	*/
	Course();
	
	/**
    constructs a new course with assigning values without students and prerequisites

		@param data that describes new course
	*/
	Course(string id, string name, string program, int creditHour, bool status, Session* lecture, Session* tutorial);
	
	/**
    constructs a new course with assigning values with students and prerequisites

		@param data that describes new course
	*/
	Course(string id, string name, string program, int creditHour, bool status, vector<string> prerequisites, vector<string> student, Session* lecture, Session* tutorial);
	
	/**
    returns course's ID to be used in other operations

		@return course's ID
	*/
	string getId();
	
	/**
    returns course's name to be used in other operations

		@return course's name
	*/
	string getName();
	
	/**
    returns course's program to be used in other operations

		@return course's program
	*/
	string getProgram();
	
	/**
    returns course's credit hours to be used in other operations

		@return course's credit hours
	*/
	int getCH();
	
	/**
    returns course's status to be used in other operations

		@return course's status
	*/
	bool getStatus();
	
	/**
    sets new course's name or edits current course's name

		@param the new course's name
	*/
	void setName(string name);
	
	/**
    sets new course's program or edits current course's program

		@param the new course's program
	*/
	void setProgram(string program);
	
	/**
    sets new course's credit hours or edits current course's credit hours

		@param the new course's credit hours
	*/
	void setCH(int creditHour);
	
	/**
    sets new course's status or edits current course's status

		@param the new course's status
	*/
	void setStatus(bool status);
	
	/**
    returns course's lecture session to be used in other operations

		@return course's lecture session
	*/
	Session* getLecture();
	
	/**
    returns course's tutorial session to be used in other operations

		@return course's tutorial session
	*/
	Session* getTutorial();
	
	/**
    returns list of students IDs registered to the course to be used in other operations

		@return course's students list
	*/
	vector<string> getStudent();
	
	/**
    adds new students to the course

		@param student's ID
	*/
	void addStudent(string student);
	
	/**
    adds prerequisite to the course

		@param prerequisite course's ID
	*/
	void addPrerequisites(string course);
	
	/**
    returns list of prerequisites of the course

		@return list of prerequisites of the course
	*/
	vector<string> getPrerequisites();
	
	/**
    returns course's approval status

		@return course's approval status
	*/
	int getCourseApproval();
	
	/**
    sets course's approval status by admin

		@param course's approval status
	*/
	void setCourseApproval(int courseApproval);
};

#include "Course.cpp"
#endif