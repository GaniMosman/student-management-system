
#include "User.h"
#include <iomanip>
#include "windows.h"
#include <sstream>

User::User(){}

User::User(string id, string password, string name, string faculty, string email, string phoneNo){

	this->id = id;
	this->password = password;
	this->name = name;
	this->faculty = faculty;
	this->email = email;
	this->phoneNo = phoneNo;
}

bool User::login(string id, string password){

	if(this->id == id && this->password == password)
		return true;
	else
		return false;

}

string User::getId(){
	return this->id;
}
string User::getPassword(){
	return this->password;
}
string User::getName(){
	return this->name;
}
string User::getFaculty(){
	return this->faculty;
}
string User::getEmail(){
	return this->email;
}
string User::getPhoneNo(){
	return this->phoneNo;
}

int User::selectTrimester(Faculty* faculty){

	vector<Trimester*> trimesters;

	for(int i=0; i<faculty->getTrimester().size(); ++i){
		trimesters.push_back(faculty->getTrimester()[i]);
	}

	system("cls");
	cout<<endl<<endl;
	cout<<"  "
	<< left << setw(10) << "No"
	<< setw(10) << "ID"
	<< setw(30) << "Description"
	<< setw(30) << "Start Date"
	<< setw(30) << "End Date"
	<< endl;

	for(int i=0; i<trimesters.size(); ++i){

		cout<<endl<<endl;
		cout<<"  "
		<< left << setw(10) << i+1
		<< setw(10) << trimesters[i]->getId()
		<< setw(30) << trimesters[i]->getName()
		<< setw(30) << trimesters[i]->getSDate()
		<< setw(30) << trimesters[i]->getEDate()
		<< endl;
	}

	cout<<endl<<endl;

	if(!trimesters.empty()){

		int term;
		cout<<"  Select the required trimester: ";
		cin>>term;
		if(cin.fail() || term>trimesters.size() || term < 1){
			cout<< "input error";
			cout<<endl<<endl;
			system("pause");
			return -1;
		}
		return term-1;
	}
	else{
		cout<<"  There is no ongoing trimester! ";
		system("pause");
		return 0;
	}
}

void User::setPassword(string password){
	this->password = password;
}

void User::setName(string name){
	this->name = name;
}

void User::setEmail(string email){
	this->email = email;
}

void User::setPhoneNo(string phoneNo){
	this->phoneNo = phoneNo;
}

