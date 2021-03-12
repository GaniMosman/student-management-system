

#include "Faculty.h"

Faculty::Faculty(){}

Faculty::Faculty(string id, string name, vector<Trimester*> trimester){
	
	this->id = id;
	this->name = name;
	for(int i=0; i<trimester.size(); ++i){
		this->trimester.push_back(trimester[i]);
	}
}

string Faculty::getId(){
	return this->id;
}
	
string Faculty::getName(){
	return this->name;
}
	
vector<Trimester*> Faculty::getTrimester(){
	return this->trimester;
}

