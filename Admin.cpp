

#include "Admin.h"

#include <iomanip>
#include "windows.h"
#include <sstream>

Admin::Admin(){
	User();
}

Admin::Admin(string id, string password, string name, string faculty, string email, string phoneNo, string role = "N/A") :
	User(id, password, name, faculty, email, phoneNo){

	this->role = role;

}

void Admin::mainMenu(vector<User*> &user, vector<Faculty*> &faculty){

	int choice;
	string facultyName;

	for(int i=0; i<faculty.size(); ++i){
		if(faculty[i]->getId() == getFaculty()){
			facultyName = faculty[i]->getName();
		}
	}

	do
	{
		system("cls");
		cout << endl << endl
		<< "      << "<<getName()<<" you are an admin in "<<facultyName<<" >>"
	    << endl << endl
		<< " 1 - Add Academician.\n"
		<< " 2 - Delete Academician.\n"
		<< " 3 - Add Student.\n"
		<< " 4 - Delete Student.\n"
		<< " 5 - Edit User Info.\n"
		<< " 6 - View Users Info.\n"
		<< " 7 - View Courses.\n"
		<< " 8 - View Students by Courses.\n"
		<< " 9 - User Requests.\n"
		<< " 10 - Logout.\n\n"
		<< " Enter your choice and press return: ";
		cin >> choice;
		if(cin.fail()){
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(10000,'\n');//Max_In exception ***
		}

		switch (choice)
		{
			case 1:
			addAcademician(user);
			break;
			case 2:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					deleteAcademician(user, faculty[i]);
					break;
				}
			}
			break;
			case 3:
			addStudent(user);
			break;
			case 4:
			deleteStudent(user);
			break;
			case 5:
			editUsers(user);
			break;
			case 6:
			print_User(user);
			break;
			case 7:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						viewCourses(user, faculty[i], term);
						system("pause");
						break;
					}

				}
			}
			break;
			case 8:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					int term = selectTrimester(faculty[i]);
					if(term != -1){
						viewStudentsInCourse(user, faculty[i], term);
						break;
					}
				}
			}
			break;
			case 9:
			for(int i=0; i<faculty.size(); ++i){
				if(faculty[i]->getId() == getFaculty()){
					viewRequests(faculty[i]);
					break;
				}
			}
			break;
			case 10:
			break;
			default:
			cout << endl << endl << "  Not a Valid Choice. \n"
			<< "  Choose again.\n\n";
			system("pause");
			break;
		}

	}while (choice != 10);
}

void Admin::print_User(vector<User*> &user) // Function to display user
{
	system("cls");
	cout << endl;
	cout<<"  <<   Admins   >>"<<endl<<endl;
	cout<<"  "
	<< left << setw(10) << "User ID"
	<< setw(30) << "Name"
	<< setw(20) << "Password"
	<< setw(30) << "Email"
	<< setw(12) << "Phone No"
	<< setw(5) << "Faculty"
	<< endl;

	for(int i=0; i<user.size(); ++i){
		if(user[i]->getId() == getId()){
			cout<<"  "
			<< left << setw(10) << user[i]->getId()
			<< setw(30) << user[i]->getName()
			<< setw(20) << user[i]->getPassword()
			<< setw(30) << user[i]->getEmail()
			<< setw(12) << user[i]->getPhoneNo()
			<< setw(5) << user[i]->getFaculty()
			<< endl;
		}
	}

	cout<<endl<<"________________________________________________________________________________________________________________"<<endl<<endl;

	cout<<"  <<   Academicians   >>"<<endl<<endl;
	cout<<"  "
	<< left << setw(10) << "User ID"
	<< setw(30) << "Name"
	<< setw(20) << "Password"
	<< setw(30) << "Email"
	<< setw(12) << "Phone No"
	<< setw(5) << "Faculty"
	<< endl;

	for(int i=0; i<user.size(); ++i){

		if(user[i]->getId().at(0) == 'L'){
			cout<<"  "
			<< left << setw(10) << user[i]->getId()
			<< setw(30) << user[i]->getName()
			<< setw(20) << user[i]->getPassword()
			<< setw(30) << user[i]->getEmail()
			<< setw(12) << user[i]->getPhoneNo()
			<< setw(5) << user[i]->getFaculty()
			<< endl;
		}
	}

	cout<<endl<<"________________________________________________________________________________________________________________"<<endl<<endl;

	cout<<"  <<   Students   >>"<<endl<<endl;
	cout<<"  "
	<< left << setw(10) << "User ID"
	<< setw(30) << "Name"
	<< setw(20) << "Password"
	<< setw(30) << "Email"
	<< setw(12) << "Phone No"
	<< setw(5) << "Faculty"
	<< endl;

	for(int i=0; i<user.size(); ++i){

		if(user[i]->getId().at(0) == 'S'){
			cout<<"  "
			<< left << setw(10) << user[i]->getId()
			<< setw(30) << user[i]->getName()
			<< setw(20) << user[i]->getPassword()
			<< setw(30) << user[i]->getEmail()
			<< setw(12) << user[i]->getPhoneNo()
			<< setw(5) << user[i]->getFaculty()
			<< endl;
		}
	}
	cout << endl << endl;
	system("pause");

}

