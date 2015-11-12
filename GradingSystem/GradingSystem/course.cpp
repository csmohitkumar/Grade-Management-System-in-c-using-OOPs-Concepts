#include "course.h"
#include <algorithm>
void course::getlevel()
{
	int check=0;
	do
	{
		try
		{
			cout<<"\nEnter Level: ";
			cin>>level;
			if(level>=0 && level<4)
				check=1;
		}
		catch(istream::failure e)
		{
			check=0;
			fflush(stdin);
			cin.clear();
		}
	}while(check!=1);
}
void course::getbranch()
{
	int c=0;
	string br;
	while(1)
	{
		br="";
		cout<<"\n\nEnter Char_Branch_Name name of level "<<level<<": ";
		cin>>Char_Branch_Name;
		br=(string)Char_Branch_Name;
		transform(br.begin(), br.end(), br.begin(),::toupper);
		if(br.compare("CSE")==0 ||br.compare("COM")==0||br.compare("MULTIMEDIA")==0||br.compare("EEE")==0||br.compare("MECHATRONIC")==0||br.compare("AUTOMOBILE")==0||br.compare("EE")==0)
		{
			c=1;
			break;
		}
		else
		{
			c=0;
			getbranch();
		}
	}
}
void course::getbranch_no()
{
	int check=0;
	string br="";
	br=(string)Char_Branch_Name;
	transform(br.begin(), br.end(), br.begin(),::toupper);
	if(br.compare("CSE")==0)
		branch_no=0;
	if(br.compare("COM")==0)
		branch_no=1;
	if(br.compare("MULTIMEDIA")==0)
		branch_no=2;
	if(br.compare("EEE")==0)
		branch_no=3;
	if(br.compare("MECHATRONIC")==0)
		branch_no=4;
	if(br.compare("AUTOMOBILE")==0)
		branch_no=5;
	if(br.compare("EE")==0)
		branch_no=6;
	cout<<"\nBranch Number : "<<branch_no;

}
void course::getno_of_course()
{
	int check=0;
	do
		{
			check=1;
			try
			{
				cout<<"\nPlease Enter New Tuition fee rate: RS ";
				cin>>tution_fee_amount;
				cout<<"number of courses you want to enter: ";
				cin>>no_of_course;
				if(no_of_course>0 && no_of_course<=10)
					check=1;
			}
			catch(istream::failure e)
			{
				check=0;
				fflush(stdin);
				cin.clear();
			}
		}while(check!=1);
}
void course::getcoursedetails()
{
	string course_nm[30],course_Num[10];
	int check=0,generate=1;
	char char_level[10][11],char_branch_no[10][11],char_last[10][11];
	for(int i=0;i<no_of_course;i++)
		{
			make_course_code[i]="";
			//strcmp(course_no[i],"");
			cout<<"\n\t"<<i+1<<". enter course name: ";
			cin>>course_name[i];

			itoa(level,char_level[i],10);
			itoa(branch_no,char_branch_no[i],10);
			itoa(generate,char_last[i],10);
			strcpy(course_no[i],"");
			strcat(course_no[i],char_level[i]);
			strcat(course_no[i],char_branch_no[i]);
			strcat(course_no[i],char_last[i]);
			course_nm[i]=(string)course_name[i];
			transform(course_nm[i].begin(), course_nm[i].end(), course_nm[i].begin(), toupper);
			course_nm[i]=course_nm[i].substr(0,3);
			make_course_code[i].append(course_nm[i]);
			make_course_code[i].append(course_no[i]);
			cout<<"\n\t"<<i+1<<". Course code: "<<make_course_code[i];
			cout<<"\n\n\t"<<i+1<<". Credit Hour for "<<course_name[i]<<" :";
			cin>>credit_hr[i];
			generate++;
		}


}
void course::getDetails()
{
	int check_Branch,k=0,check=0;
	int u=0,a=6,y=2;
	login lod;
	lod.gotoxy(a+8,y+6);
	cout<<"Branch Code:0.CSE   1.COM   2.MULTIMEDIA   3.EEE";
	lod.gotoxy(a+14,y+8);
	cout<<"4.Mechatronic 5.AUTOMOBILE   6.EE";
	getbranch();
	getbranch_no();
	check_Branch=BranchExist();
	if(check_Branch==0)
	{
		getno_of_course();
		getcoursedetails();
	}
	else
	{
		cout<<"\n\tBRANCH ALREADY EXIST\n\t";
		system("pause");
		coursemenu();
	}

}
void course::putDetails()
{
	
	cout<<"\nLevel: "<<level<<"\nBranch name: "<<Char_Branch_Name<<"\nBranch Number: "<<branch_no<<"\nTuition Fee rate: "<<tution_fee_amount;
	cout<<"\n\tCOURSE NAME\t\tCOURSE CODE\t\tCridit hour"<<endl;
	for(int i=0;i<no_of_course;i++)
	{
	
		cout<<"\n\t"<<course_name[i]<<"\t\t\t  "<<make_course_code[i]<<"\t\t  "<<credit_hr[i];
	}
	cout<<endl;
}
void course::fileWrite()
{
	int n=0;
	char ch;
	ofstream fout;
	course c;
	c.getlevel();
	fout.open("course", ios::app);
	do
	{
		c.getDetails();
		fout.write((char *) &c,sizeof(c));
		cout<<"\n\nDO Yoy Want to Add More Record in same level(Y/N): ";
		cin>>ch;
		system("cls");
	}while(ch=='y' || ch=='Y');
}
void course::fileRead()
{
	course c;
	int i=0;
	ifstream fcin;
	fcin.open("course", ios::app |ios::in);
	fcin.seekg(0) ;
	while(1)
	{
		fcin.read ((char *) &c,sizeof(c));
		if(fcin.eof()!=0)
		break;
		else
		{
			cout<<"\n@@@@@@@@@@@@@@@@@@@@@--"<<i<<". Details of course"<<"--@@@@@@@@@@@@@@@@@@@@@\n";
			i++;
			c.putDetails();
		}
	}
	fcin.close();
	system("pause");
}

