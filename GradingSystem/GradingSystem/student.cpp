#include"student.h"
#include <stdlib.h>
#include <iomanip>
#include<windows.h>
#include <algorithm>
#include<conio.h>
class course c1;
class student s1;

void student::Student_Screen(student &student_detail)
{
	system("cls");
	//cout<<"\t";
	string notpaid="***";
	int x=1,y=2,a=9,b=0;
	for(int i=0;i<27;i++)
	{
		gotoxy(a,b);
		cout<<"*";
		a=a+2;
	}
	a=9;b=0;
	gotoxy(a+20,1);
	cout<<"Welcome "<<name;
	for(int i=0;i<27;i++)
	{
		gotoxy(a,b+2);
		cout<<"*";
		a=a+2;
	}
	a=9;b=0;
	for(int i=0;i<12;i++)
	{
		gotoxy(a,b+2);
		cout<<"*";
		b=b+2;
	}
	for(int i=0;i<27;i++)
	{
		gotoxy(a,b+2);
		cout<<"*";
		a=a+2;
	}
	a=61;b=0;
	for(int i=0;i<12;i++)
	{
		gotoxy(a,b+2);
		cout<<"*";
		b=b+2;
	}


	x=1;y=1;
	gotoxy(x+12,y+2);
	fflush(stdin);
	cout<<"Student Name:";
	gotoxy(x+45,y+2);
	fflush(stdin);
	puts(student_detail.name);
	gotoxy(x+12,y+4);
	cout<<"Level:";
	gotoxy(x+45,y+4);
	cout<<student_detail.level;
	gotoxy(x+12,y+6);
	cout<<"Student ID:";
	gotoxy(x+45,y+6);
	cout<<student_detail.intake;
	gotoxy(x+12,y+8);
	cout<<"Number of Courses enrolled:";
	gotoxy(x+45,y+8);
	cout<<student_detail.check_getcourse;
	gotoxy(x+12,y+10);
	cout<<"Course No";
	gotoxy(x+27,y+10);
	cout<<"Course Name";
	gotoxy(x+42,y+10);
	cout<<"Credits";
	gotoxy(x+52,y+10);
	cout<<"Grade";
	int y1=14;
	if(student_detail.tution_fee_paid==1)
	{
		for(int i=0;i<student_detail.check_getcourse;i++)
		{
			if(student_detail.subject_fee[i]==0)
			{
				
			}
			else
			{
				gotoxy(x+12,y1);
				cout<<student_detail.course_code[i];
				gotoxy(x+27,y1);
				cout<<student_detail.course_name[i];
				gotoxy(x+42,y1);
				cout<<student_detail.credit_hr[i];
				gotoxy(x+52,y1);
				cout<<student_detail.grade[i];
				y1=y1+2;
			}
		}
		gotoxy(x+12,y1);
		cout<<"Total Number of Credit:";
		gotoxy(x+42,y1);
		cout<<student_detail.total_credit_hr;
		gotoxy(x+27,y1+2);
		cout<<"GPA:";
		gotoxy(x+43,y1+2);
		cout<<student_detail.finalgpa;
	}
	else
	{
		for(int i=0;i<check_getcourse;i++)
		{
			if(s1.subject_fee[i]==0)
			{
				
			}
			else
			{
				gotoxy(x+12,y1);
				cout<<student_detail.course_code[i];
				gotoxy(x+27,y1);
				cout<<student_detail.course_name[i];
				gotoxy(x+42,y1);
				cout<<student_detail.credit_hr[i];
				gotoxy(x+52,y1);
				cout<<notpaid;
				y1=y1+2;
			}
		}
		gotoxy(x+12,y1);
		cout<<"Total Number of Credit:";
		gotoxy(x+42,y1);
		cout<<student_detail.total_credit_hr;
		gotoxy(x+27,y1+2);
		cout<<"GPA:";
		gotoxy(x+43,y1+2);
		cout<<notpaid;
		gotoxy(x+12,y1+4);
		cout<<"Pay your free, to see your grade";
		gotoxy(x+12,y1+6);
		cout<<"Due Fee: RS "<<student_detail.totalfee;
	}
	cout<<"\n\n\n";
}

