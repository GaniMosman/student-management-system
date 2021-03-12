/*

--------------------------
GANI MOHAMMED OSMAN 1171300039

-----------------------
Lecture section : TC01
Tutorial section : TT01
*/


#include <iostream>
#include <fstream>
#include <string>
#include <iterator>

#include "windows.h"
#include "User.h"
#include "Student.h"
#include "Academician.h"
#include "Admin.h"
#include "Faculty.h"
#include "Trimester.h"
#include "Course.h"
#include "Session.h"

#include <vector>

using namespace std;

/**
Saves user's data to external file to be used again on another time

	@param list of system users objects
*/
void saveUsers(vector<User*> user)
{
    ofstream fileStudent;
	ofstream fileLecturer;
    fileStudent.open("StudentRecords.txt");
	fileLecturer.open("LecturerRecords.txt");

    for(int i =0; i <user.size(); ++i)
    {
		if(user[i]->getId().at(0) == 'S')
			user[i]->saveToFile(fileStudent);

		else if(user[i]->getId().at(0) == 'L')
			user[i]->saveToFile(fileLecturer);
	}
    fileStudent.close ();
	fileLecturer.close ();
}

/**
Loads user's data from external file that has been save before

	@param list of system users objects
*/
void loadUsers(vector<User*>& user)
{

    // Define string variables.
    string id,
	password,
	name,
    email,
    faculty,
	phone,
	speciality,
	officeNo,
	degree;

	int currentTerm;

    ifstream file; // Pre-pare opening of file.
    file.open("StudentRecords.txt"); // Open StudentRecords.txt
    if (!file) // Validation statement
    {
        cout << "Can't open file " << endl; // Tell user that the file could not be read correctly.
        exit(1); // End program.
    }
    while(!file.eof()){

		getline(file, id);
		if(id == "")
			break;
		getline(file, name);
		getline(file, password);
		getline(file, faculty);
		getline(file, email);
		getline(file, phone);
		file>>currentTerm;
		getline(file, degree);

		user.push_back(new Student(id, password, name, faculty, email, phone, degree, currentTerm));
    }
    file.close();    // Close file

	file.open("LecturerRecords.txt"); // Open LecturerRecords.txt
    if (!file) // Validation statement
    {
        cout << "Can't open file " << endl; // Tell user that the file could not be read correctly.
        exit(1); // End program.
    }
    while(!file.eof()){

		getline(file, id);
		if(id == "")
			break;
		getline(file, name);
		getline(file, password);
		getline(file, faculty);
		getline(file, email);
		getline(file, phone);
		getline(file, officeNo);
		getline(file, speciality);

		user.push_back(new Academician(id, password, name, faculty, email, phone, officeNo, speciality));
	}
    file.close();    // Close file
}


vector<string> split(string str, char delimiter) {
  vector<string> result;
  stringstream ss(str);
  string tok;

  while(getline(ss, tok, delimiter)) {
    result.push_back(tok);
  }

  return result;
}

/**
Loads courses' data from external file that has been save before

	@param list of faculties available in the system
*/
void loadCourses(vector<Faculty*> &faculties)
{
    // Define string variables.

    string id,
	name,
	program,
	lID,
	lTime,
	lVanue,
	lLecturerID,
	tID,
	tTime,
	tVanue,
	tLecturerID,
	students,
	status,
	prerequisites;

	int creditHour=0, approvalStatus=0;
	bool isOpen=true;

    ifstream file; // Pre-pare opening of file.
    file.open("Faculties.txt"); // Open StudentRecords.txt
    if (!file) // Validation statement
    {
        cout << "Can't open input file " << endl; // Tell user that the file could not be read correctly.
        exit(1); // End program.
    }

	for(int i=0; i<faculties.size(); ++i){

		for(int j=0; j<faculties[i]->getTrimester().size(); ++j){

			vector<Course*> courses;
			while (!file.eof()){

				getline(file, id);
				if(id == "<<trimester>>")
					break;

				getline(file, name);
				file>>creditHour;
				getline(file, program);
				getline(file, lID);
				getline(file, lTime);
				getline(file, lVanue);
				getline(file, lLecturerID);
				getline(file, tID);
				getline(file, tTime);
				getline(file, tVanue);
				getline(file, tLecturerID);
				getline(file, students);
				getline(file, prerequisites);
				file>>approvalStatus;
				getline(file, status);

				vector<string> s = split(students, ' ');
				vector<string> prerequisitesV = split(prerequisites, ' ');

				if(status == "Open")
					isOpen =true;

				else if(status == "Close")
					isOpen =false;

				Session* lecture = new Session(lID, lTime, lVanue, lLecturerID);
				Session* tutorial = new Session(tID, tTime, tVanue, tLecturerID);
				Course* course = new Course(id, name, program, creditHour, isOpen, prerequisitesV, s, lecture, tutorial);
				course->setCourseApproval(approvalStatus);
				courses.push_back(course);

			}

			faculties[i]->getTrimester()[j]->addAllCourses(courses);

		}
    }

    file.close();
}

string join(const vector<string>& vec)
{
	if(vec.empty())
		return "";

	else{
		string result = vec[0];

		for(int i=1; i<vec.size(); ++i){
			result = result + " " + vec[i];
		}

		return result;
	}
}