int course::BranchExist()
{
	int i=0;
	course c;
	ifstream fcin;
	fcin.open("course", ios::app |ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read ((char *) &c,sizeof(c));
		if(fcin.eof()!=0)
		{
			break;	
		}
		if(level==c.level && branch_no==c.branch_no)
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
int course::courseExist(string search_course_nm)
{
	string file_course_nm;
	int flag=0,n,history;
	course c;
	ifstream fcin;
	
	fcin.open("course", ios::app |ios::in);
	fcin.seekg(0);
	while(1)
	{
		fcin.read ((char *) &c,sizeof(c));
		if(fcin.eof()!=0)
		{
			break;	
		}
		if(level==c.level && branch_no==c.branch_no)
		{
			n=c.no_of_course;
			for(int j=0;j<n;j++)
			{
				file_course_nm=(string)c.course_name[j];
				if(search_course_nm==file_course_nm)
				{
					flag=j+1;
					break;
				}
			}
		}	
	}	
	fcin.close();
	return flag;
}
void course::courseUpdate()
{
	system("cls");
	int choice;
	int j,i;
	char char_i[10];
	char char_level[10][11],char_branch_no[10][11],char_last[10][11];
	string course_nm[30],course_Num[10],search_course_nm;
	course c;
	fstream file;
	int flag=0,position=0;
	login lod;
	lod.loginGraphic(6,"WELCOME TO UPDATE MENU");
	int a=6,y=4;
	lod.gotoxy(a+6,y);
	cout<<"1. Add New course\t2.Change in Existing one";
	lod.gotoxy(a+6,y+2);
	cout<<"3. update Tuition fee Rate\t4.Exit";
	lod.gotoxy(a+8,y+4);
	cout<<"Enter your option: ";
	cin>>choice;
	if(choice!=4)
	{
		system("cls");
		if(choice==1)
			lod.loginGraphic(8,"ADD NEW COURSE");
		if(choice==2)
			lod.loginGraphic(12,"UPDATE EXISTING COURSE");
		if(choice==3)
			lod.loginGraphic(8,"UPDATE TUITION FEE");
		lod.gotoxy(a+6,y);
		cout<<"Enter Level: ";
		cin>>level;
		lod.gotoxy(a+6,y+2);
		cout<<"Branch Code:0.CSE   1.COM   2.MULTIMEDIA   3.EEE";
		lod.gotoxy(a+15,y+4);
		cout<<"4.Mechatronic  5.AUTOMOBILE    6.EE";
		lod.gotoxy(a+6,y+8);
		cout<<"enter Branch Number: ";
		cin>>branch_no;
	}
	flag=BranchExist();
	file.open("course",ios::in|ios::out|ios::ate);
	file.seekg(0);
	while(1 && flag==1)
	{
		file.read ((char *) &c,sizeof(c));
		if(file.eof()!=0)
		{
			break;	
		}
		if(level==c.level && branch_no==c.branch_no)
		{
			position=file.tellg();
			if(choice==2)
			{
				//lod.loginGraphic(12,"UPDATE EXISTING COURSE");
				cout<<"\n\t   Enter course name which you want to update: ";
				cin>>search_course_nm;
				i=0;
				j=c.courseExist(search_course_nm);
				if(j!=0)
				{
					i=j-1;
					make_course_code[i]="";
					cout<<"\n\t\t"<<i+1<<". enter course name: ";
					cin>>c.course_name[i];
					itoa(level,char_level[i],10);
					itoa(branch_no,char_branch_no[i],10);
					itoa(j,char_i,10);
					strcpy(course_no[i],"");
					strcat(course_no[i],char_level[i]);
					strcat(course_no[i],char_branch_no[i]);
					strcat(course_no[i],char_i);
					course_nm[i]=(string)c.course_name[i];
					transform(course_nm[i].begin(), course_nm[i].end(),course_nm[i].begin(), toupper);
					course_nm[i]=course_nm[i].substr(0,3);
					make_course_code[i].append(course_nm[i]);
					make_course_code[i].append(course_no[i]);
					c.make_course_code[i]=make_course_code[i];
					cout<<"\n\t\tCourse code: "<<c.make_course_code[i];
					cout<<"\n\n\t\t"<<i+1<<". Credit Hour for "<<c.course_name[i]<<" :";
					cin>>c.credit_hr[i];		
					file.seekg((position-sizeof(c)),ios::beg);
					file.write((char*)&c,sizeof(c));
					cout<<"\n\t@@@@@@@@@@@@@--Course Updated Successfully--@@@@@@@@@@@@@@@\n";
					system("pause");
					courseUpdate();		
				}
				else
				{
					cout<<"\n@@@@@@@@@@@@@@@@@Course Not exist@@@@@@@@@@@@@\n";
					courseUpdate();
				}
			}
			if(choice==3)
			{
				lod.loginGraphic(11,"UPDATE TUITION FEE");
				lod.gotoxy(a+6,y+10);
				cout<<"Current tuition fee rate: "<<c.tution_fee_amount;
				lod.gotoxy(a+6,y+12);
				cout<<"Please Enter New rate: ";
				cin>>c.tution_fee_amount;
				file.seekg((position-sizeof(c)),ios::beg);
				file.write((char*)&c,sizeof(c));
				lod.gotoxy(a+6,y+16);
				cout<<"Rate Updated Successfully";
				lod.gotoxy(a+6,y+18);
				system("pause");
				courseUpdate();
			}
			if(choice!=4)
			{
				system("cls");
				cout<<"\n**************************************************************\n";
				cout<<"\##		      Add New course In level: "<<c.level<<"           ##\n";
				cout<<"\n**************************************************************\n";
				c.putDetails();
			}
		    break;
		}
	}
	if(choice==1 && flag==1)
	{
		if(c.no_of_course<=10)
		{

			c.updateOption_add(c,'y');
			file.seekg((position-sizeof(c)),ios::beg);
			file.write((char*)&c,sizeof(c));
			cout<<"@@@@@@@@@@@@@@@@@--Course Added Successfully--@@@@@@@@@@@@@@@@@@@@@\n";
			system("pause");
			courseUpdate();
		}
		else
		{
			cout<<"\n@@@@@@@@@@@@@@--Maximum Course Limit is Riched--@@@@@@@@@@@@@@@@@\n";
		}
	}
	
	if(choice>=5 && flag==1)
	{
		cout<<"\n\t@@@@@@@@@@@--Invalid selection--@@@@@@@@@@@@@@@\n";
		system("pause");
		courseUpdate();
	}
	if(choice==4)
		coursemenu();
	if(flag==0)
	{
		cout<<"\nBranch not Exist\n";
	}
	file.close();
}
void course::updateOption_add(course& c,char ch)
{
	int j=0,generate=2;
	char char_level[10][11],char_branch_no[10][11],char_last[10][11];
	string course_nm[30],course_Num[10];
	if(ch=='y' || ch=='Y')
	{
		level=c.level;
		strcpy(Char_Branch_Name,c.Char_Branch_Name);
		branch_no=c.branch_no;
		tution_fee_amount=c.tution_fee_amount;
		for(j=0;j<c.no_of_course;j++)
		{
			strcpy(course_name[j],c.course_name[j]);
			strcpy(course_no[j],c.course_no[j]);
			make_course_code[j]=c.make_course_code[j];
			credit_hr[j]=c.credit_hr[j];
		}
		int i;
		i=j;
		generate=i+1;
		//generate=j;
		do
		{
			if(i<=10)
			{
				
				strcpy(char_last[i],"");
				make_course_code[i]="";
				cout<<"\n\t\t"<<i+1<<". enter course name: ";
				cin>>course_name[i];
				itoa(level,char_level[i],10);
				itoa(branch_no,char_branch_no[i],10);
				itoa(generate,char_last[i],10);
				strcpy(course_no[i],"");
				strcat(course_no[i],char_level[i]);
				strcat(course_no[i],char_branch_no[i]);
				strcat(course_no[i],char_last[i]);

				course_nm[i]=(string)course_name[i];
				transform(course_nm[i].begin(), course_nm[i].end(), course_nm[i].begin(), toupper);
				course_nm[i]=course_nm[i].substr(0,3);
				make_course_code[i].append(course_nm[i]);
				make_course_code[i].append(course_no[i]);
				cout<<"\n\t\t"<<i+1<<". Course code: "<<make_course_code[i];
				cout<<"\n\n\t\t"<<i+1<<". Credit Hour for "<<course_name[i]<<" :";
				cin>>credit_hr[i];
				i++;
				generate++;
				//no_of_course=no_of_course-no_of_course+i;
				cout<<"\nDo you want to add more record(y/n): ";
				cin>>ch;
			}
			else
			{
				cout<<"\n@@@@@--Maximum Limit of course Limit Riched--@@@@@\n";
				system("pause");
				courseUpdate();
			}
		}while((ch=='y' || ch=='Y') && no_of_course<=10);
		no_of_course=i;
			
	}
}


void course::deletefun()
{
	int flag2=0,j=0;
	int flag,m,flag12,position;
	string file_course_nm2,line,msg="DELETE COURSE";
	course c;
	login lod;
	lod.loginGraphic(7,msg);
	int a=5,y=4;
	fstream file;
	string search_course_nm;
	lod.gotoxy(a+8,y);
	cout<<"Eneter Level: ";
	cin>>level;
	lod.gotoxy(a+8,y+2);
	cout<<"Branch Code:0.CSE   1.COM   2.MULTIMEDIA   3.EEE";
	lod.gotoxy(a+14,y+4);
	cout<<"4.Mechatronic  5.AUTOMOBILE   6.EE";
	lod.gotoxy(a+8,y+6);
	cout<<"enter Branch Number: ";
	cin>>branch_no;
	lod.gotoxy(a+8,y+8);
	cout<<"enter course name: ";
	cin>>search_course_nm;
	flag=courseExist(search_course_nm);
	if(flag==0)
	{
		lod.gotoxy(a+8,y+10);
		cout<<"course not exist";
		lod.gotoxy(a+8,y+12);
		system("pause");
		coursemenu();
	}
	if(flag!=0)
	{
		file.open("course",ios::in|ios::out|ios::ate);
		file.seekg(0);
		while(1)
		{
			file.read ((char *) &c,sizeof(c));
			if(file.eof()!=0)
			{
				break;	
			}
			if(level==c.level && branch_no==c.branch_no)
			{
				flag12=1;
				position=file.tellg();
				for(int i=0;i<c.no_of_course;i++)
				{
					if(i==flag-1)
					{
						flag2=1;
						i=i-1;
						flag=99;
					}
					else
					{
						
						if(flag2==0)
						{
							j=i;
							strcpy(c.course_name[i],c.course_name[j]);
							strcpy(c.course_no[i],c.course_no[j]);
							c.make_course_code[i]=c.make_course_code[j];
							c.credit_hr[i]=c.credit_hr[j];
							
						}
						else
						{
							j=i+1;
							strcpy(c.course_name[i],c.course_name[j]);
							strcpy(c.course_no[i],c.course_no[j]);
							c.make_course_code[i]=c.make_course_code[j];
							c.credit_hr[i]=c.credit_hr[j];
						}
					}
					j++;
				}
				c.no_of_course=c.no_of_course-1;;
				lod.gotoxy(a+8,y+10);
				cout<<"@@@@@@@@@Record deleted@@@@@@@@";
				file.seekg((position-sizeof(c)),ios::beg);
				file.write((char*)&c,sizeof(c));
				file.close();
				break;
			}
		}
	}
	else
	{

	}
}




