#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<iomanip.h>
#include<process.h>
#include<dos.h>
class ATM
{
public:
int atmno,loading;
int dd,mm,yy,make;
char bname[50],place[20],d,m,y;
void accept()
	{
	cout<<"Enter the following details: ";
	date();
	cout<<"\nATM ID Number: ";
	cin>>atmno;
	cout<<"\nMachine Make(1.Diebold 2.Wincor 3.Ncr 4.Hyosung): ";
	cin>>make;
	cout<<"\nPlace: ";
	gets(place);
	cout<<"\nBank Name: ";
	gets(bname);
	cout<<"Loading: ";
	cin>>loading;
	}
void date()
	{
	struct date f;
	getdate(&f);
	dd=f.da_day;
	mm=f.da_mon;
	yy=f.da_year;
	}
void display()
	{
	cout<<endl;
	cout<<"The details are: "<<endl;
	cout<<"ATM Number: ";
	cout<<atmno;
	cout<<endl;
	cout<<"Date: ";
	cout<<dd<<"/"<<mm<<"/"<<yy;
	cout<<endl;
	cout<<"Bank Name: ";
	puts(bname);
	cout<<"Place: ";
	puts(place);
	}
};
class call_service
{
char problem[50],cname[25],d,m,rl,y,status,rdate[25],sename[25];
int atmno,dtime,crno;
int dd,mm,yy,rd,rm,ry;
public:
void accept()
	{
	cout<<"Enter the details";
	date();
	cout<<"\nATM ID Number: ";
	cin>>atmno;
	cout<<"Problem: ";
	gets(problem);
	cout<<"Status of rectification(y/n): ";
	cin>>status;
	cout<<"Custodian name: ";
	gets(cname);
	cout<<"Down Time(Enter in hours): ";
	cin>>dtime;
	cout<<"Call Reference Number: ";
	cin>>crno;
	if(status=='y')
	{	rectdate();
	cout<<"Enter the service engineer name: ";
	gets(sename);
	}
	}
void date()
	{
	struct date f;
	getdate(&f);
	dd=f.da_day;
	mm=f.da_mon;
	yy=f.da_year;
	}
void display()
	{
	cout<<"\nATM ID Number: "<<atmno;
	cout<<"\nDate: "<<dd<<"/"<<mm<<"/"<<yy;
	cout<<"\nProblem Identified: "<<problem;
	cout<<"\nCustodian Name: "<<cname;
	cout<<"\nDowntime: "<<dtime;
	cout<<"\nRectified or not(y/n): "<<status;
	if(status=='y')
		{
		cout<<"\nService Engineer Name: "<<sename;
		cout<<"\nCall Reference number: "<<crno;
		cout<<"\nThe rectified date is: "<<rd<<"/"<<rm<<"/"<<ry;
		}
	}
void rectdate()
	{
	rl:
	cout<<"\nEnter the rectified date"<<endl;
	cout<<"Date(dd): ";
	cin>>rd;
	cout<<"Month(mm): ";
	cin>>rm;
	cout<<"Year(yyyy): ";
	cin>>ry;
	if(ry==yy)
		{
		if(rm=mm)
			{
			if(rd>dd)
			{
			cout<<"The date is invalid";

			goto rl;
			}
			}
		if(rm>mm)
			{
			cout<<"The date is invalid";
			goto rl;
			}
		}
	if(ry>yy)
		{
		cout<<"The date is invalid";;
		goto rl;
		}
	}
char func()
	{
	return status;
	}
};

class cash_recharge
{
int dd,mm,yy;
char d,m,y;
long int atmno,loading,obal,cbal;
long int dispense;
public:
void accept()
	{
	cout<<"Enter the following details";
	date();
	cout<<"\nATM ID Number: ";
	cin>>atmno;
	cout<<"Loading: ";
	cin>>loading;
	cout<<"Opening Balalnce: ";
	cin>>obal;
	cout<<"Closing Balance: ";
	cin>>cbal;
	cout<<"Dispense: ";
	cin>>dispense;
	}
void date()
	{
	struct date f;
	getdate(&f);
	dd=f.da_day;
	mm=f.da_mon;
	yy=f.da_year;
	}
void display()
	{
	cout<<"\nDate: "<<dd<<"/"<<mm<<"/"<<yy;
	cout<<"\nATM ID Number: "<<atmno;
	cout<<"\nOpening Balance: "<<obal;
	cout<<"\nDispense: "<<dispense;
	cout<<"\nClosing Balance: "<<cbal;
	cout<<"\nLoading: "<<loading;;
	}
long int ispense()
	{
	return dispense;
	}
};

void atm_register()
	{
	ATM x;
	cout<<"ATM Register";
	cout<<endl;
	ifstream fin("ATM.dat",ios::binary);
	fin.seekg(0);
	if(!fin)
		cout<<"Error in opening the file";
	else
		while(!fin.eof())
		{
		fin.read((char*)&x,sizeof(x));
		if(fin.eof())
		break;
		x.display();
		}
	fin.close();
	}

