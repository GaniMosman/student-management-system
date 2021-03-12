

#include "Academician.h"

Academician::Academician(){
	User();
}

Academician::Academician(string id, string password, string name, string faculty, string email,	string phoneNo, string officeNo, string speciality) : 
	User(id, password, name, faculty, email, phoneNo){
	
	this->officeNo = officeNo;
	this->speciality = speciality;
	
	for(int i=0; i<4; ++i){
		this->totalCourses[i] = 0;
	}
	
}

void Academician::mainMenu(vector<User*> &user, vector<Faculty*> &faculty){
	
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
				calTotalCourses(faculty[i]);
			}
		}
		
		system("cls");
	    cout << endl << endl
		<< "      << "<<getName()<<" you are an academician in "<<facultyName<<" >>"
	    << endl << endl
		<< " 1 - Add Courses.\n"
		<< " 2 - Delete Courses.\n"
		<< " 3 - Change Courses Info.\n"
		<< " 4 - Change Courses Status.\n"
		<< " 5 - View Courses.\n"
		<< " 6 - View Students.\n"
		<< " 7 - Logout.\n\n"
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
						addCourse(faculty[i], term);
					}
				}
			}
			break;
			case 2:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						deleteCourse(faculty[i], term);
					}
				}
			}
			break;
			case 3:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						editCourse(faculty[i], term);
					}
				}
			}
			break;
			case 4:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						editCourseStatus(faculty[i], term);
					}
				}
			}
			break;
			case 5:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						viewAllCourses(user, faculty[i], term);
					}
				}
			}
			break;
			case 6:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						viewYourStudents(user, faculty[i], term);
					}
				}
			}
			break;
			case 7:
			cout<<"Logout.";
			break;
			default:
			cout << "Not a Valid Choice. \n"
			<< "Choose again.\n\n";
			system("pause");
			break;
		}

	}while (choice != 7);
}

void Academician::addCourse(Faculty* &faculty, int term){
	
	
	if(this->totalCourses[term] + 1 > 3){
		cout<<endl<<endl<<"  You are not allowed to teach more then 3 course per trimester."<<endl<<endl;
		system("pause");
		return;
	}
	system("cls");
	
	string lastId = "";
	string id, name, degree, sID, sTime, sVanue;
	int degreeNo = 0, ch;
			
	cin.clear();
	cin.ignore(1000, '\n');
	cout<<endl<<endl<< " Enter course id: ";
	getline(cin, id);
	cout<< " Enter course name: ";
	getline(cin, name);		
	cout<< " Enter course credit hours: ";
	cin >> ch;
	if(cin.fail()){
		cout<<endl<<endl;
		cout<< "input error";
		cout<<endl<<endl;
		system("pause");
		cout<<endl<<endl;
		cin.clear();
		cin.ignore(10000,'\n');
		return;
	}
	
	do{
		cout<< " Choose student program:\n"
		<< " 1 - Diploma.\n"
		<< " 2 - Undergraduate.\n"
		<< " 3 - Post-graduate.\n"
		<< " >> ";
		cin >> degreeNo;
		if(cin.fail()){
			cout<< "input error";
			cout<<endl<<endl;
			system("pause");
			cout<<endl<<endl;
			cin.clear();
			cin.ignore(10000,'\n');
			return;
		}
	}while(degreeNo < 1 || degreeNo > 3);
	
	cin.clear();
	cin.ignore(1000, '\n');
	cout<< " Enter lecture session id: ";
	getline(cin, sID);
	cout<< " Enter lecture session time: ";
	getline(cin, sTime);
	cout<< " Enter lecture session vanue: ";
	getline(cin, sVanue);
	cin.clear();
	
	Session* lecture = new Session(sID, sTime, sVanue, getId());
	
	cout<< " Enter tutorial session id: ";
	getline(cin, sID);
	cout<< " Enter tutorial session time: ";
	getline(cin, sTime);
	cout<< " Enter tutorial session vanue: ";
	getline(cin, sVanue);
	
	Session* tutorial = new Session(sID, sTime, sVanue, getId());
	
	switch(degreeNo){
		case 1:
		degree = "diploma";
		break;
		case 2:
		degree = "undergraduate";
		break;
		case 3:
		degree = "post-graduate";
		break;
		default:
		degree = "N/A";
		break;
	}
	
	Course* course = new Course(id, name, degree, ch, true, lecture, tutorial);
	
	string prerequisites="";
	char addMore;
	
	cout<< " Do you want to add prerequisite course? (Y/N): ";
	cin>> addMore;
	
	while(addMore == 'y' || addMore == 'Y'){
		string input;
		viewAllCourses(faculty);
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter prerequisite course id: ";
		getline(cin, input);
		course->addPrerequisites(input);
		cout<< " Do you want to add  another perequisite course? (Y/N): ";
		cin>> addMore;
	}
	
	course->setCourseApproval(0);
	faculty->getTrimester()[term]->addCourse(course);
	cout<<endl<<endl<<"  "<<course->getName()<<" course addition request is sent to admin successfully."<<endl<<endl;

	system("pause");
}

