#include "student.h"
#include<iostream>
using namespace std;
student::student()
{
    //ctor
}

student::~student()
{
    //dtor
}
void student::input_data(void)
{
    cout << "\nEnter name of student: "; cin >> name;
    cout << "\nEnter roll no of student: "; cin >> rollno;
    cout << "\nEnter department of student: "; cin >> depart;
    fflush(stdin);
}
void student::print_data(void)
{
    cout << "\nName: " << name << "\nRoll No: " << rollno << "\nDepartment: " << depart << endl;
}
string student::fetch_name(void)
{
    return name;
}
void student::swap_objects(student &s1)
{
    student temp;
    temp.name = s1.name; temp.depart = s1.depart; temp.rollno = s1.rollno;
    s1.name = this->name; s1.depart = this->depart; s1.rollno = this->rollno;
    this->name = temp.name; this->depart = temp.depart; this->rollno = temp.rollno;
   
}
