// C++ program to create student class, read and print N student's details
// (Example of array of objects)

#include <iostream>
using namespace std;

#define MAX 10

class student {
private:
    char name[30];
    int idNo;
    int attendance;
    float score;

public:
    //member function to get student's details
    void getDetails(void);
    //member function to print student's details
    void putDetails(void);
};

//member function definition, outside of the class
void student::getDetails(void)
{
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter id number: ";
    cin >> rollNo;
    cout << "Enter total marks out of 250: ";
    cin >> total;

    score = (float)total / 250 * 100;
}

//member function definition, outside of the class
void student::putDetails(void)
{
    cout << "Student details:\n";
    cout << "Name:" << name << ",Identity Number:" << idNo << ",Attendance:" << attendance << "Score:" << score;
}

int main()
{
    student std[MAX]; //array of objects creation
    int n, loop;

    cout << "Enter total number of students: ";
    cin >> n;

    for (loop = 0; loop < n; loop++) {
        cout << "Enter details of student " << loop + 1 << ":\n";
        std[loop].getDetails();
    }

    cout << endl;

    for (loop = 0; loop < n; loop++) {
        cout << "Details of student " << (loop + 1) << ":\n";
        std[loop].putDetails();
    }

    return 0;
}