void Academician::viewCourses(Faculty* faculty, int term){
	
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
	<< endl;
	
	for(int i=0; i<courses.size(); ++i){
		
		if(courses[i]->getCourseApproval() != 0){
			
			Session* lecture = courses[i]->getLecture();
			
			if(lecture->getLecturer() == getId()){	
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
					cout<< setw(20) << "Open"
					<< endl;
				}
				else{
					cout<< setw(20) << "Close"
					<< endl;
				}			
			}
			
			Session* tutorial = courses[i]->getTutorial();
			
			if(tutorial->getLecturer() == getId()){	
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
				<< setw(20) << "Tutorial"
				<< setw(10) << tutorial->getId()
				<< setw(30) << tutorial->getTime()
				<< setw(20) << tutorial->getVanue();
				
				if(courses[i]->getStatus()){
					cout<< setw(20) << "Open"
					<< endl;
				}
				else{
					cout<< setw(20) << "Close"
					<< endl;
				}
			}
		}
	}
	
	cout<<endl<<endl;
}

void Academician::deleteCourse(Faculty* &faculty, int term){
	
	string id = "";

	viewCourses(faculty, term);
	
	vector<Course*> courses = faculty->getTrimester()[term]->getCourse();
	
	if(!courses.empty()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter course ID to be deleted: ";
		getline(cin, id);
		for(int i=0; i<courses.size(); ++i){
			
			if(courses[i]->getId() == id){
				
				Session* lecture = courses[i]->getLecture();
			
				if(lecture->getLecturer() == getId()){
					courses[i]->setCourseApproval(2);
					faculty->getTrimester()[term]->addAllCourses(courses);
					cout<<endl<<endl<<"  "<<courses[i]->getName()<<" course deletion request is sent to admin successfully.."<<endl<<endl;
					system("pause");
					return;
				}
				
				Session* tutorial = courses[i]->getTutorial();
				
				if(tutorial->getLecturer() == getId()){	
					courses[i]->setCourseApproval(2);
					faculty->getTrimester()[term]->addAllCourses(courses);
					cout<<endl<<endl<<"  "<<courses[i]->getName()<<" course deletion request is sent to admin successfully."<<endl<<endl;
					system("pause");
					return;
				}
				
			}
		}
	}
	
	cout<<endl<<endl<<"  course not found!"<<endl<<endl;
	system("pause");
}