void Admin::addAcademician(vector<User*> &user){

	system("cls");

	string lastId = "";
	string id, password, name, email, phone, officeNo, speciality;

	try{
		cout<<endl<<endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter academician name: ";
		getline(cin, name);
		cout<< " Enter academician email: ";
		getline(cin, email);
		cout<< " Enter academician phone number: ";
		getline(cin, phone);
		cout<< " Enter academician office number: ";
		getline(cin, officeNo);
		cout<< " Enter academician speciality: ";
		getline(cin, speciality);
		cout<< " Enter academician password: ";
		getline(cin, password);

		if(cin.fail()){
           throw "input error";
       }


	}
	catch( char* error){
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(10000,'\n');//Max_In exception ***
		cout<<error<<endl<<endl;
		system("pause");
		return;
	}

	for(int i=0; i<user.size(); ++i){
		if(user[i]->getId().at(0) == 'L'){
			lastId = user[i]->getId();
		}
	}

	if(lastId != ""){

		string sNumber = lastId.substr (1);
		stringstream geek(sNumber);
		int number = 0;
		geek >> number;
		stringstream ss;
		ss << number+1;
		id = "L"+ ss.str();

	}
	else{
		id = "L1";
	}


	user.push_back(new Academician(id, password, name, getFaculty(), email, phone, officeNo, speciality));

	cout<<endl<<"  New academician account created successfully"<<endl<<endl;
	system("pause");

}

void Admin::deleteAcademician(vector<User*> &user, Faculty* &faculty){

	system("cls");

	cout<< endl
	<< endl
	<<"  "
	<< left << setw(10) << "User ID"
	<< setw(30) << "Name"
	<< setw(30) << "Email"
	<< setw(12) << "Phone No"
	<< setw(5) << "Faculty"
	<< endl	<< endl;

	for(int i=0; i<user.size(); ++i){

		if(user[i]->getId().at(0) == 'L' && user[i]->getFaculty() == getFaculty()){
			cout<<"  "
			<< left << setw(10) << user[i]->getId()
			<< setw(30) << user[i]->getName()
			<< setw(30) << user[i]->getEmail()
			<< setw(12) << user[i]->getPhoneNo()
			<< setw(5) << user[i]->getFaculty()
			<< endl;
		}
	}

	string id= "";
	cout<< endl <<" Enter academician ID to delete the account: ";
	cin >> id;

	for(int i=0; i<user.size(); ++i){

		if(user[i]->getId() == id && user[i]->getFaculty() == getFaculty()){

			user.erase(user.begin()+i);
			deleteCourses(faculty, id);
			cout<<endl<<"  Academician account deleted successfully"<<endl<<endl;
			system("pause");
			return;
		}
	}

	cout<<endl<<"Academician ID not found! Please write the exact ID."<<endl<<endl;
	system("pause");

}

