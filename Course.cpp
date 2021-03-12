

#include "Course.h"

Course::Course(){}

Course::Course(string id, string name, string program, int creditHour, bool status, Session* lecture, Session* tutorial){
	
	this->id = id;
	this->name = name;
	this->program = program;
	this->creditHour = creditHour;
	this->status = status;
	this->lecture = lecture;
	this->tutorial = tutorial;
	this->courseApproval= 0;
}

Course::Course(string id, string name, string program, int creditHour, bool status, vector<string> prerequisites, vector<string> student, Session* lecture, Session* tutorial){
	
	this->id = id;
	this->name = name;
	this->program = program;
	this->creditHour = creditHour;
	this->status = status;
	this->student = student;
	this->prerequisites = prerequisites;
	this->lecture = lecture;
	this->tutorial = tutorial;
}


string Course::getId(){
	return this->id;
}
	
string Course::getName(){
	return this->name;
}

string Course::getProgram(){
	return this->program;
}

int Course::getCH(){
	return this->creditHour;
}

bool Course::getStatus(){
	return this->status;
}

void Course::setName(string name){
	this->name = name;
}

void Course::setProgram(string program){
	this->program = program;
}

void Course::setCH(int creditHour){
	this->creditHour = creditHour;
}

void Course::setStatus(bool status){
	this->status = status;
}
	

Session* Course::getLecture(){
	return this->lecture;
}

Session* Course::getTutorial(){
	return this->tutorial;
}
		
vector<string> Course::getStudent(){
	return this->student;
}

void Course::addStudent(string student){
	this->student.push_back(student);
}

void Course::addPrerequisites(string course){
	this->prerequisites.push_back(course);
}

vector<string> Course::getPrerequisites(){
	return this->prerequisites;
}

void Course::setCourseApproval(int courseApproval){
	this->courseApproval = courseApproval;
}

int Course::getCourseApproval(){
	return this->courseApproval;
}