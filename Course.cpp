#include<iostream>
#include "Database.cpp"

using namespace std;

class Course{
	char code[7];
	char title[45];
	char tutor[45];
	char department[45];
	
public: void RegisterCourse(){
	char matr[10];
	cout<<"Enter Matricle For Verification: ";
	cin>>matr;
	//Check for matricle in database
	//if found ask for course to be registered
	//else display message
}

public: void StoreCourses(Database tool){
	cout<<"Code: ";
	cin>>this->code;
	cin.ignore(7,'\n');
	cout<<endl;
	
	cout<<"Title: ";
	cin.getline(this->title, 45);
	cin.ignore(45,'\n');
	
	cout<<"Tutor: ";
	cin.getline(this->tutor, 45);
	cin.ignore(45,'\n');
	
	cout<<"Department: ";
	cin.getline(this->department, 45);
	cin.ignore(45,'\n');
	
	tool.InsertToCourse(this->code, this->title, this->tutor, this->department);
	cout<<endl<<"Course stored";
}

void DisplayCourses(Database tool){
	char Query[]="select * from courses";
	tool.GetCourses(Query);
}
};
