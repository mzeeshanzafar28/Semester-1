/*write a program to input and display data of N students 
  in tabular form...  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<iomanip>

struct student
{
	int rollno;
	char name[30];
	char gender[6];
	int Class;
	int marks;
	
	void AddData()
	{	
		cout<<"Rollno : ";
		cin>>rollno;
		cout<<endl<<"Name : ";
		cin>>name;
		cout<<endl<<"Gender : ";
		cin>>gender;
		cout<<endl<<"Class : ";
		cin>>Class;
		cout<<endl<<"Marks : ";
		cin>>marks;
		
		cout<<"\nData successfully stored"<<endl;
		
		
	}
	void Heading()
	{
				cout.setf(ios::left);
				cout<<setw(20)<<"ROLL No";
				cout<<setw(20)<<"NAME";
				cout<<setw(20)<<"GENDER";
				cout<<setw(20)<<"CLASS";
				cout<<setw(20)<<"MARKS";
				cout<<endl;		
	}
	void ListData()
	{
				cout.setf(ios::left);
				cout<<setw(20)<<rollno;
				cout<<setw(20)<<name;
				cout<<setw(20)<<gender;
				cout<<setw(20)<<Class;
				cout<<setw(20)<<marks;
				cout<<endl;	
	}
	
};


int main()
{
	int n;
	cout<<"Enter how many students Data you want to Add and Display : ";
	cin>>n;
student s[n];
int i;
for (i=0; i<n; i++)
{
	cout<<"*** Enter Data for student Number "<<i+1<<" ***"<<endl;
	s[i].AddData();
}
s[0].Heading();
for (i=0; i<n; i++)
s[i].ListData();


getch();
return 0;
}

