#include <iostream>
#include "./Student.cpp" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main(int argc, char** argv){
	
	char host[]="localhost";
	char username[]="root";
	char password[]="#839jke7tdgiw981ksnjk.g";
	char schema[]="record_management";
	
	Database connect;
	int open=-1;
	
	if(connect.establishConnection(host,username,password,schema)){
		
	    cout<<"Select an option from the list below"<<endl;
	    while(open!=0){
	    cout<<endl<<endl<<" 1: Register Student \n 2: Add Course\n 3: DisplayList\n 4: View Student details \n 5: Register Course\n 6: Show all Courses\n 7: Sort List \n 0: Exit"<<endl<<endl;
	    cout<<"choice > ";
	    cin>>open;
	    switch(open){
	    	case 0:
	    	cout<<"Hit Enter to exit";
	    	return 0;
	    	break;
	    	
	    	case 1:
	    		Student student;
	    		student.RegisterStudent(connect);
	    		break;
	    	case 2:
	    		Course course;
	    		course.StoreCourses(connect);
	    		break;
	    	case 3:
	    		Student student1;
	    		student.viewWholeList(connect);
	    		break;
	    	case 4:
	    		Student student2;
	    		student2.viewStudentDetails(connect);
	    		break;
	    	case 5:
	    		Student student3;
	    		student3.registerCourse(connect);
	    		break;
	    	case 6:
	    		Course course1;
	    		course1.DisplayCourses(connect);
	    		break;
	    	case 7:
	    		int option;
	    		cout<<"Sort Student list by?"<<endl<<"1: Matricle"<<endl<<"2: Name"<<endl<<"3: Department"<<endl<<"Choice > ";
	    		cin>>option;
	    		//char Str[][10]={{'s','h','o','p'},{'s','h','o','p'},{'s','h','o','p'},{'s','h','o','p'}};
	    		break;
	    		
	    	    default:
	    		cout<<"invalid command"<<endl;
	    		break;
		}
		}
	}
	
	return 0;
}
