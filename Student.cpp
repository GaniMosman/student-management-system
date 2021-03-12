

#include "Student.h"
#include <algorithm>

Student::Student(){
	User();
}

Student::Student(string id, string password, string name, string faculty, string email,	string phoneNo, string degree, int currentTerm) : 
	User(id, password, name, faculty, email, phoneNo){
	this->degree = degree;
	this->currentTerm = currentTerm;
	for(int i=0; i<4; ++i){
		this->creditHour[i] = 0;
	}
}

void Student::mainMenu(vector<User*> &user, vector<Faculty*> &faculty){
	
	int choice;
	string facultyName;
	
	for(int i=0; i<faculty.size(); ++i){
		if(faculty[i]->getId() == getFaculty()){
			facultyName = faculty[i]->getName();
		}
	}

	do
	{
		for(int i=0; i<faculty.size(); ++i){
			if(faculty[i]->getId() == getFaculty()){
				calculateCH(faculty[i]);
			}
		}
		system("cls");
	    cout << endl << endl
		<< "      << "<<getName()<<" you are a student in "<<facultyName<<" >>"
	    << endl << endl
		<< " You are currently registered to following courses ";
		for(int i=0; i<faculty.size(); ++i){
			if(faculty[i]->getId() == getFaculty()){
				viewEnrollment(user, faculty[i], currentTerm);
			}
		}
		cout<< endl << endl
		<< " 1 - Register Courses.\n"
		<< " 2 - View Courses.\n"
		<< " 3 - Logout.\n\n"
		<< " Enter your choice and press return: ";
		cin >> choice;
		if(cin.fail()){
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(10000,'\n');//Max_In exception ***
		}
		switch (choice)
		{
			case 1:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						if(term < currentTerm){
							cout <<endl<<endl<< " Please select your current trimester or coming trimesters. \n\n";
							system("pause");
						}
						else{
							registerCourse(user, faculty[i], term);
						}
					}
				}
			}
			break;
			case 2:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						system("cls");
						viewEnrollment(user, faculty[i], term);
						system("pause");
					}
				}
			}
			break;
			case 3:
			break;
			default:
			cout <<endl<<endl<< "  Not a Valid Choice. \n"
			<< "  Choose again.\n\n";
			system("pause");
			break;
		}

	}while (choice != 3);
	
}

