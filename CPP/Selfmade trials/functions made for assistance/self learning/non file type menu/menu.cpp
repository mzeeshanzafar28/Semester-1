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
	cout<<endl<<endl;
	}	
void Heading()
{
	cout.setf(ios::left);
	cout<<setw(20)<<"ROLL NO";
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
	int i,n,rn,loc=0,flag=0;
	char nm[30];
	cout<<"Enter how many students Data you want to input : ";
	cin>>n;
	student s[n];
char ch;
while (1)
{
	cout<<"1. ADD STUDENT DATA"<<endl;
	cout<<"2. DISPLAY ALL STUDENT DATA"<<endl;
	cout<<"3. SEARCH BY ROLL NO"<<endl;
	cout<<"4. SEARCH BY NAME"<<endl;
	cout<<"5. MODIFY RECORD"<<endl;
	cout<<"6. DELETE RECORD"<<endl;
	cout<<"8. EXIT"<<endl;
	ch = getche();
	cout<<endl<<endl;
	
	if (ch == '1')
	{
	for (i=0; i<n; i++)
	{
	cout<<"*** ENTER DATA FOR STUDENT "<<i+1<<" ***"<<endl;	
	s[i].AddData();
	}
		}
	else if (ch == '2')
	{
	s[0].Heading();
	for (i=0; i<n; i++)
	s[i].ListData();
	cout<<endl<<endl;
     }
     else if (ch=='3')
     {
     	cout<<"Enter rollno to display data : ";
     	cin>>rn;
     	for (i=0; i<n; i++)
     	if ( rn == s[i].rollno)
     	{	
     	s[0].Heading();
     	s[i].ListData();
     	flag++;
    	    }
    	   
    }  
    else if(ch == '4')
{
    	
    cout<<"Enter Name You want to search : ";
    cin>>nm;
    for (i=0; i<n; i++)
    if ( strcmpi(nm,s[i].name) == 0 )
    {
    	s[i].Heading();
    	s[i].ListData();
	}
			}    
    else if (ch == '5')
    {
    	cout<<"Enter rollno whose record is to be modified : ";
    	cin>>rn;
    	for (i=0; i<n; i++)
    	if (rn == s[i].rollno)
    	{
    		cout<<"***ENTER NEW DATA***"<<endl<<endl;
    		s[i].AddData();
    		cout<<"Data successfully modified"<<endl<<endl;
		} 	
	}
    else if (ch=='6')
    {
    	cout<<"Enter rollno whose record you want to delete : ";
    	cin>>rn;
    	for (i=0; i<n; i++)
    	if (rn == s[i].rollno)
    	{
    		cout<<"Following record is be deleted"<<endl;
    		s[0].Heading();
    		s[i].ListData();
    		loc = i;
		}
    	for (i=loc; i<n-1; i++)
    	{
    		s[i] = s[i+1];
    		
		}
    	n--;
	}
    
    
    	else if (ch =='8')
{
	cout<<"Program Exitted"<<endl;
	break;
}
	else
	cout<<"Invalid Selection"<<endl;
}



getch();
return 0;
}

