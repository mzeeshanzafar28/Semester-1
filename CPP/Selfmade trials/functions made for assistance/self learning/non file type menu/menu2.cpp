/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<string.h>
struct student
{
	int rollno;
	char name[30];
	int marks;

void AddData()
{
	cout<<"Rollno : ";
	cin>>rollno;
	cout<<"\nName : ";
	cin>>name;
	cout<<"\nMarks : ";
	cin>>marks;
	cout<<endl;
	
}
void Heading()
{
	cout.setf(ios::left);
	cout<<setw(20)<<"ROLL#";
	cout<<setw(20)<<"NAME";
	cout<<setw(20)<<"MARKS";
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
	int N;
	cout<<"Enter how many student's data you want to process : ";
	cin>>N;
int i,n;
char ch;
student s[N];
 while (1)
 {
 	cout<<"0. EXIT"<<endl;
 	cout<<"1. ADD STUDENT DATA"<<endl;
 	cout<<"2. DISPLAY ALL STUDENT DATA"<<endl;
 	cout<<"3. SEARCH BY ROLL NO"<<endl;
 	cout<<"4. SEARCH BY NAME"<<endl;
 	cout<<"5. MODIFY RECORD"<<endl;
 	cout<<"6. DELETE RECORD"<<endl;
 	cout<<"Enter Your Choice : ";
 	ch = getche();
 	cout<<endl<<endl;
 	
 	
 	if (ch=='0')
 	{break;}
 	
 	
 	else if(ch=='1')
 	{for (i=0; i<N; i++)
 	{
	 cout<<"***ENTER DATA FOR STUDENT "<<i+1<<" ***"<<endl;
	 s[i].AddData();
	 }cout<<"\nData successfully Stored"<<endl;}
	 
	 
 	else if (ch=='2')
 	{
	 s[0].Heading();
	 for (i=0; i<N; i++)
 	s[i].ListData();
	 cout<<endl<<endl;
	 }
 	
 	
 	else if (ch=='3')
 	{
	 int r;
	 cout<<"Enter Rollno to Search : ";
	 cin>>r;
	 cout<<endl;
	 s[0].Heading();
	 for (i=0; i<N; i++)
		if (r==s[i].rollno)
		s[i].ListData();
		cout<<endl<<endl;
	 }
	 
	 
 	else if (ch=='4')
 	{
 	 char name[30];
 	 cout<<"Enter name to search : ";
 	 cin>>name;
 	 cout<<endl;
 	 s[0].Heading();
	 for (i=0; i<N; i++)
	 if (strcmpi(name,s[i].name) == 0)
	 s[i].ListData();
	 cout<<endl<<endl; 
	 }
	 
	 
 	else if (ch=='5')
 	{
	 int r;
 	cout<<"Enter rollno whose record is to be modified : ";
 	cin>>r;
	 for (i=0; i<N; i++)
	 if (r==s[i].rollno)
	 s[i].AddData();
	 cout<<"\nRecord Successfully Modified"<<endl; 
	 }
	 
	 
	 
	 
	 
 	else if (ch=='6')
 	{
 		int r,loc;
 	cout<<"Enter rollno whose record you want to delete : ";
    	cin>>r;
    	for (i=0; i<N; i++)
    	if (r == s[i].rollno)
    	{
    		cout<<"Following record is be deleted"<<endl;
    		s[0].Heading();
    		s[i].ListData();
    		loc = i;
		}
    	for (i=loc; i<N-1; i++)
    	{
    		s[i] = s[i+1];
    		
		}
    	N--;
	 }
	 
	 
 	else
 	{cout<<"\nInvalid Choice"<<endl;}
 	
 	
 	
 	
 	
 	
 }



getch();
return 0;
}

