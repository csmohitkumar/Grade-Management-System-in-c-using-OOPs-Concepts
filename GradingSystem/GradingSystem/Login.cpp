#include<iostream>
#include "Login.h"
#include<fstream>
#include <algorithm>
#include<conio.h>
class login log;
fstream file;
void login::putData(int x,int y)
{
	gotoxy(x+6,y+6);
	cout<<admin_username;
	gotoxy(x+30,y+6);
	cout<<admin_password<<"\n";
}
void login::fileWrite()
{
	int auth=0; 
	string un,ppw;
	char p,ppw1[40];
	int counter=0;
	fflush(stdin);
	system("cls");
	ofstream fcout;
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
	cin>>ppw;
	while(1)
		{
			
			p=getch();
			if(p>=48 && p<=57)
			{
				strcpy(ppw1,"");
				cout<<"\nbye\n";
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



    fcout.open("Login", ios::app |ios::out);
	log=login(ppw,un);
	auth=validation(un,ppw);
	if(auth==1)
	{
		gotoxy(a+5,b+6);
		cout<<"Username Exist please try again\n";
	}
	if(auth==99)
	{
		fcout.write ((char *) &log,sizeof(log));
		gotoxy(a+5,b+6);
		cout<<"write success\n";
	}
	file.close();
	gotoxy(a+5,b+8);
	system("pause");
}
void login::fileWrite1(string u,string p)//for student
{
	login log1;
	ofstream fcout;
	transform(u.begin(), u.end(), u.begin(), toupper);
	log1.admin_username=u;
	log1.admin_password=p;
	fcout.open("Login", ios::app |ios::out);
	fcout.write ((char *) &log1,sizeof(log1));
	file.close();

}

void login::fileRead()
{
	file.open("Login", ios::app |ios::in);
	file.seekg(0) ;
	int x=9,y=0;
	for(int i=0;i<27;i++)
	{
		gotoxy(x,y);
		cout<<"*";
		x=x+2;
	}
	x=9;y=4;
	for(int i=0;i<27;i++)
	{
		gotoxy(x,y);
		cout<<"*";
		x=x+2;
	}
	x=9;y=0;
	gotoxy(x+12,y+2);
	cout<<"Welcome To Registration Details";
	x=9;y=2;
	gotoxy(x+6,y+4);
	cout<<"user Name";
	gotoxy(x+30,y+4);
	cout<<"Password";
	while(1)
	{
		file.read ((char *) &log,sizeof(log));
		if(file.eof()!=0)
		{
			break;
		}
		else
		{
			log.putData(x,y);
			y=y+2;
		}
	}
	file.close();
	system("pause");
}
int login::validation(string un,string pw)
{
	int i=99;
	login d;
	ifstream fcin;
	fcin.open("Login", ios::ate |ios::in);
	fcin.seekg((sizeof(d)),ios::beg);
	while(1)
	{
		fcin.read ((char *) &d,sizeof(d));
		if(fcin.eof()!=0)
		{
			break;	
		}
		if(un==d.admin_username && pw==d.admin_password)
		{
				i=1;
				break;
		}
	}	
	fcin.close();
	return i;
}
int login::loginDetails(string un,string ppw)
{
	int auth=0;
	fstream file;
	transform(un.begin(), un.end(), un.begin(), toupper);
	file.open("Login", ios::ate |ios::in);
	file.seekg(0,ios::beg);
	file.read ((char *) &log,sizeof(log));
	if(un==log.admin_username && ppw==log.admin_password)
	{
		auth=1;
	}
	file.close();
	return auth;
}

void login::gotoxy(int xpos,int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}
void login::loginGraphic(int vertical,string message)
{
	int x=1,y=2,a=9,b=0;
	for(int i=0;i<27;i++)
	{
		gotoxy(a,b);
		cout<<"*";
		a=a+2;
	}
	a=9;b=0;
	gotoxy(a+20,1);
	cout<<message;
	for(int i=0;i<27;i++)
	{
		gotoxy(a,b+2);
		cout<<"*";
		a=a+2;
	}
	a=9;b=0;
	for(int i=0;i<vertical;i++)//7
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
	for(int i=0;i<vertical;i++)//7
	{
		gotoxy(a,b+2);
		cout<<"*";
		b=b+2;
	}

}