void Academician::editCourse(Faculty* &faculty, int term){
	
	string id = "";

	viewCourses(faculty, term);
	
	vector<Course*> courses = faculty->getTrimester()[term]->getCourse();
	
	if(!courses.empty()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter course ID to be edited: ";
		getline(cin, id);
		for(int i=0; i<courses.size(); ++i){
			
			if(courses[i]->getId() == id){
				
				Session* lecture = courses[i]->getLecture();
				Session* tutorial = courses[i]->getTutorial();
				
				if(lecture->getLecturer() == getId() || tutorial->getLecturer() == getId()){	
				
					int choice;

					do
					{
						system("cls");
						cout << endl << endl
						<< " 1 - Course Name.\n"
						<< " 2 - Course Credit Hours.\n"
						<< " 3 - Lecture Session ID.\n"
						<< " 4 - Lecture Session Time.\n"
						<< " 5 - Lecture Session Vanue.\n"
						<< " 6 - Tutorial Session ID.\n"
						<< " 7 - Tutorial Session Time.\n"
						<< " 8 - Tutorial Session Vanue.\n"
						<< " 9 - Exit.\n"
						<< " Select course information: ";
						cin >> choice;
						if(cin.fail()){
							cin.clear(); // clear input buffer to restore cin to a usable state
							cin.ignore(10000,'\n');//Max_In exception ***
						}
						
						string data = "";
						switch (choice)
						{
							case 1:
							cout << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout<< " Enter course name: ";
							getline(cin, data);
							courses[i]->setName(data);
							cout<<endl<<endl;
							cout<< "  course name is changed successfully.";
							cout<<endl<<endl;
							system("pause");
							break;
							case 2:
							int ch;
							cout << endl << endl;
							cout<< " Enter course credit hours: ";
							cin >> ch;
							if(cin.fail()){
								cout<<endl<<endl;
								cout<< "  input error";
								cout<<endl<<endl;
								system("pause");
								return;
							}
							courses[i]->setCH(ch);
							cout<<endl<<endl;
							cout<< "  credit hours is changed successfully.";
							cout<<endl<<endl;
							system("pause");
							break;
							case 3:
							cout << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout<< " Enter lecture session id: ";
							getline(cin, data);
							lecture->setId(data);
							cout<<endl<<endl;
							cout<< "  lecture session id is changed successfully.";
							cout<<endl<<endl;
							system("pause");
							break;
							case 4:
							cout << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout<< " Enter lecture session time: ";
							getline(cin, data);
							lecture->setTime(data);
							cout<<endl<<endl;
							cout<< "  lecture session time is changed successfully.";
							cout<<endl<<endl;
							system("pause");
							break;
							case 5:
							cout << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout<< " Enter lecture session vanue: ";
							getline(cin, data);
							lecture->setVanue(data);
							cout<<endl<<endl;
							cout<< "  lecture session vanue is changed successfully.";
							cout<<endl<<endl;
							system("pause");
							break;
							case 6:
							cout << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout<< " Enter tutorial session id: ";
							getline(cin, data);
							tutorial->setId(data);
							cout<<endl<<endl;
							cout<< "  tutorial session id is changed successfully.";
							cout<<endl<<endl;
							system("pause");
							break;
							case 7:
							cout << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout<< " Enter tutorial session time: ";
							getline(cin, data);
							tutorial->setTime(data);
							cout<<endl<<endl;
							cout<< "  tutorial session time is changed successfully.";
							cout<<endl<<endl;
							system("pause");
							break;
							case 8:
							cout << endl << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout<< " Enter tutorial session vanue: ";
							getline(cin, data);
							tutorial->setVanue(data);
							cout<<endl<<endl;
							cout<< "  tutorial session vanue is changed successfully.";
							cout<<endl<<endl;
							system("pause");
							break;
							case 9:
							break;
							default:
							cout << endl << endl << "  Not a Valid Choice. \n"
							<< "  Choose again.\n\n";
							system("pause");
							break;
						}
					}while (choice != 9);
					faculty->getTrimester()[term]->addAllCourses(courses);
					cout<<endl<<endl<<"  "<<courses[i]->getName()<<" course information is changed successfully."<<endl<<endl;
					system("pause");
					return;
				}
			}
		}
	}
	cout<<endl<<endl<<"  course not found!"<<endl<<endl;
	system("pause");
}