int fee(int level,int branch_no)
{
	int i=0;
	ifstream fcin;
	fcin.open("course", ios::app |ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read ((char *) &c1,sizeof(c1));
		if(fcin.eof()!=0)
		{
			break;	
		}
		if(level==c1.level && branch_no==c1.branch_no)
		{
			i=c1.tution_fee_amount;
		    break;
		}
		else 
		{
			i=0;
		}
	}	
	fcin.close();
	return i;
}
void student::getDetails(int level_par,int branch_no_par,int no_of_record,int year15)
{

	string city="PT",yop,level1,branch_no1,serial_no1,tution_fee;
	char year1[10],lev[5],branch_n[5],s_no[5];
	int check_intake=0,check=0;
	total_credit_hr=1.0;
	intake="";
	status="active";
	level=level_par;
	branch_no=branch_no_par;
	record_entry=no_of_record;
	if(validate_branch_no(s1,c1))
	{
		cout<<"\nEnter name of student: ";
		fflush(stdin);
		gets(name);
		year=year15;
		serial_no=0;
		serial_no=get_serial_from_file();
		if((serial_no-getDeletedRecord())<=60)
		{
			serial_no1=string(itoa(serial_no,s_no,10));
			intake.append(city);
			yop=string(itoa(year,year1,10));
			yop=yop.substr(2,2);
			intake.append(yop);
			level1=string(itoa(level,lev,10));
			intake.append(level1);
			branch_no1=string(itoa(branch_no,branch_n,10));
			intake.append(branch_no1);
			if(serial_no1.length()==1)
			{
				serial_no1.replace(0,2,("0"+serial_no1));
			}
			string serial_no2=serial_no1;
			intake=intake+serial_no2;
			cout<<"\nIntake Number: "<<intake;
			check_intake=Validation(intake);
			if(check_intake==0)
			{
				cout<<"\nEnter Tution Fee Paid(\t1.True\t0.False): ";
				cin>>tution_fee_paid;
				check_getcourse=getCourse(s1,c1);
				finalgpa=gpa/(total_credit_hr*1.0);
				if(check_getcourse!=0)
				{
					cout<<"\n\tCourse name\t\tcourse Code\t\tCredit Hour\n";
					for(int i=0;i<check_getcourse;i++)
					{
						cout<<"\n\t"<<s1.course_name[i]<<"\t\t\t"<<s1.course_code[i]<<"\t\t\t"<<credit_hr[i]<<endl;
					}
					
				}
				else
				{
					cout<<"\n course does not exist(file not open)\n";
					getDetails(level,branch_no,record_entry,year);
				}
			}
			else
			{
				cout<<"\nIntake Exist!Please try Again\n";
				getDetails(level,branch_no,record_entry,year);
			}
		}
		else
		{
			cout<<"\nMaximum Limit of Student reached\n";
			fileWrite();
		}
	}
	else
	{
		cout<<"\nBranch Not exixt";
		fileWrite();
	}

}
int student::getDeletedRecord()
{
	int i=0;
	student sd;
	ifstream fcin;
	fcin.open("student", ios::app |ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read ((char *) &sd,sizeof(sd));
		if(fcin.eof()!=0)
		{
			break;	
		}
		if(sd.status.compare("deactive")==0)
		{
			i++;
		}
	}	
	fcin.close();
	return i;
}
int student::get_serial_from_file()
{
	int i=0;
	int j=0,max=0;
	int serial[70];
	student sd;
	ifstream fcin;
	fcin.open("student", ios::app |ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read ((char *) &sd,sizeof(sd));
		if(fcin.eof()!=0)
		{
			break;	
		}
		if(level==sd.level && branch_no==sd.branch_no && year==sd.year)
		{
			serial[j]=sd.serial_no;
			if(max<serial[j])
			{
				max=serial[j];
			}
			j++;
		}
	}	
	fcin.close();
	return max+1;
}
int getCourse(student& s1, course& c1)
{
	ifstream fcin;
	s1.total_credit_hr=0;
	int i,flag1=0,checkgrade=0;
	string s_level,c_level,s_branch,c_branch,s_coursename[100];
	char ch_s_level[5],ch_s_branch[5],ch_c_branch[5],course_level[10];
	fcin.open("course",ios::app|ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read((char*)&c1,sizeof(c1));
		if(fcin.eof()!=0)
			break;
		else
		{
			s1.gpa=0;
			s_level=string(itoa(s1.level,ch_s_level,10));
			c_level=string(itoa(c1.level,course_level,10));
			s_branch=string(itoa(s1.branch_no,ch_s_branch,10));
			c_branch=string(itoa(c1.branch_no,ch_c_branch,10));
			if(s_level==c_level && s_branch==c_branch)
			{
				s1.tution_fee_amount=c1.tution_fee_amount;
				s1.total_course=c1.no_of_course;
				flag1=c1.no_of_course;
				for(i=0;i<c1.no_of_course;i++)
				{
					s1.course_name[i]=(string)c1.course_name[i];
					s1.course_code[i]=(string)c1.make_course_code[i];
					calculate_GPA(s1,c1,i);
				}
				break;
			}			
		}
	}
	fcin.close();
	return flag1;
}
void calculate_GPA(student& s1, course& c1,int i)
{
	int checkgrade=0;
    s1.credit_hr[i]=c1.credit_hr[i];
	char *credit_hour=new char[(s1.credit_hr[i]).size()+1];
	credit_hour[s1.credit_hr[i].size()]=0;
	memcpy(credit_hour,(s1.credit_hr[i]).c_str(),(s1.credit_hr[i]).size());
	s1.subject_fee[i]=atoi(credit_hour)*s1.tution_fee_amount;
	s1.totalfee=s1.totalfee+s1.subject_fee[i];
	
	s1.total_credit_hr=s1.total_credit_hr+atoi(credit_hour);
	do
	{
			cout<<"\n\tEnter Grade course "<<s1.course_name[i]<<" (A-F): ";
			cin>>s1.grade[i];
			
		if(string(s1.grade[i]).compare("A")==0 ||string(s1.grade[i]).compare("a")==0 ||string(s1.grade[i]).compare("B")==0 ||string(s1.grade[i]).compare("b")==0 ||string(s1.grade[i]).compare("C")==0 ||string(s1.grade[i]).compare("c")==0 ||string(s1.grade[i]).compare("D")==0 ||string(s1.grade[i]).compare("d")==0 ||string(s1.grade[i]).compare("E")==0 ||string(s1.grade[i]).compare("e")==0 ||string(s1.grade[i]).compare("F")==0 ||string(s1.grade[i]).compare("f")==0);
		{
			if(string(s1.grade[i]).compare("A")==0 ||string(s1.grade[i]).compare("a")==0)
			{
				s1.grade1[i]=5;
			}
			 if(string(s1.grade[i]).compare("B")==0 ||string(s1.grade[i]).compare("b")==0)
				s1.grade1[i]=4;
			 if(string(s1.grade[i]).compare("C")==0 ||string(s1.grade[i]).compare("c")==0)
				s1.grade1[i]=3;
			 if(string(s1.grade[i]).compare("D")==0 ||string(s1.grade[i]).compare("d")==0)
				s1.grade1[i]=2;
			 if(string(s1.grade[i]).compare("E")==0 ||string(s1.grade[i]).compare("e")==0)
				s1.grade1[i]=1;
			 if(string(s1.grade[i]).compare("F")==0 ||string(s1.grade[i]).compare("f")==0)
				s1.grade1[i]=0;
			s1.gpa=(atoi(credit_hour)*s1.grade1[i]+s1.gpa);///s1.total_course;
			checkgrade=1;
		}
		
	}while(checkgrade!=1);
	
}
int student::validate_level_branch()
{
	int i=0;
	student s;
	ifstream fcin;
	fcin.open("student", ios::app|ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read ((char *) &s,sizeof(s));
		if(fcin.eof()!=0)
			break;	
		if(level==s.level && branch_no==s.branch_no)
		{
			i=1;
		    break;
		}
		else 
		{
			i=0;
		}
	}	
	fcin.close();
	return i;
}
int validate_branch_no(student& s1, course& c1)
{
	int i=0;
	ifstream fcin;
	fcin.open("course", ios::app |ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read ((char *) &c1,sizeof(c1));
		if(fcin.eof()!=0)
		{
			break;	
		}
		if(s1.level==c1.level && s1.branch_no==c1.branch_no)
		{
			i=1;
		    break;
		}
		else 
		{
			i=0;
		}
	}	
	fcin.close();
	return i;
}
int student::Validation(string roll)
{
	int i=0;
	student s;
	ifstream fcin;
	fcin.open("student", ios::app|ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read ((char *) &s,sizeof(s));
		if(fcin.eof()!=0)
		{
			break;	
		}
		if(roll.compare(s.intake)==0 && s.status.compare("active")==0)
		{
			i=1;
		    break;
		}
		else 
		{
			i=0;
		}
	}	
	fcin.close();
	return i;
}
void student::putDetails()
{
	//string notpaid="***";
	cout<<"\nLevel: "<<level;
	cout<<"\nStudent Name: ";
	fflush(stdin);
	puts(name);
	cout<<"\nIntake Number: "<<intake<<"\nBranch Number: "<<branch_no<<"\nYear of Admision: "<<year;
	cout<<"\nCourse name\tcourse Code\tCredit Hour\tTution Fee\tGrade\n";
	/*if(s1.tution_fee_paid==1)
	{*/
		for(int i=0;i<check_getcourse;i++)
		{
			cout<<"\n"<<s1.course_name[i]<<"\t\t"<<s1.course_code[i]<<"\t\t"<<s1.credit_hr[i]<<"\t\tRS "<<subject_fee[i]<<"\t\t"<<grade[i]<<endl;
		}
		cout<<"\nTotal Fee:RS "<<totalfee;
		cout<<"\nGPA: "<<finalgpa;
		cout<<"\nStudent Status: "<<status<<endl;
		cout<<"\nTution fee paid(1. yes 2.not): "<<tution_fee_paid;
	cout<<endl;
}

