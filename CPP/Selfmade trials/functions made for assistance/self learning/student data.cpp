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
	char gender[8];
	int marks;

void AddData()
{
	cout<<"Rollno : ";
	cin>>rollno;
	cout<<endl<<"Name : ";
	cin>>name;
	cout<<endl<<"Gender : ";
	cin>>gender;
	cout<<endl<<"Marks : ";
	cin>>marks;
	cout<<endl<<"Data successfully stored"<<endl;
}

void Heading()
{
	cout.setf(ios::left);
	cout<<setw(20)<<"Rollno";
	cout<<setw(20)<<"Name";
	cout<<setw(20)<<"Gender";
	cout<<setw(20)<<"Marks";
	cout<<endl;
}

void ListData()
{
		cout.setf(ios::left);
	cout<<setw(20)<<rollno;
	cout<<setw(20)<<name;
	cout<<setw(20)<<gender;
	cout<<setw(20)<<marks;
	cout<<endl;
}


};








int main()
{
int n;
cout<<"Enter how many stdent's data you want to store : ";
cin>>n;
student s[n];
int i;
for (i=0; i<n; i++)
{
	s[i].AddData();
}

ofstream ofs("student.txt");
for (i=0; i<n; i++)
{
	ofs<<s[i].rollno<<endl<<s[i].name<<endl<<s[i].gender<<endl<<s[i].marks<<endl;
	ofs<<"**********"<<endl;
}
ofs.close();
cout<<"Data successfully stored in file"<<endl;


ifstream ifs("student.txt");
char ch[300];
while (1)
{
	ifs.getline(ch,300);
	if (ifs.eof()) break;
	cout<<ch<<endl;
}
ifs.close();





getch();
return 0;
}