void Academician::editCourseStatus(Faculty* &faculty, int term){
	
	string id = "";

	viewCourses(faculty, term);
	
	vector<Course*> courses = faculty->getTrimester()[term]->getCourse();
	
	if(!courses.empty()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter course ID to be edited: ";
		getline(cin, id);
		for(int i=0; i<courses.size(); ++i){
			
			if(courses[i]->getId() == id){
				
				int choice;

				system("cls");
				cout << endl << endl
				<< " 1 - Open Course.\n"
				<< " 2 - Close Course.\n"
				<< " Select course status: ";
				cin >> choice;
				if(cin.fail()){
					cin.clear(); // clear input buffer to restore cin to a usable state
					cin.ignore(10000,'\n');//Max_In exception ***
				}
				
				switch (choice)
				{
					case 1:
					courses[i]->setStatus(true);
					faculty->getTrimester()[term]->addAllCourses(courses);
					cout<<endl<<endl;
					cout<< "  course is opened successfully.";
					cout<<endl<<endl;
					system("pause");
					break;
					case 2:
					courses[i]->setStatus(false);
					faculty->getTrimester()[term]->addAllCourses(courses);
					cout<<endl<<endl;
					cout<< "  course is closed successfully.";
					cout<<endl<<endl;
					system("pause");
					break;
					default:
					cout << endl << endl << "  Not a Valid Choice. \n"
					<< "  Choose again.\n\n";
					system("pause");
					break;
				}
				return;
			}
		}
	}
	cout<<endl<<endl<<"  course not found!"<<endl<<endl;
	system("pause");
}

void Academician::viewAllCourses(vector<User*> user, Faculty* faculty, int term){
	
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
	
	cout<<endl<<endl;
	system("pause");
}

void Academician::viewAllCourses(Faculty* faculty){
	
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
	<< endl;
	
	for(int term=0; term<faculty->getTrimester().size(); ++term){
		
		vector<Course*> courses = faculty->getTrimester()[term]->getCourse();
		
		for(int i=0; i<courses.size(); ++i){
			
			if(courses[i]->getCourseApproval() != 0){
				
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
			}
		}
	}
	cout<<endl<<endl;
}

void Academician::viewYourStudents(vector<User*> user, Faculty* faculty, int term){
	
	string id = "";

	viewCourses(faculty, term);
	
	vector<Course*> courses = faculty->getTrimester()[term]->getCourse();
	
	if(!courses.empty()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter course ID to view registered students: ";
		getline(cin, id);
		for(int i=0; i<courses.size(); ++i){
			
			if(courses[i]->getCourseApproval() != 0){
			
				if(courses[i]->getId() == id){
					
					Session* lecture = courses[i]->getLecture();
					Session* tutorial = courses[i]->getTutorial();
					
					if(lecture->getLecturer() == getId() || tutorial->getLecturer() == getId()){
						
						system("cls");
						cout<<endl<<endl;
						cout<<"  "
						<< left	<< setw(10) << "ID"
						<< setw(30) << "Name"
						<< setw(30) << "Email"
						<< setw(20) << "Phone No";
						
						vector<string> studentIDs(courses[i]->getStudent());
							
						for(int j=0; j<user.size(); ++j){
							
							if(find(studentIDs.begin(), studentIDs.end(), user[j]->getId()) != studentIDs.end()){
								
								cout<<endl<<endl;
								cout<<"  "
								<< left	<< setw(10) << user[j]->getId()
								<< setw(30) << user[j]->getName()
								<< setw(30) << user[j]->getEmail()
								<< setw(20) << user[j]->getPhoneNo();
									
							}

						}
						
						cout<<endl<<endl;
						system("pause");
						return;
					}
					
				}
			}
		}
	}
	cout<<endl<<endl<<"  course not found!"<<endl<<endl;
	system("pause");
}

void Academician::calTotalCourses(Faculty* faculty){
	
	for(int j=0; j<faculty->getTrimester().size(); ++j){
		
		int numCourses = 0;
		
		vector<Course*> courses = faculty->getTrimester()[j]->getCourse();
		
		for(int i=0; i<courses.size(); ++i){
			
			if(courses[i]->getCourseApproval() != 0){
				
				Session* lecture = courses[i]->getLecture();
				Session* tutorial = courses[i]->getTutorial();
			
				if(lecture->getLecturer() == getId() || tutorial->getLecturer() == getId())
				{
					numCourses++;
				}
			}
		}
		
		this->totalCourses[j] = numCourses;
	}
}

void Academician::saveToFile(ofstream& saveFile){
	
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
	<<this->officeNo
	<<endl
	<<this->speciality
	<<endl;
};