void Student::registerCourse(vector<User*> user, Faculty* &faculty, int term){
	
	vector<Course*> courses = faculty->getTrimester()[term]->getCourse();
	
	system("cls");
	cout<<endl<<endl;
	cout<<"  "
	<< left	<< setw(10) << "ID"
	<< setw(30) << "Name"
	<< setw(30) << "Program"
	<< setw(10) << "CH"
	<< setw(30) << "Prerequisites"
	<< setw(20) << "Session"
	<< setw(10) << "ID"
	<< setw(30) << "Time"
	<< setw(20) << "Vanue"
	<< setw(20) << "Status"
	<< setw(30) << "Lecturer Name"
	<< setw(30) << "Email"
	<< setw(20) << "Phone No"
	<< endl;
	
	for(int i=0; i<courses.size(); ++i){
		
		if(courses[i]->getCourseApproval() != 0){
				
			if(courses[i]->getProgram() == this->degree){	
				
				Session* lecture = courses[i]->getLecture();
				
				cout<<endl<<endl;
				cout<<"  "
				<< left	<< setw(10) << courses[i]->getId()
				<< setw(30) << courses[i]->getName()
				<< setw(30) << courses[i]->getProgram()
				<< setw(10) << courses[i]->getCH();
				vector<string> prerequisites = courses[i]->getPrerequisites();
				string collect="N/A";
				if(!prerequisites.empty()){
					collect= prerequisites[0];
					for(int j=1; j<prerequisites.size(); ++j){
						collect = collect + " " + prerequisites[j];
					}
				}
				cout << setw(30) << collect
				<< setw(20) << "Lecture"
				<< setw(10) << lecture->getId()
				<< setw(30) << lecture->getTime()
				<< setw(20) << lecture->getVanue();
				
				if(courses[i]->getStatus()){
					cout<< setw(20) << "Open";
				}
				else{
					cout<< setw(20) << "Close";
				}		

				for(int j=0; j<user.size(); ++j){
					if(user[j]->getId() == lecture->getLecturer()){
						cout<< setw(30) << user[j]->getName()
						<< setw(30) << user[j]->getEmail()
						<< setw(20) << user[j]->getPhoneNo()
						<< endl;
					}
				}
				
				Session* tutorial = courses[i]->getTutorial();
				
				cout<<endl;
				cout<<"  "
				<< left	<< setw(10) << courses[i]->getId()
				<< setw(30) << courses[i]->getName()
				<< setw(30) << courses[i]->getProgram()
				<< setw(10) << courses[i]->getCH()
				<< setw(30) << collect
				<< setw(20) << "Tutorial"
				<< setw(10) << tutorial->getId()
				<< setw(30) << tutorial->getTime()
				<< setw(20) << tutorial->getVanue();
				
				if(courses[i]->getStatus()){
					cout<< setw(20) << "Open";
				}
				else{
					cout<< setw(20) << "Close";
				}
				
				for(int j=0; j<user.size(); ++j){
					if(user[j]->getId() == tutorial->getLecturer()){
						cout<< setw(30) << user[j]->getName()
						<< setw(30) << user[j]->getEmail()
						<< setw(20) << user[j]->getPhoneNo()
						<< endl;
					}
				}
			}
		}
	}
	
	string id = "";
	cin.clear();
	cin.ignore(1000, '\n');
	cout<<endl<<endl;
	cout<< " Enter course ID you want to register: ";
	getline(cin, id);
	
	for(int i=0; i<courses.size(); ++i){
		if(courses[i]->getId() == id && courses[i]->getProgram() == this->degree){
			if(courses[i]->getStatus()){ // *** another if
				if(!findStudent(courses[i]->getStudent())){
					if((this->creditHour[term] + courses[i]->getCH()) <= 22){
						if(checkPrerequisites(faculty, courses[i]->getPrerequisites())){
							courses[i]->addStudent(getId());
							faculty->getTrimester()[term]->addAllCourses(courses);
							currentTerm = term;
							cout<<endl<<endl;
							cout<< "  You have registered to "<<courses[i]->getName()<<" successfully.";
							cout<<endl<<endl;
							system("pause");
							return;
						}
						else{
							cout<<endl<<endl;
							cout<<"  You cannot register to "<<courses[i]->getName()<<" course because of prerequisites.";
							cout<<endl<<endl;
							system("pause");
							return;
						}
						
					}
					else{
						cout<<endl<<endl;
						cout<<"  You cannot register to "<<courses[i]->getName()<<" course because of credit hours limit. Current credit hours is "<<this->creditHour[term];
						cout<<endl<<endl;
						system("pause");
						return;
					}
				}
				else{
					cout<<endl<<endl;
					cout<<"  You have registered to "<<courses[i]->getName()<<" course before.";
					cout<<endl<<endl;
					system("pause");
					return;
				}
			}
			else{
				cout<<endl<<endl;
				cout<<"  "<<courses[i]->getName()<<" course is closed.";
				cout<<endl<<endl;
				system("pause");
				return;
			}
		}
	}
	cout<<endl<<endl;
	cout<<endl<<endl<<"  course not found!"<<endl<<endl;
	system("pause");
}