void installation()
	{
	ofstream fout("ATM.dat",ios::app|ios::binary);
	ATM x;
	cout<<endl<<"Installation of a new ATM"<<endl;
	char m;
	char j;
	m:
	x.accept();

	cout<<"\nThe details you have entered are: ";
	x.display();
	cout<<"\nDo you want to change?(y/n): ";
	cin>>j;
	if(j=='y')
	goto m;
	if(!fout)
		cout<<"Error in opening the file";
	else
		{
		fout.write((char*)&x,sizeof(x));
		}
	cout<<"\nThe details have been entered into the register";
	fout.close();
	}

void cash_replenish()
	{
	ofstream fout2("CR.dat",ios::app|ios::binary);
	fout2.seekp(0);
	cash_recharge x;
	cout<<"\nCash Replenish"<<endl;
	char m;
	char j;
	m:
	x.accept();
	cout<<"\nThe details you have entered are: ";
	x.display();
	cout<<"\nDo you want to change?(y/n): ";
	cin>>j;
	if(j=='y')
	goto m;
	if(!fout2)
		cout<<"Error in opening the file";
	else
		{
		fout2.write((char*)&x,sizeof(x));
		}
	cout<<"\nThe details have been entered into the register";
	fout2.close();
	}
void cr_register()
	{
	ifstream fin2("CR.dat",ios::binary);
	fin2.seekg(0);
	cash_recharge x;
	cout<<endl;
	cout<<"Cash Replenish Register: ";
	if(!fin2)
		cout<<"Error in opening the file";
	else
		while(!fin2.eof())
		{
		fin2.read((char*)&x,sizeof(x));
		if(fin2.eof())
		break;
		x.display();
		cout<<endl;
		}
	fin2.close();
	}
void problem_management()
	{
	ofstream fout3("Call Service.dat",ios::app|ios::binary);
	fout3.seekp(2);
	call_service x;
	char m;
	char j;
	m:
	x.accept();

	if(x.func()=='y')
	{;}
	else
		{cout<<"\nThe problem is being forwarded";}
	cout<<"\nThe details you have entered are: ";
	x.display();
	cout<<"\nDo you want to change?(y/n): ";
	cin>>j;
	if(j=='y')
	goto m;
	if(!fout3)
		cout<<"\nError in opening the file: ";
	else
		{
		fout3.write((char*)&x,sizeof(x));
		}
	cout<<"\nThe details have been entered into the register";
	fout3.close();
	}
void call_servicef()
	{
	ifstream fin3("Call Service.dat",ios::binary);
	fin3.seekg(0);
	call_service x;
	if(!fin3)
		cout<<"Error in opening the file ";
	else
		while(!fin3.eof())
		{
		fin3.read((char*)&x,sizeof(x));
		if(fin3.eof())
		break;
		x.display();
		cout<<endl;
		}
	fin3.close();
	}

void report1()
	{
	ATM x;
	int ch;
	ifstream fin("ATM.dat",ios::binary);
	fin.seekg(0);
	cout<<"\n1.Diebold \n2.Wincor \n3.Ncr \n4.Hyosung";
	cout<<"\nEnter the type of the machiene: ";
	cin>>ch;
	if(!fin)
		cout<<"Error in opening the file";
	else
	       {	while(!fin.eof())
			{
			fin.read((char *)&x,sizeof(x));
			if(x.make==ch)
			x.display();
			}
	       }
	fin.close();
	}
void report2()
	{
	ifstream fin2("CR.dat",ios::binary);
	fin2.seekg(0);
	cash_recharge x;

	if(!fin2)
		cout<<"Error in opening the file";
	else
		while(!fin2.eof())
		{
		fin2.read((char*)&x,sizeof(x));
		cout<<endl;
		if(fin2.eof())
		break;
		if(x.ispense()>120000)
		x.display();
		}
	fin2.close();
	}

void report()
	{
	int ch;
	cout<<"\n1.Reports on installation of ATM";
	cout<<"\n2.Reports on cash dispense";
	cout<<"\nEnter your choice: ";
	cin>>ch;
	switch(ch)
		{
		case 1:
		report1();
		break;
		case 2:
		report2();
		break;
		default:
		cout<<"Enter from the above options";
		}
	}

void main()
	{int ch,ch1;
	clrscr();
	char rep='y';
	while(rep=='y')
		{
		cout<<" \t \t \tBrinks Arya India Pvt. Ltd.";
		cout<<"\n 1.Installation of ATM \n 2.Cash Replenish \n 3.Problem with the machiene \n 4.Administration \n 5.Reports \n 6.Exit";
		cout<<"\n Enter your choice:  ";
		cin>>ch;
		switch(ch)
			{
			case 1:
			installation();
			break;
			case 2:
			cash_replenish();
			break;
			case 3:
			problem_management();
			break;
			case 4:
				{
				cout<<"\n1.ATM Register \n2.CR Register \n3.Call Service Register";
				cout<<"\nEnter your choice: ";
				cin>>ch1;
				switch(ch1)
					{
					case 1:
					atm_register();
					break;
					case 2:
					cr_register();
					break;
					case 3:
					call_servicef();
					break;
					default:
					cout<<"Enter from the above options";
					break;
					}

				}
				break;
			case 5:
			report();
			break;
			case 6:
			exit(0);
			break;
			default:
			cout<<"Enter from the above options";
			break;
			}
		cout<<endl;
		cout<<"Do you want to continue?(y/n): ";
		cin>>rep;
		}
	getch();
	}