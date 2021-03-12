

#include "Session.h"

Session::Session(){}

Session::Session(string id, string time, string vanue, string lecturer){
	
	this->id = id;
	this->time = time;
	this->vanue = vanue;
	this->lecturer = lecturer;
}

string Session::getId(){
	return this->id;
}
	
string Session::getTime(){
	return this->time;
}

string Session::getVanue(){
	return this->vanue;
}

void Session::setId(string id){
	this->id = id;
}

void Session::setTime(string time){
	this->time = time;
}

void Session::setVanue(string vanue){
	this->vanue = vanue;
}
		
string Session::getLecturer(){
	return this->lecturer;
}