void Student::viewEnrollment(vector<User*> user, Faculty* faculty, int term){
	
	vector<Course*> courses = faculty->getTrimester()[term]->getCourse();
	
	cout<<endl<<endl;
	cout<<"  "
	<< left	<< setw(10) << "ID"
	<< setw(30) << "Name"
	<< setw(30) << "Program"
	<< setw(10) << "CH"
	<< setw(30) << "Prerequisites"
	<< setw(20) << "Session"
	<< setw(10) << "ID"
	<< setw(30) << "Time"
	<< setw(20) << "Vanue"
	<< setw(20) << "Status"
	<< setw(30) << "Lecturer Name"
	<< setw(30) << "Email"
	<< setw(20) << "Phone No"
	<< endl;
	
	for(int i=0; i<courses.size(); ++i){
		
		if(courses[i]->getCourseApproval() != 0){
			
			if(findStudent(courses[i]->getStudent()))
			{				
				Session* lecture = courses[i]->getLecture();
				
				cout<<endl<<endl;
				cout<<"  "
				<< left	<< setw(10) << courses[i]->getId()
				<< setw(30) << courses[i]->getName()
				<< setw(30) << courses[i]->getProgram()
				<< setw(10) << courses[i]->getCH();
				vector<string> prerequisites = courses[i]->getPrerequisites();
				string collect="N/A";
				if(!prerequisites.empty()){
					collect= prerequisites[0];
					for(int j=1; j<prerequisites.size(); ++j){
						collect = collect + " " + prerequisites[j];
					}
				}
				cout << setw(30) << collect
				<< setw(20) << "Lecture"
				<< setw(10) << lecture->getId()
				<< setw(30) << lecture->getTime()
				<< setw(20) << lecture->getVanue();
				
				if(courses[i]->getStatus()){
					cout<< setw(20) << "Open";
				}
				else{
					cout<< setw(20) << "Close";
				}		

				for(int j=0; j<user.size(); ++j){
					if(user[j]->getId() == lecture->getLecturer()){
						cout<< setw(30) << user[j]->getName()
						<< setw(30) << user[j]->getEmail()
						<< setw(20) << user[j]->getPhoneNo()
						<< endl;
					}
				}
				
				Session* tutorial = courses[i]->getTutorial();
				
				cout<<endl;
				cout<<"  "
				<< left	<< setw(10) << courses[i]->getId()
				<< setw(30) << courses[i]->getName()
				<< setw(30) << courses[i]->getProgram()
				<< setw(10) << courses[i]->getCH()
				<< setw(30) << collect
				<< setw(20) << "Tutorial"
				<< setw(10) << tutorial->getId()
				<< setw(30) << tutorial->getTime()
				<< setw(20) << tutorial->getVanue();
				
				if(courses[i]->getStatus()){
					cout<< setw(20) << "Open";
				}
				else{
					cout<< setw(20) << "Close";
				}
				
				for(int j=0; j<user.size(); ++j){
					if(user[j]->getId() == tutorial->getLecturer()){
						cout<< setw(30) << user[j]->getName()
						<< setw(30) << user[j]->getEmail()
						<< setw(20) << user[j]->getPhoneNo()
						<< endl;
					}
				}
			}
		}
	}
	cout<<endl<<endl;
}

// ***
void Student::calculateCH(Faculty* faculty){
	
	for(int j=0; j<faculty->getTrimester().size(); ++j){
		
		int totalCH = 0;
		
		vector<Course*> courses = faculty->getTrimester()[j]->getCourse();
		
		for(int i=0; i<courses.size(); ++i){
		
			if(findStudent(courses[i]->getStudent()))
			{
				totalCH += courses[i]->getCH();
			}
		}
		
		this->creditHour[j] = totalCH;
	}
}

bool Student::findStudent(vector<string> studentIDs){
	for(int i=0; i<studentIDs.size(); ++i){
		if(studentIDs[i] == getId()){
			return true;
		}
	}
	return false;
}

void Student::saveToFile(ofstream& saveFile){
	
	saveFile<<getId()
	<<endl
	<<getName()
	<<endl
	<<getPassword()
	<<endl
	<<getFaculty()
	<<endl
	<<getEmail()
	<<endl
	<<getPhoneNo()
	<<endl
	<<this->currentTerm
	<<this->degree
	<<endl;
};

bool Student::checkPrerequisites(Faculty* faculty, vector<string> prerequisites){
	
	if(prerequisites.empty()){
		system("pause");
		return true;
	}
	
	for(int term=0; term<faculty->getTrimester().size(); ++term){
		vector<Course*> courses = faculty->getTrimester()[term]->getCourse();
		
		for(int i=0; i<prerequisites.size(); ++i){
			for(int j=0; j<courses.size(); ++j){
				if(courses[j]->getId() == prerequisites[i]){
					if(!findStudent(courses[j]->getStudent())){
						return false;
					}
				}
			}
		}
	}
	return true;
}