void Admin::addStudent(vector<User*> &user){

	system("cls");

	string lastId = "";
	string id, password, name, email, phone, degree;
	int degreeNo = 0;

	try{
		cout<<endl<<endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter student name: ";
		getline(cin, name);
		cout<< " Enter student email: ";
		getline(cin, email);
		cout<< " Enter student phone number: ";
		getline(cin, phone);
		cout<< " Enter student password: ";
		getline(cin, password);

		if(cin.fail()){
           throw "input error";
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
				return;
			}
		}while(degreeNo < 1 || degreeNo > 3);

	}
	catch( char* error){
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(10000,'\n');//Max_In exception ***
		cout<<error<<endl<<endl;
		system("pause");
		return;
	}

	for(int i=0; i<user.size(); ++i){
		if(user[i]->getId().at(0) == 'S'){
			lastId = user[i]->getId();
		}
	}

	if(lastId != ""){

		string sNumber = lastId.substr (1);
		stringstream geek(sNumber);
		int number = 0;
		geek >> number;
		stringstream ss;
		ss << number+1;
		id = "S"+ ss.str();

	}
	else{
		id = "S1";
	}

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

	user.push_back(new Student(id, password, name, getFaculty(), email, phone, degree, 0));

	cout<<endl<<"  New student account created successfully"<<endl<<endl;
	system("pause");
}

void Admin::deleteStudent(vector<User*> &user){

	system("cls");

	cout<< endl
	<< endl
	<<"  "
	<< left << setw(10) << "User ID"
	<< setw(30) << "Name"
	<< setw(30) << "Email"
	<< setw(12) << "Phone No"
	<< setw(5) << "Faculty"
	<< endl	<< endl;

	for(int i=0; i<user.size(); ++i){

		if(user[i]->getId().at(0) == 'S' && user[i]->getFaculty() == getFaculty()){
			cout<<"  "
			<< left << setw(10) << user[i]->getId()
			<< setw(30) << user[i]->getName()
			<< setw(30) << user[i]->getEmail()
			<< setw(12) << user[i]->getPhoneNo()
			<< setw(5) << user[i]->getFaculty()
			<< endl;
		}
	}

	string id= "";
	cout<< endl <<" Enter Student ID to delete the account: ";
	cin >> id;

	for(int i=0; i<user.size(); ++i){

		if(user[i]->getId() == id && user[i]->getFaculty() == getFaculty()){
			user.erase(user.begin()+i);
			cout<<endl<<"  Student account deleted successfully"<<endl<<endl;
			system("pause");
			return;
		}
	}

	cout<<endl<<" Student ID not found! Please write the exact ID."<<endl<<endl;
	system("pause");

}

void Admin::viewCourses(vector<User*> user, Faculty* faculty, int term){

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
}

