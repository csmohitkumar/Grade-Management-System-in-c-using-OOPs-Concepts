#include "Login.h"
#include "course.h"
#include "student.h"
void mainmenu()
{
	login lod;
	
	int ch;
	do
	{
		system("cls");
		lod.loginGraphic(7,"WELCOME TO GRADING SYSTEM");
		int a=9,y=4;
		lod.gotoxy(a+10,y);
		cout<<"1. User Management";
		lod.gotoxy(a+10,y+2);
		cout<<"2. Course Management";
		lod.gotoxy(a+10,y+4);
		cout<<"3. Student Management";
		lod.gotoxy(a+10,y+6);
		cout<<"4. Quit";
		lod.gotoxy(a+10,y+8);
		cout<<"Enter Your Option:";
		cin>>ch;
		switch(ch)
		{
		case 1:
				LoginMenu();
			break;
		case 2:
			coursemenu();
			break;
		case 3:
			studentmenu();
			break;
		case 4:
			break;
		default:
			lod.gotoxy(a+10,y+10);
			cout<<"Error in input ! try Again";
			lod.gotoxy(a+10,y+14);
			system("pause");
			break;
		}
	}while(ch!=4);
}
void LoginMenu()
{
	login lod;
	int choice,authentation; 
	do
	{
		system("cls");
		lod.loginGraphic(7,"USER MANAGEMENT");
		int a=9,y=4;
		lod.gotoxy(a+10,y);
		cout<<"1.Registration";
		/*lod.gotoxy(a+10,y+2);
		cout<<"2.Login As Student";*/
		lod.gotoxy(a+10,y+3);
		cout<<"2.Display Registration Details";
		lod.gotoxy(a+10,y+6);
		cout<<"3.Quit";
		lod.gotoxy(a+10,y+8);
		cout<<"Enter your Option: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			system("cls");
			lod.fileWrite();
			break;
		case 2:
			system("cls");
			lod.fileRead();
			break;
		case 3:
			
			break;
		default:
			lod.gotoxy(a+10,y+10);
			cout<<"Error in input ! try Again";
			lod.gotoxy(a+10,y+14);
			system("pause");
			break;
		}
	}while(choice!=3);
}

void coursemenu()
{
	int ch;
	login lod;
	int level2,branch2,index=-1;
	course c;
	do
	{
		system("cls");
		lod.loginGraphic(9,"COURSE MANAGEMENT");
		int a=9,y=4;
		lod.gotoxy(a+10,y);
		cout<<"1. Add New Course Record";
		lod.gotoxy(a+10,y+2);
		cout<<"2. Display All Course Records";
		lod.gotoxy(a+10,y+4);
		cout<<"3. Delete Cource Record";
		lod.gotoxy(a+10,y+6);
		cout<<"4. Update Records";
		lod.gotoxy(a+10,y+8);
		cout<<"5. exit";
		lod.gotoxy(a+10,y+10);
		cout<<"Enter Your Option: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			system("cls");
			a=0,y=1;
			for(int i=0;i<40;i++)
			{
				lod.gotoxy(a,y);
				cout<<"*";
				a=a+2;
			}
			a=0;y=4;
			for(int i=0;i<40;i++)
			{
				lod.gotoxy(a,y);
				cout<<"*";
				a=a+2;
			}
			lod.gotoxy(26,2);
			cout<<"Course Details";
			lod.gotoxy(0,6);
			c.fileWrite();
			break;
		case 2:
			system("cls");
			a=0,y=1;
			for(int i=0;i<40;i++)
			{
				lod.gotoxy(a,y);
				cout<<"*";
				a=a+2;
			}
			a=0;y=3;
			for(int i=0;i<40;i++)
			{
				lod.gotoxy(a,y);
				cout<<"*";
				a=a+2;
			}
			lod.gotoxy(26,2);
			cout<<"Course Details";
			lod.gotoxy(0,4);	
			c.fileRead();
			break;
		case 3:
			system("cls");
			c.deletefun();
			break;
		case 4:
			system("cls");
			c.courseUpdate();
		break;
		case 5:
			break;
		default:
			lod.gotoxy(a+10,y+11);
			cout<<"Error in input ! try Again";
			lod.gotoxy(a+10,y+14);
			system("pause");
		}
		system("pause");
	}while(ch!=5);
	//system("pause");
}

void studentmenu()
{
	login lod;
	int ch;
	student s;
	do
	{
		system("cls");
		lod.loginGraphic(9,"STUDENT MANAGEMENT");
		int a=9,y=4;
		lod.gotoxy(a+10,y);
		cout<<"1. Add Student Record";
		lod.gotoxy(a+10,y+2);
		cout<<"2. Display Student Details";
		lod.gotoxy(a+10,y+4);
		cout<<"3. Delete Student Record";
		lod.gotoxy(a+10,y+6);
		cout<<"4. Update Student Record";
		lod.gotoxy(a+10,y+8);
		cout<<"5. Quit";
		lod.gotoxy(a+10,y+10);
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			system("cls");
			a=0,y=1;
			for(int i=0;i<40;i++)
			{
				lod.gotoxy(a,y);
				cout<<"*";
				a=a+2;
			}
			a=0;y=4;
			for(int i=0;i<40;i++)
			{
				lod.gotoxy(a,y);
				cout<<"*";
				a=a+2;
			}
			lod.gotoxy(26,2);
			cout<<"Student Details";
			lod.gotoxy(0,6);
			s.fileWrite();
			break;
		case 2:
			system("cls");
			a=0,y=1;
			for(int i=0;i<40;i++)
			{
				lod.gotoxy(a,y);
				cout<<"*";
				a=a+2;
			}
			a=0;y=4;
			for(int i=0;i<40;i++)
			{
				lod.gotoxy(a,y);
				cout<<"*";
				a=a+2;
			}
			lod.gotoxy(28,2);
			cout<<"Student Details";
			lod.gotoxy(0,6);
			s.fileRead(1);//1for admin 0 for student
			//s.display();
			break;
		case 3:
			system("cls");
			//c.courseExist();
			s.studentDelete();
			break;
		case 4:
			//s.DisplayRecord();
			s.update();
			//c.courseUpdate();
		break;
		case 5:
			break;
		default:
			lod.gotoxy(a+12,y+12);
			cout<<"Invalid Input";
			lod.gotoxy(a+10,y+14);
			system("pause");
			break;
		}
		
	}while(ch!=5);
	//system("pause");
}