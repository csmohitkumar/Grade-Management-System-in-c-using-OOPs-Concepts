#ifndef LOGIN_H
#define LOGIN_H
#include <string>
#include<iostream>
void mainmenu();
#include<fstream>
#include<windows.h>
void LoginMenu();
using namespace std;
class login
{
private:
	string admin_username,admin_password,uname;
	int authentication;
public:
	login()
	{
		admin_username=""; 
		admin_password="";
	}
	login(string u,string p)
	{
		admin_username=p;
		admin_password=u;
	}
	void gotoxy(int xpos,int ypos);
	void putData(int x,int y);
	void fileWrite1(string u,string p);
	void fileWrite();
	void fileRead();
	int validation(string,string);
	int loginDetails(string,string);
	void loginGraphic(int,string);
};
#endif

