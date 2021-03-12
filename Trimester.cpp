

#include "Trimester.h"

Trimester::Trimester(){}

Trimester::Trimester(string id, string name, string startDate, string endDate, vector<Course*> course){

	this->id = id;
	this->name = name;
	this->startDate = startDate;
	this->endDate = endDate;
	this->course = course;
}

string Trimester::getId(){
	return this->id;
}

string Trimester::getName(){
	return this->name;
}

string Trimester::getSDate(){
	return this->startDate;
}

string Trimester::getEDate(){
	return this->endDate;
}

vector<Course*> Trimester::getCourse(){
	return this->course;
}

void Trimester::addCourse(Course* course){
	this->course.push_back(course);
}

void Trimester::addAllCourses(vector<Course*> courses){

	this->course.clear();

	for(int i=0; i<courses.size(); ++i){
		this->course.push_back(courses[i]);
	}

}

