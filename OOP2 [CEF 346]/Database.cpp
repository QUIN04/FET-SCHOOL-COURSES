#include<iostream>
#include<mysql.h>
#include<mysqld_error.h>
#include<string.h>

using namespace std;

class Database{
	
	MYSQL *object;
	MYSQL_ROW records;
	MYSQL_RES *result;

	
public:	bool establishConnection(char *host, char *username, char *password, char *schema){
		if(!(this->object=mysql_init(0))){
		cout<<"Error: Failed to create SQL object";
		return false;}
		
		else{
			if(!(mysql_real_connect(this->object,host,username,password,schema,3306, NULL, 0)))
			{
				cout<<"Error: Failed to connect to database. Check authentication is correct"<<endl;
				return false;
			}
			else{
				cout<<"All Connections established"<<endl<<endl;
				return true;
			}
		}
	}
	
public: void InsertToStudent(char *matricle, char *name, char *faculty, char* department, char *dob){
	
	char Query[]="INSERT INTO student values ('%s', '%s', '%s', '%s', '%s')";
	char FQuery[strlen(Query) + strlen(matricle) + strlen(name) + strlen(faculty) + strlen(department) + strlen(dob)+1];
	sprintf(FQuery, Query, matricle, name, faculty, department, dob);
	
	if(mysql_query(this->object, FQuery)){
		cout<<"Error: "<<mysql_error(this->object)<<endl;
	}
	else cout<<"Data Stored in Database";
	
	
		
}

public: void InsertToStudentCourse(char *matricle, char *code){
	
	char Query[]="INSERT INTO student_course values ('%s', '%s')";
	char FQuery[strlen(Query) + strlen(matricle) + strlen(code)+1];
	sprintf(FQuery, Query, matricle, code);
	
	if(mysql_query(this->object, FQuery)){
		cout<<"Error: "<<mysql_error(this->object)<<endl;
	}
	else cout<<"Data Stored in Database";
		
}

public: void InsertToCourse(char *code, char *title, char *tutor, char *dep){
	
	char Query[]="INSERT INTO courses values ('%s', '%s', '%s', '%s')";
	char FQuery[strlen(Query) + strlen(title) + strlen(code)+ strlen(tutor) + strlen(dep) + 1];
	sprintf(FQuery, Query, code, title, tutor, dep);
	
	if(mysql_query(this->object, FQuery)){
		cout<<"Error: "<<mysql_error(this->object)<<endl;
	}
	else cout<<"Data Stored in Database";
		
}

public: void GetCourses( char *Query){
   int i;
   
   if((mysql_query(this->object, Query))){
   	cout<<"Error: "<<mysql_error(this->object)<<endl;
   }
   else{
   	  this->result=mysql_store_result(this->object);
   	  
   	  int fields=mysql_num_fields(this->result);
   	        cout<<"-------------+-------------------------+-----------------+------------------+";
   	  cout<<endl<<"|    CODE    |          TITLE          |      TUTOR      |    DEPARTMENT    |"<<endl;
   	        cout<<"-------------+-------------------------+-----------------+------------------+"<<endl;
   	  
   	  while(this->records=mysql_fetch_row(this->result)){
   	  	cout<<"  ";
   	  	for(i=0;i<fields;i++){
   	  			cout<<this->records[i]<<"\t\t";
			 }
			 cout<<endl;
   	  	  
		 }
		 mysql_free_result(this->result);
   }
   	
}

void GetStudent(){
	char Query[]="select * from student";
   int i;
   
   if((mysql_query(this->object, Query))){
   	cout<<"Error: "<<mysql_error(this->object)<<endl;
   }
   else{
   	  this->result=mysql_store_result(this->object);
   	  
   	  int fields=mysql_num_fields(this->result);
   	        cout<<"----------------+-------------------------+-----------------+------------------+-------------------";
   	  cout<<endl<<"|   MATRICULE   |           NAME          |     FACULTY     |    DEPARTMENT    |        DOB       |"<<endl;
   	        cout<<"----------------+-------------------------+-----------------+------------------+-------------------"<<endl;
   	  
   	  while(this->records=mysql_fetch_row(this->result)){
   	  	cout<<"  ";
   	  	for(i=0;i<fields;i++){
   	  			cout<<this->records[i]<<"\t\t";
			 }
			 cout<<endl;
   	  	  
		 }
		 mysql_free_result(this->result);
   }
}

void getStudentDetails(char* matricle){
	
	string label[]={"MATRICLE","NAME","FACULTY","DEPARTMENT","DOB"};
	char Query[]="select * from student where matricle= '%s' ";
	char FQuery[strlen(Query)+strlen(matricle)];
	sprintf(FQuery,Query,matricle);
	
   int i;
   
   if((mysql_query(this->object, FQuery))){
   	cout<<"Error: "<<mysql_error(this->object)<<endl;
   }
   else{
   	  this->result=mysql_store_result(this->object);
   	  
   	  int fields=mysql_num_fields(this->result);
   	  
   	  if(!(this->result)){
   	  	   cout<<endl<<"Student not registered"<<endl<<endl;
   	  	   return;
		 }
		 
		 else{
		 	while(this->records=mysql_fetch_row(this->result)){
   	  	cout<<"  ";
   	  	for(i=0;i<fields;i++){
   	  			cout<<endl<<label[i]<<": "<<this->records[i]<<endl;
			 }
			 cout<<endl;
   	  	  
		 }
		 mysql_free_result(this->result);
		 }
		 
		 char Query2[]="select * from student_course where matricle='%s'";
		 char FQuery2[strlen(Query2)+strlen(matricle)];
		 
		 sprintf(FQuery2, Query2, matricle);
		 
		 if(mysql_query(this->object, FQuery2)){
		 	cout<<"Error: Coudln't get courses"<<endl<<"Cause:"<<mysql_error(this->object);
		 }
		 else{
		 	
		 	this->result=mysql_store_result(this->object);
   	  
   	        int fields=mysql_num_fields(this->result);
   	        
   	        int rows=mysql_num_rows(this->result);
   	        
   	        cout<<"----------Registered Courses--------------"<<endl<<endl;
   	  
   	  if(!(this->result) || !rows){
   	  	   cout<<endl<<"No Course Registered Yet"<<endl<<endl;
   	  	   return;
		 }
		 
		 else{
		 	int count=0;
		 	char query[]="select * from courses where course_code='%s'";
		 	while(this->records=mysql_fetch_row(this->result)){
   	  	    for(i=1;i<fields;i++){
   	  		    char fquery[strlen(query)+strlen(records[i])];
   	  		    sprintf(fquery, query,records[i]);
   	  		    GetCourses(fquery);
   	  			cout<<endl<<endl;
			 }
			
   	  	  
		 }
		 mysql_free_result(this->result);
		 }
		 	
		 }
   	  
   	  
   }
}
};