void student::fileWrite()
{
	int n=0;
	char ch;
	int no_of_record=0,check=0;
	ofstream fout;
	cout<<"\nEnter Level(0-3): ";
	cin>>level;
	cout<<"\nBranch Code: 0.CSE   1.COM   2.MULTIMEDIA   3.EEE";
	cout<<"\n             4.Mechatronic 5.AUTOMOBILE   6.EE";
	cout<<"\n\nEnter Branch Number(0 to 6): ";
	cin>>branch_no;
	do
	{
		cout<<"\nEnter Year of Addmission(YYYY): ";
		cin>>year;
		if(year>=2000 && year<=2030)
			check=1;
		else
			check=0;
	}while(check!=1);
	cout<<"\nThe tution fee rate: "<<fee(level,branch_no);
	cout<<"\n\nHow many student record you want Enter: ";
	cin>>no_of_record;
	fout.open("student", ios::app);
	for(int i=0;i<no_of_record;i++)
	{
		s1.getDetails(level,branch_no,no_of_record,year);
		fout.write((char *) &s1,sizeof(s1));
		fout.close();
		s1.fileWrite1(s1.intake,(string)s1.name);
		fout.open("student", ios::app);
	}
	fout.close();
	system("pause");
}
void student::fileRead(int power)
{
	int i=0;
	ifstream fcin;
	fcin.open("student", ios::app |ios::in);
	fcin.seekg(0) ;
	while(1)
	{
		fcin.read ((char *) &s1,sizeof(s1));
		if(fcin.eof()!=0)
		    break;
		else
		{
			cout<<"\n@@@@@@@@@@@@@@@@@@@@@--"<<i+1<<". Student Details"<<"--@@@@@@@@@@@@@@@@@@@@@\n";
			i++;
				s1.putDetails();
			//break;
		}
	}
	fcin.close();
	system("pause");
}
void student::loginverification()
{
	int f=0,check=0,counter=0;
	string un,ppw;
	char p,ppw1[40];
	fflush(stdin);
	student student_detail;
	loginGraphic(7,"WELCOME TO GRADING SYSTEM");
	int a=9,b=2;
	gotoxy(a+5,b+2);
	cout<<"Enter User Name: ";
	cin>>un;
	gotoxy(a+22,b+2);
	cout<<"                        ";
	transform(un.begin(), un.end(), un.begin(), toupper);
	gotoxy(a+22,b+2);
	cout<<un;
	gotoxy(a+5,b+4);
	cout<<"Enter Password: ";
	//cin>>ppw;
	while(1)
		{
			
			p=getch();
			if(p>=48 && p<=57)
			{
				strcpy(ppw1,"");
				un="";
				gotoxy(a+5,b+6);
				cout<<"Wrong input! Please enter only alphabet(a-z)\n";
				gotoxy(a+5,b+8);
				system("pause");
				system("cls");
				loginverification();
				break;
				
			}
			else
			{
				
				if(p==13)
					break;
				else
				{
					if(p==8 && counter>0)
					{
						printf("\b ");
						counter--;
						printf("\b");
					}
					else
					{
						cout<<"*";
						ppw1[counter]=p;
						counter++;
					}
				}
			}	
		}
		ppw1[counter]='\0';
		ppw=(string)ppw1;















	login log=login(un,ppw);
	ifstream fcin;
	f=student_detail.loginDetails(un,ppw);
	if(f==1)
	{
		mainmenu();
	}
	if(f==0)
	{
		
		fcin.open("student", ios::app |ios::in);
		fcin.seekg(0);
		while(1)
		{
			fcin.read ((char *) &student_detail,sizeof(student_detail));
			if(fcin.eof()!=0)
			{
				break;	
			}
			if(un.compare(student_detail.intake)==0 && ppw.compare((string)student_detail.name)==0)
			{
				check=1;
				system("cls");
				student_detail.Student_Screen(student_detail);
				system("pause");
				break;
			}
		}	
		fcin.close();
		if(check==0)
		{
			gotoxy(a+5,b+6);
			cout<<"User name or password wrong !Please try again\n";
		}
		else
		{
			gotoxy(a+5,b+6);
			cout<<"User name or password wrong !Please try again\n";
		}
	}

}
void student::studentDelete()
{
	int flag,m,flag12,position;
	string line;
	student s;
	login lod;
	lod.loginGraphic(9,"DELETE STUDENT");
	int a=5,y=4;
	fstream file;
	string search_intake;
	lod.gotoxy(a+8,y);
	cout<<"Eneter Level: ";
	cin>>level;
	lod.gotoxy(a+8,y+2);
	cout<<"Branch Code:0.CSE   1.COM   2.MULTIMEDIA   3.EEE";
	lod.gotoxy(a+14,y+4);
	cout<<"4.Mechatronic  5.AUTOMOBILE    6.EE";
	lod.gotoxy(a+8,y+6);
	cout<<"enter Branch Number: ";
	cin>>branch_no;
	lod.gotoxy(a+8,y+8);
	cout<<"enter student intake: ";
	cin>>search_intake;
	flag=Validation(search_intake);
	if(flag==1)
	{
		file.open("student",ios::in|ios::out);
		file.seekg(0);
		while(1)
		{
			
			file.read ((char *) &s,sizeof(s));
			if(file.eof()!=0)
			{
				break;	
			}
			if(search_intake.compare(s.intake)==0)
			{
				s.status="deactive";
				position=file.tellg();
				file.seekg((position-sizeof(s)),ios::beg);
				file.write((char*)&s,sizeof(s));
				lod.gotoxy(a+8,y+10);
				cout<<"Record Deleted Successfully";
				flag12=1;
				lod.gotoxy(a+8,y+12);
				system("pause");
				break;
			}
		}
	}
	else
	{
		lod.gotoxy(a+8,y+10);
		cout<<"Intake Not Exist";
		lod.gotoxy(a+8,y+12);
		system("pause");
	}
}
void student::DisplayRecord(student &s)//(student &s)
{
	//student s;
	ifstream fcin;
	fcin.open("student", ios::app |ios::in);
	fcin.seekg(0) ;
	cout<<setw(10)<<"Name"<<setw(20)<<"Intake"<<setw(22)<<"Ststus"<<setw(10)<<endl;
	while(1)
	{
		fcin.read ((char *) &s,sizeof(s));
		if(fcin.eof()!=0)
		break;
		else
		{
			if(level==s.level && branch_no==s.branch_no)
			{
				cout<<setw(10)<<s.name<<setw(21)<<s.intake<<setw(21)<<s.status<<setw(21)<<endl;
			}
		}
	}
	system("pause");
}
void student::update()
{
	system("cls");
	int choice,chk=0,gpa1=0,gpa2=0;
	string searchcourse;
	string changestatus;
	student s;
	login lod;
	lod.loginGraphic(24,"UPDATE STUDENT RECORD");
	int a=5,y=4;
	fstream file;
	int flag=0,position=0;

	lod.gotoxy(a+8,y);
	cout<<"Eneter Level: ";
	cin>>level;
	int x=a+4,b=y+1;
	for(int i=0;i<27;i++)
	{
		lod.gotoxy(x,b);
		cout<<"-";
		x=x+2;
	}
	lod.gotoxy(a+8,y+2);
	cout<<"Branch Code:0.CSE   1.COM   2.MULTIMEDIA   3.EEE";
	lod.gotoxy(a+14,y+4);
	cout<<"4.Mechatronic  5.AUTOMOBILE    6.EE";
	lod.gotoxy(a+8,y+6);
	cout<<"enter Branch Number: ";
	cin>>branch_no;
	 x=a+4,b=y+7;
	for(int i=0;i<27;i++)
	{
		lod.gotoxy(x,b);
		cout<<"-";
		x=x+2;
	}
	//lod.gotoxy(a+8,y+8);
	if(validate_level_branch()==0)
	{
		lod.gotoxy(a+8,y+10);
		cout<<"Invalid level or Branch Number\n";
		lod.gotoxy(a+8,y+12);
		system("pause");
		studentmenu();
	}
	 x=a+4,b=y+15;
	for(int i=0;i<27;i++)
	{
		lod.gotoxy(x,b);
		cout<<"-";
		x=x+2;
	}
	lod.gotoxy(a+8,y+9);
	cout<<"**1. Name\t\t2. Update Fee Status";
	lod.gotoxy(a+8,y+10);
	cout<<"**3. Grade upgrade\t4. Deletion Status";
	lod.gotoxy(a+8,y+12);
	cout<<"**5. Display record Intake wise\t6. Quit**\n";
	lod.gotoxy(a+8,y+14);
	cout<<"Enter your choice: ";
	cin>>choice;
	if(choice==1 || choice==2||choice==3 ||choice==4)
	{
		lod.gotoxy(a+8,y+17);
		cout<<"Enter intake of student: ";
		cin>>intake;
		transform(intake.begin(), intake.end(), intake.begin(), toupper);
	}
	file.open("student",ios::in|ios::out|ios::ate);
	file.seekg(0);
	while(1)
	{
		file.read ((char *) &s,sizeof(s));
		if(file.eof()!=0)
		{
			break;	
		}
		if(level==s.level && branch_no==s.branch_no && intake==s.intake)
		{
			flag=1;
			position=file.tellg();
			if(choice==1)
			{
				lod.loginGraphic(14,"");
				lod.loginGraphic(14,"UPDATE STUDENT NAME      ");
				lod.gotoxy(a+10,y+19);//14
				cout<<"Name of student: "<<s.name;
				lod.gotoxy(a+10,y+21);
				cout<<"Please Enter New Name of Student: ";
				fflush(stdin);
				gets(s.name);
				file.seekg((position-sizeof(s)),ios::beg);
				file.write((char*)&s,sizeof(s));
				lod.gotoxy(a+10,y+23);
				cout<<"Nmae Updated Successfully";
				lod.gotoxy(a+10,y+25);
				system("pause");
			}
			if(choice==2)
			{
				lod.loginGraphic(14,"FEE STATUS");
				lod.gotoxy(a+8,y+20);
				cout<<"The Current Status(1.PAID  0.NOT PAID):"<<s.tution_fee_paid;
				lod.gotoxy(a+8,y+22);
				cout<<"Please Enter New Status (1.True  0.False):";
				cin>>s.tution_fee_paid;				
				file.seekg((position-sizeof(s)),ios::beg);
				file.write((char*)&s,sizeof(s));
				lod.gotoxy(a+8,y+24);
				cout<<"Tution fee rate is Updated Successfully";
				lod.gotoxy(a+8,y+26);
				system("pause");
			}
			if(choice==3)
			{
				lod.loginGraphic(18,"GRADE UPDATE MENU");
				lod.gotoxy(a+8,y+19);
				cout<<"Course name\tcourse Code\tGrade";
				y=y+20;
				for(int i=0;i<s.total_course;i++)
				{
					lod.gotoxy(a+8,y);
					cout<<s.course_name[i]<<"\t\t"<<s.course_code[i]<<"\t\t"<<s.grade[i];
					y=y+2;
				}
				lod.gotoxy(a+7,y);
				cout<<"Enter the course : ";
				cin>>searchcourse;
				for(int i=0;i<s.total_course;i++)
				{
					if(searchcourse==s.course_name[i])
					{
						position=file.tellg();
						char *credit_hour=new char[(s.credit_hr[i]).size()+1];
						credit_hour[s.credit_hr[i].size()]=0;
						memcpy(credit_hour,(s.credit_hr[i]).c_str(),(s.credit_hr[i]).size());
						//s1.total_credit_hr=s1.total_credit_hr+atoi(credit_hour);
						gpa1=(atoi(credit_hour)*s.grade1[i]);
						lod.gotoxy(a+7,y+2);
						cout<<"Enter new Grade for course "<<s.course_name[i]<<": ";
						cin>>s.grade[i];
						if(string(s.grade[i]).compare("A")==0 ||string(s.grade[i]).compare("a")==0)
						{
							s.grade1[i]=5;
						}
						 if(string(s.grade[i]).compare("B")==0 ||string(s.grade[i]).compare("b")==0)
							s.grade1[i]=4;
						 if(string(s.grade[i]).compare("C")==0 ||string(s.grade[i]).compare("c")==0)
							s.grade1[i]=3;
						 if(string(s.grade[i]).compare("D")==0 ||string(s.grade[i]).compare("d")==0)
							s.grade1[i]=2;
						 if(string(s.grade[i]).compare("E")==0 ||string(s.grade[i]).compare("e")==0)
							s.grade1[i]=1;
						 if(string(s.grade[i]).compare("F")==0 ||string(s.grade[i]).compare("f")==0)
							s.grade1[i]=0;
						 gpa2=(atoi(credit_hour)*s.grade1[i]);
						 chk=1;
						 break;
					}
				}
				if(chk==1)
				{
					s.gpa=s.gpa-gpa1+gpa2;
					s.finalgpa=s.gpa/(s.total_credit_hr*1.0);
					file.seekg((position-sizeof(s)),ios::beg);
					file.write((char*)&s,sizeof(s));
					lod.gotoxy(a+10,y+4);
					//chk=1;
					lod.gotoxy(a+10,y+6);
					cout<<"Grade updated successfully";
					lod.gotoxy(a+10,y+8);
					system("pause");
					break;
						
				}
				if(chk==0)
					lod.gotoxy(a+8,y+8);
					cout<<"Course name not exist";
			}
			if(choice==4)
			{
				lod.loginGraphic(14,"UPDATE DELETION STATUS");
				lod.gotoxy(a+8,y+21);
				cout<<"Enter Status (1 for Active && 2 for Deactive):";
				cin>>changestatus;
				if(changestatus.compare("1")==0)
					s.status="active";
				if(changestatus.compare("2")==0)
					s.status="deactive";
				if(changestatus!="1" && changestatus!="0")
				{
					lod.gotoxy(a+8,y+23);
					cout<<"Invalid Selection ! Please try again";
				}
				file.seekg((position-sizeof(s)),ios::beg);
				file.write((char*)&s,sizeof(s));
				lod.gotoxy(a+8,y+23);
				cout<<"Status updated Successfully\n";
				lod.gotoxy(a+8,y+25);
				system("pause");
				break;
			}
		}
		if(choice==5)
		{
			system("cls");
			s.DisplayRecord(s);
			break;
		}
	}

	file.close();
}