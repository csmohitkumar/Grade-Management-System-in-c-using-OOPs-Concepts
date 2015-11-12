#ifndef STUDENT_H
#define STUDENT_H
#include<fstream>
#include<string>
#include "course.h"
#include<windows.h>
using namespace std;
void studentmenu();
class course;
class login;
class student:public login
{
private:
	char name[60],grade[5][60];
	string intake,course_name[60],course_code[60],status,credit_hr[60];
	int year,level,branch_no,serial_no,total_course,check_getcourse,grade1[60],gpa,record_entry,total_credit_hr;	
	bool tution_fee_paid;
	float tution_fee_amount,subject_fee[65],finalgpa,totalfee;
public:
	student(){}
	void getDetails(int,int,int,int);
	void putDetails();
	void fileWrite();
	void fileRead(int);
	int Validation(string);
	int validate_level_branch();
	void studentDelete();
	int get_serial_from_file();
	int getDeletedRecord();
	friend void calculate_GPA(student& s1, course& c1,int i);
	friend int validate_branch_no(student& s1, course& c1);
	friend int getCourse(student& s1, course& c1);
	void DisplayRecord(student &s);
	void update();
	void Student_Screen(student &student_detail);
	friend int fee(int,int);
	void loginverification();
};
#endif
