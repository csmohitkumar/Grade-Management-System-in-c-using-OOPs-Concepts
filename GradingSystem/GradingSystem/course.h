#ifndef COURSE_H
#define COURSE_H
#include <string>
#include<iostream>
#include<fstream>
#include "Login.h"
void coursemenu();
class student;
using namespace std;
class course
{
private:
	char Char_Branch_Name[30],branch_code[10],course_name[20][11],course_no[10][11];
	int level,no_of_course,branch_no;
	string make_course_code[60],credit_hr[60];
	float tution_fee_amount;
public:
	void getlevel();
	void getbranch();
	void getDetails();
	void getbranch_no();
	void getno_of_course();
	void getcoursedetails();
	void putDetails();
	void updateOption_add(course& c,char ch);
	void fileWrite();
	void fileRead();
	int BranchExist();
	int courseExist(string);
	void getdelete(int n,course& c);
	void courseUpdate();
	friend int getCourse(student& s1, course& c1);
	friend int validate_branch_no(student& s1, course& c1);
	friend void calculate_GPA(student& s1, course& c1,int i);
	friend int fee(int,int);
	void deletefun();
};
#endif