void Admin::viewStudentsInCourse(vector<User*> user, Faculty* faculty, int term){

	string id = "";

	viewCourses(user, faculty, term);

	vector<Course*> courses = faculty->getTrimester()[term]->getCourse();

	if(!courses.empty()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter course ID to view registered students: ";
		getline(cin, id);
		for(int i=0; i<courses.size(); ++i){

			if(courses[i]->getId() == id){

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
	cout<<endl<<endl<<"  course not found!"<<endl<<endl;
	system("pause");
}

void Admin::deleteCourses(Faculty* &faculty, string id){ // ***  string lecturerID

	for(int j=0; j<faculty->getTrimester().size(); ++j){

		int numCourses = 0;

		vector<Course*> courses = faculty->getTrimester()[j]->getCourse();

		for(int i=0; i<courses.size(); ++i){

			Session* lecture = courses[i]->getLecture();
			Session* tutorial = courses[i]->getTutorial();

			if(lecture->getLecturer() == id || tutorial->getLecturer() == id)
			{
				courses.erase(courses.begin()+i);
				i=0;
			}
		}
		faculty->getTrimester()[j]->addAllCourses(courses);
	}
}

void Admin::editUsers(vector<User*> &user){

	system("cls");

	string id = "";

	print_faculty_user(user);

	if(!user.empty()){
		cin.clear();
		cin.ignore(1000, '\n');
		cout<< " Enter user ID to be edited: ";
		getline(cin, id);
		for(int i=0; i<user.size(); ++i){

			if(user[i]->getFaculty() == getFaculty() && user[i]->getId() == id){

				int choice;

				do
				{
					system("cls");
					cout << endl << endl
					<< " 1 - User Name.\n"
					<< " 2 - User Password.\n"
					<< " 3 - User Email.\n"
					<< " 4 - User Phone Number.\n" // *** faculty *** old data is
					<< " 5 - Exit.\n"
					<< " Select user information: ";
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
						cout<< " Enter user name: ";
						getline(cin, data);
						user[i]->setName(data);
						cout<<endl<<endl;
						cout<< "  user name is changed successfully.";
						cout<<endl<<endl;
						system("pause");
						break;
						case 2:
						int ch;
						cout << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
						cout<< " Enter user password: ";
						getline(cin, data);
						user[i]->setPassword(data);
						cout<<endl<<endl;
						cout<< "  password is changed successfully.";
						cout<<endl<<endl;
						system("pause");
						break;
						case 3:
						cout << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
						cout<< " Enter user email: ";
						getline(cin, data);
						user[i]->setEmail(data);
						cout<<endl<<endl;
						cout<< "  user email is changed successfully.";
						cout<<endl<<endl;
						system("pause");
						break;
						case 4:
						cout << endl << endl;
						cin.clear();
						cin.ignore(1000, '\n');
						cout<< " Enter user phone number: ";
						getline(cin, data);
						user[i]->setPhoneNo(data);
						cout<<endl<<endl;
						cout<< "  user phone number is changed successfully.";
						cout<<endl<<endl;
						system("pause");
						break;
						case 5:
						break;
						default:
						cout << endl << endl << "  Not a Valid Choice. \n"
						<< "  Choose again.\n\n";
						system("pause");
						break;
					}
				}while (choice != 5);
				cout<<endl<<endl<<"  "<<user[i]->getName()<<" information is changed successfully."<<endl<<endl;
				system("pause");
				return;
			}
		}
	}
	cout<<endl<<endl<<"  user not found!"<<endl<<endl;
	system("pause");
}

void Admin::print_faculty_user(vector<User*> &user){

	cout<<endl<<endl
	<<"  <<   Academicians   >>"<<endl<<endl;
	cout<<"  "
	<< left << setw(10) << "User ID"
	<< setw(30) << "Name"
	<< setw(20) << "Password"
	<< setw(30) << "Email"
	<< setw(12) << "Phone No"
	<< setw(5) << "Faculty"
	<< endl;

	for(int i=0; i<user.size(); ++i){

		if(user[i]->getId().at(0) == 'L' && user[i]->getFaculty() == getFaculty()){
			cout<<"  "
			<< left << setw(10) << user[i]->getId()
			<< setw(30) << user[i]->getName()
			<< setw(20) << user[i]->getPassword()
			<< setw(30) << user[i]->getEmail()
			<< setw(12) << user[i]->getPhoneNo()
			<< setw(5) << user[i]->getFaculty()
			<< endl;
		}
	}

	cout<<endl<<"________________________________________________________________________________________________________________"<<endl<<endl;

	cout<<"  <<   Students   >>"<<endl<<endl;
	cout<<"  "
	<< left << setw(10) << "User ID"
	<< setw(30) << "Name"
	<< setw(20) << "Password"
	<< setw(30) << "Email"
	<< setw(12) << "Phone No"
	<< setw(5) << "Faculty"
	<< endl;

	for(int i=0; i<user.size(); ++i){

		if(user[i]->getId().at(0) == 'S' && user[i]->getFaculty() == getFaculty()){
			cout<<"  "
			<< left << setw(10) << user[i]->getId()
			<< setw(30) << user[i]->getName()
			<< setw(20) << user[i]->getPassword()
			<< setw(30) << user[i]->getEmail()
			<< setw(12) << user[i]->getPhoneNo()
			<< setw(5) << user[i]->getFaculty()
			<< endl;
		}
	}
	cout << endl << endl;
}

void Admin::viewRequests(Faculty* &faculty){
	int choice;

	do
	{
		system("cls");
		cout << endl << endl
		<< " 1 - New Courses Requests.\n"
		<< " 2 - Delete Courses Requests.\n"
		<< " 3 - Exit.\n"
		<< " Select request type: ";
		cin >> choice;
		if(cin.fail()){
			cin.clear(); // clear input buffer to restore cin to a usable state
			cin.ignore(10000,'\n');//Max_In exception ***
		}

		switch (choice)
		{
			case 1:
			approveNewCourses(faculty);
			break;
			case 2:
			approveCourseDeletion(faculty);
			break;
			case 3:
			break;
			default:
			cout << endl << endl << "  Not a Valid Choice. \n"
			<< "  Choose again.\n\n";
			system("pause");
			break;
		}
	}while (choice != 3);
}

void Admin::viewCourses(Faculty* faculty, int approvalStatus){

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

			if(courses[i]->getCourseApproval() == approvalStatus){

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

void Admin::approveNewCourses(Faculty* &faculty){

	viewCourses(faculty, 0);

	string id="";
	cin.clear();
	cin.ignore(1000, '\n');
	cout<< " Enter course ID: ";
	getline(cin, id);


	for(int j=0; j<faculty->getTrimester().size(); ++j){

		vector<Course*> courses = faculty->getTrimester()[j]->getCourse();

		for(int i=0; i<courses.size(); ++i){

			if(courses[i]->getId() == id){
				int choice;
				do
				{
					cout << endl << endl
					<< " 1 - Approve Courses.\n"
					<< " 2 - Delete Courses.\n"
					<< " 3 - Exit.\n"
					<< " Select request type: ";
					cin >> choice;
					if(cin.fail()){
						cin.clear(); // clear input buffer to restore cin to a usable state
						cin.ignore(10000,'\n');//Max_In exception ***
					}

					switch (choice)
					{
						case 1:
						courses[i]->setCourseApproval(1);
						faculty->getTrimester()[j]->addAllCourses(courses);
						cout<<endl<<endl<<"  "<<courses[i]->getName()<<" course is approved successfully."<<endl<<endl;
						system("pause");
						return;
						break;
						case 2:
						courses.erase(courses.begin()+i);
						faculty->getTrimester()[j]->addAllCourses(courses);
						cout<<endl<<endl<<"  "<<courses[i]->getName()<<" course is deleted successfully."<<endl<<endl;
						system("pause");
						return;
						break;
						case 3:
						break;
						default:
						cout << endl << endl << "  Not a Valid Choice. \n"
						<< "  Choose again.\n\n";
						system("pause");
						break;
					}
				}while (choice != 3);
			}
		}
	}
}

void Admin::approveCourseDeletion(Faculty* &faculty){

	viewCourses(faculty, 2);

	string id="";
	cin.clear();
	cin.ignore(1000, '\n');
	cout<< " Enter course ID: ";
	getline(cin, id);


	for(int j=0; j<faculty->getTrimester().size(); ++j){

		vector<Course*> courses = faculty->getTrimester()[j]->getCourse();

		for(int i=0; i<courses.size(); ++i){

			if(courses[i]->getId() == id){
				int choice;
				do
				{
					cout << endl << endl
					<< " 1 - Approve Course Deletion.\n"
					<< " 2 - Reject Course Deletion.\n"
					<< " 3 - Exit.\n"
					<< " Select request type: ";
					cin >> choice;
					if(cin.fail()){
						cin.clear(); // clear input buffer to restore cin to a usable state
						cin.ignore(10000,'\n');//Max_In exception ***
					}

					switch (choice)
					{
						case 1:
						courses.erase(courses.begin()+i);
						faculty->getTrimester()[j]->addAllCourses(courses);
						cout<<endl<<endl<<"  "<<courses[i]->getName()<<" course is deleted successfully."<<endl<<endl;
						system("pause");
						return;
						break;
						case 2:
						courses[i]->setCourseApproval(1);
						faculty->getTrimester()[j]->addAllCourses(courses);
						cout<<endl<<endl<<"  Request is rejected successfully."<<endl<<endl;
						system("pause");
						return;
						break;
						case 3:
						break;
						default:
						cout << endl << endl << "  Not a Valid Choice. \n"
						<< "  Choose again.\n\n";
						system("pause");
						break;
					}
				}while (choice != 3);
			}
		}
	}
}
