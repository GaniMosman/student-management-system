

#ifndef TRIMESTER_H
#define TRIMESTER_H

using namespace std;

#include "Course.h"
#include <vector>

class Trimester{
	
	string id;
	string name;
	string startDate;
	string endDate;
	vector<Course*> course;
	
	public:
	
	/**
	constructs a new trimester without assigning data
	*/
	Trimester();
	
	/**
    constructs a new trimester with assigning values 

		@param data that describes new trimester
	*/
	Trimester(string id, string name, string startDate,	string endDate, vector<Course*> course);
	
	/**
    returns trimester's ID to be used in other operations

		@return returns trimester's ID
	*/
	string getId();
	
	/**
    returns trimester's name to be used in other operations

		@return returns trimester's name
	*/
	string getName();
	
	/**
    returns trimester's starting date to be used in other operations

		@return returns trimester's starting date
	*/
	string getSDate();
	
	/**
    returns trimester's ending date to be used in other operations

		@return returns trimester's ending date
	*/
	string getEDate();
	
	/**
    returns trimester's courses list to be used in other operations

		@return trimester's courses
	*/
	vector<Course*> getCourse();
	
	/**
    Adds new course to trimester

		@param new course
	*/
	void addCourse(Course* course);
	
	/**
    Update trimester's courses list

		@param trimester's updated courses list
	*/
	void addAllCourses(vector<Course*> courses);
};

#include "Trimester.cpp"
#endif