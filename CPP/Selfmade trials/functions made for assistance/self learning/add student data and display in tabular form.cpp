/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<iomanip>

struct student
{
	int rollno;
	char name[30];
	int marks;
	
	void AddData()
	{
		cout<<"rollno : ";
		cin>>rollno;
		cout<<endl<<"Name : ";
		cin>>name;
		cout<<endl<<"Marks : ";
		cin>>marks;
		cout<<endl;
	}
	void Headding()
	{
		cout.setf(ios::left);
		cout<<setw(20)<<"ROllno";
		cout<<setw(20)<<"Name";
		cout<<setw(20)<<"Marks";
		cout<<endl;
		}	
	void ListData()
	{
		cout.setf(ios::left);
		cout<<setw(20)<<rollno;
		cout<<setw(20)<<name;
		cout<<setw(20)<<marks;
		cout<<endl;
	}
	
};


int main()
{
int i,n;
cout<<"Enter how many student's data you want to input and display : ";
cin>>n;
student s[n];
for (i=0; i<n; i++)
{
	cout<<"***ENTER DATA FOR STUDENT "<<i+1<<" ***"<<endl;
	s[i].AddData();
}
cout<<"***YOUR ENTERED DATA IS AS GIVEN BELOW***"<<endl;
s[0].Headding();
for (i=0; i<n; i++)
s[i].ListData();

getch();
return 0;
}

