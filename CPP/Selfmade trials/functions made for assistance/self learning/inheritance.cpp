/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>

struct student
{
	int rollno;
	char name[30];
	int marks;
	
	void AddData()
	{
		cout<<"****STUDENT DATA***\n"<<endl;
		cout<<"rollno : ";
		cin>>rollno;
		cout<<"\nname : ";
		cin>>name;
		cout<<"\nmarks : ";
		cin>>marks;
	}
	
};

struct boy : student
{
	int age;
	int height;
	char cast[20];

void GetData()
{
	cout<<"***BOY DATA***\n"<<endl;
	cout<<"age : ";
	cin>>age;
	cout<<"\nheight : ";
	cin>>height;
	cout<<"\ncast  :";
	cin>>cast;
}

};


int main()
{


student s;
boy b;
s.AddData();
b.GetData();
cout<<"Inheritance takes place"<<endl;
b.AddData();




getch();
return 0;
}