/**
Saves courses' data to external file to be used again on another time

	@param list of faculties available in the system
*/
void saveCourses(vector<Faculty*> faculties){

	ofstream fileFaculty;
    fileFaculty.open("Faculties.txt");

	for(int i=0; i<faculties.size(); ++i){

		for(int j=0; j<faculties[i]->getTrimester().size(); ++j){

			vector<Course*> courses = faculties[i]->getTrimester()[j]->getCourse();

			for(int k=0; k<courses.size(); ++k){

				Session* lecture = courses[k]->getLecture();
				Session* tutorial = courses[k]->getTutorial();

				fileFaculty<< courses[k]->getId()
				<<endl
				<< courses[k]->getName()
				<<endl
				<< courses[k]->getCH()
				<< courses[k]->getProgram()
				<<endl
				<< lecture->getId()
				<<endl
				<< lecture->getTime()
				<<endl
				<< lecture->getVanue()
				<<endl
				<< lecture->getLecturer()
				<<endl
				<< tutorial->getId()
				<<endl
				<< tutorial->getTime()
				<<endl
				<< tutorial->getVanue()
				<<endl
				<< tutorial->getLecturer()
				<<endl
				<< join(courses[k]->getStudent())
				<<endl
				<< join(courses[k]->getPrerequisites())
				<<endl
				<< courses[k]->getCourseApproval();
				if(courses[k]->getStatus()){
					fileFaculty<< "Open"
					<< endl;
				}
				else{
					fileFaculty<< "Close"
					<< endl;
				}
			}

			fileFaculty<< "<<trimester>>"
			<< endl;
		}
	}
	fileFaculty.close();
}

int main(){

	vector<User*> user;

	vector<Faculty*> faculties;
	vector<Trimester*> trimestersFCI;
    vector<Trimester*> trimestersFOE;
	vector<Trimester*> trimestersFOM;
	vector<Course*> courses;

	trimestersFCI.push_back(new Trimester("1710", "Trimester 1 2017/18", "02-07-2017",	"28-10-2017", courses));
	trimestersFCI.push_back(new Trimester("1720", "Trimester 2 2017/18", "20-11-2017",	"10-03-2018", courses));
	trimestersFCI.push_back(new Trimester("1810", "Trimester 1 2018/19", "02-07-2018",	"28-10-2018", courses));
	trimestersFCI.push_back(new Trimester("1820", "Trimester 2 2018/19", "20-11-2018",	"10-03-2019", courses));

	trimestersFOE.push_back(new Trimester("1710", "Trimester 1 2017/18", "02-07-2017",	"28-10-2017", courses));
	trimestersFOE.push_back(new Trimester("1720", "Trimester 2 2017/18", "20-11-2017",	"10-03-2018", courses));
	trimestersFOE.push_back(new Trimester("1810", "Trimester 1 2018/19", "02-07-2018",	"28-10-2018", courses));
	trimestersFOE.push_back(new Trimester("1820", "Trimester 2 2018/19", "20-11-2018",	"10-03-2019", courses));

	trimestersFOM.push_back(new Trimester("1710", "Trimester 1 2017/18", "02-07-2017",	"28-10-2017", courses));
	trimestersFOM.push_back(new Trimester("1720", "Trimester 2 2017/18", "20-11-2017",	"10-03-2018", courses));
	trimestersFOM.push_back(new Trimester("1810", "Trimester 1 2018/19", "02-07-2018",	"28-10-2018", courses));
	trimestersFOM.push_back(new Trimester("1820", "Trimester 2 2018/19", "20-11-2018",	"10-03-2019", courses));

	faculties.push_back(new Faculty("FCI", "Faculty of Computing and Informatics", trimestersFCI));
	faculties.push_back(new Faculty("FOE", "Faculty of Engineering", trimestersFOE));
	faculties.push_back(new Faculty("FOM", "Faculty of Managment", trimestersFOM));

	user.push_back(new Admin("A1", "1q2w3e4r", "Omer Ali", "FCI", "Omer@gmail.com", "035467765", "officer"));
	user.push_back(new Admin("A2", "1q2w3e4r", "Ridom Zaki", "FOM", "eidom@gmail.com", "0356789090", "officer"));
	user.push_back(new Admin("A3", "1q2w3e4r", "Aisha Hassan", "FOE", "aisha@gmail.com", "037687876", "officer"));

	loadUsers(user);
	loadCourses(faculties);

	while(true){

		system("cls");

		string userID, password;

		cout<< endl << endl
		<< "*******************************************************"
		<< endl << endl
		<< "*          WELCOME TO MULTIMEDIA UNIVERSITY           *"
		<< endl << endl
		<< "*              STUDENT MANAGEMENT SYSTEM              *"
		<< endl << endl
		<< "*******************************************************"
		<< endl << endl <<endl
        << "*/ Sample admin id and password for login into system */"
        << endl
        << "ID: A1, password : 1q2w3e4r, Faculty : FCI "
        << endl
        << "ID: A2, password : 1q2w3e4r, Faculty : FOM "
        << endl
        << "ID: A3, password : 1q2w3e4r, Faculty : FOE "
        << endl
        << "-------------------------------------------"
        << endl
		<< "Enter your user ID: ";
		cin >> userID;
		cin.clear();
		cin.ignore(10000,'\n');
		cout<< "Enter your password: ";
		cin >> password;

		bool logged = false;

		for(int i = 0; i<user.size(); ++i){
			if(user[i]->login(userID, password)){
				logged = true;
				user[i]->mainMenu(user,faculties);
				break;
			}
		}

		if(!logged){
			cout << endl<< endl << "UserID or Password is not correct!" << endl << endl;
			system("pause");
		}

		saveUsers(user);
		saveCourses(faculties);
	}
}
