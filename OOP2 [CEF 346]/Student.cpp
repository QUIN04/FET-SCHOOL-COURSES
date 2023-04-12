#include<iostream>
#include<string.h>

#include "Course.cpp"

class Student{
	char matricle[10];
	char name[150];
	char dob[11];
	char faculty[25];
	char department[25];
	
public: void RegisterStudent(Database tool){
	cout<<"Matricle: ";
	cin>>this->matricle;
	cin.ignore(10,'\n');
	cout<<endl;
	
	cout<<"Names: ";
	cin.getline(this->name, 150);
	cin.ignore(150,'\n');
	
	cout<<"Faculty: ";
	cin.getline(this->faculty, 25);
	cin.ignore(25,'\n');
	
	cout<<"Department: ";
	cin.getline(this->department, 25);
	cin.ignore(25,'\n');
	
	cout<<"DOB: ";
	cin.getline(this->dob, 25);
	cin.ignore(11,'\n');
	
	tool.InsertToStudent(this->matricle, this->name,this->faculty, this->department, this->dob);	
}

public: void viewStudentDetails(Database Tool){
	char testMatricle[10];
	cout<<endl<<"Enter Matricle for verification: ";
	cin>>testMatricle;
	//if found display information
	//display error message
	Tool.getStudentDetails(testMatricle);
}

public: void viewWholeList(Database Tool){
	Tool.GetStudent();
}

public: void registerCourse(Database Tool){
	char testMatricle[10];
	char code[8];
	cout<<endl<<"Enter Matricle for verification: ";
	cin>>testMatricle;
	cin.ignore(10, '\n');
	cout<<endl<<"Enter Matricle for Course: ";
	cin>>code;
	cin.ignore(8,'\n');
	Tool.InsertToStudentCourse(testMatricle, code);
}

public: void sort(char strings[][5],int x,int y){
	int i,j,k,min;
	char temp[x];
	
	for(k=0;k<y-1;k++){
	   min=k;
	  for(j=k+1;j<y;j++){
	  	for(i=0;i<x;i++){
	  		if(strings[min][i]>strings[j][i])
	  		min=j;
		  }
	  }
	  if(min!=k){
	  	strcpy(temp,strings[k]);
	  	strcpy(strings[k],strings[min]);
	  	strcpy(strings[min],temp);
	  }	
	}
}

};

