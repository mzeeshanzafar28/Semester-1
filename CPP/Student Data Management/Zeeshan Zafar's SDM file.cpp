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
};


void AddData()
{
	
	int r,flag=0;
	student s;
	cout<<"\nRollno : ";
	cin>>r;
	ifstream ifs("student.bin");
	while (ifs.read(reinterpret_cast<char*>(&s), sizeof(s)) )
	{
		if (r==s.rollno)
		flag=1;
	}
	ifs.close();
	if (flag==1)
	cout<<"\n***Data of Student with Same Rollno Already Exists***\n"<<endl;
	else
	{
	s.rollno = r;
	cout<<"\nName : ";
	cin.ignore();
	cin.getline(s.name,30);
	cout<<"\nMarks : ";
	cin>>s.marks;
	
	ofstream ofs("student.bin",ios_base::app);
	ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
	ofs.close();
	
	cout<<"\n***Data successfully Stored***\n"<<endl<<endl;
	system("color 1");
	}
}
void DisplayData()
{
	system("color 2");
	student s;
	ifstream ifs("student.bin",ios::in);
	{
		cout<<"\n"<<endl;
		cout.setf(ios::left);
		cout<<setw(20)<<"Roll#";
		cout<<setw(20)<<"Name";
		cout<<setw(20)<<"Marks";
		cout<<endl<<endl;
	}
	while (ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
	{
		
		cout.setf(ios::left);
		cout<<setw(20)<<s.rollno;
		cout<<setw(20)<<s.name;
		cout<<setw(20)<<s.marks;
		cout<<endl;
			}
			cout<<endl;
}
void ModifyData()
{
		int r;
		int flag=0;
		cout<<"Enter the Rollno whose Data You want to change : ";
		cin>>r;
		ifstream ifs("student.bin");
		ofstream ofs("temp.bin");
		student s;
		while (ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
		{
			if (s.rollno == r)
				{
				cout<<"\n***Enter New Data***"<<endl<<endl;
				cout<<"\nRollno : ";
				cin>>s.rollno;
				cout<<"\nName : ";
				cin.ignore();
				cin.getline(s.name,30);
				cout<<"\nMarks : ";
				cin>>s.marks;
				cout<<endl<<endl;
				flag++;
								}
				ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
			
										}
			
			ifs.close();
			ofs.close();
			
			ifstream ifs2("temp.bin");
			ofstream ofs2("student.bin");
			while (ifs2.read(reinterpret_cast<char*>(&s),sizeof(s)))
			{
			ofs2.write(reinterpret_cast<char*>(&s),sizeof(s));
				}
			ofs2.close();
			ifs2.close();
			
			
			if (flag==0)
			{
			cout<<"\n***No Such Roll No Exists***\n"<<endl<<endl;
			}
			else
			{
			cout<<"\n***Data successfully Modified***\n"<<endl<<endl;
			}
			system("color 4");
		}			
void DeleteData()
{
	student s;
	int r;
	int flag=0;
	cout<<"\nEnter the rollno whose Data you want to delete : ";
	cin>>r;
	
	ofstream ofs("temp.bin");
	ifstream ifs("student.bin");
	
	while (ifs.read(reinterpret_cast<char*>(&s),sizeof(s)))
	{
		
		if (s.rollno != r)
		{
			ofs.write(reinterpret_cast<char*>(&s),sizeof(s));
			
		}
		else 
		{
		cout<<"\n***Record Successfully Deleted***\n"<<endl;
		flag=1;
		}
	}
	ifs.close();
	ofs.close();
	
	ofstream ofs2("student.bin");
	ifstream ifs2("temp.bin");
	
	while (ifs2.read(reinterpret_cast<char*>(&s),sizeof(s)))
	{
		ofs2.write(reinterpret_cast<char*>(&s),sizeof(s));
			}		

	ofs2.close();
	ifs2.close();
	
	if (flag==0)
	cout<<"\n***No such Roll no Exists***\n"<<endl;
	
	system("color 6");


}
void DisplayHighest()
{
	ifstream ifs ("student.bin");
	student s;
	int count = 0;
	while (ifs.read (reinterpret_cast<char*> (&s), sizeof(s)))
	{
		count++;
	}
	ifs.close();
	student s2[count];
	ifstream ifs2 ("student.bin");
	int i = 0;
	while (ifs2.read (reinterpret_cast<char*> (&s), sizeof(s)))
	{
		s2[i] = s;
		i++;
	}
	ifs2.close();
	int large = s2[0].marks;
	int loc = 0;
	for (i=1; i<count; i++)
	{
		if (s2[i].marks > large)	
		{
			large = s2[i].marks;
			loc = i;
		}
	}	
	cout << "***Student with the highest marks***" << endl << endl;
	cout << "Rollno : " << s2[loc]. rollno << endl;
	cout << "Name : " << s2[loc].name << endl;
	cout << "Marks : " << s2[loc].marks << endl <<endl;	
	
	system("color 20");	
}
void SearchByName()
{
	int flag=0;
	char ch[30];
	cout<<"Enter The Name You want to Search : ";
	cin.getline(ch,30);
	student s;
	ifstream ifs("student.bin");
	while( ifs.read(reinterpret_cast<char*>(&s), sizeof(s)) )
	{
		if ( strcmpi(ch , s.name ) == 0 )
		{
			cout<<"\n***Student Data***\n"<<endl;
			cout<<"Rollno : "<<s.rollno<<endl;
			cout<<"Name : "<<s.name<<endl;
			cout<<"Marks : "<<s.marks<<endl;
			cout<<endl;
			flag=1;
		}
		
	}
	ifs.close();
	
	
		if  (flag==0)
		cout<<"\n***No Such Name Exists in Record***\n"<<endl;
		
		
		system("color 3");
	
}
void SearchByRollno()
{
	int flag=0;
	int r;
	cout<<"Enter The Rollno You want to Search : ";
	cin>>r;
	student s;
	ifstream ifs("student.bin");
	while( ifs.read(reinterpret_cast<char*>(&s), sizeof(s)) )
	{
		if (r == s.rollno)
		{
			cout<<"\n***Student Data***\n"<<endl;
			cout<<"Rollno : "<<s.rollno<<endl;
			cout<<"Name : "<<s.name<<endl;
			cout<<"Marks : "<<s.marks<<endl;
			cout<<endl;
			flag=1;
		}
		
	}
	ifs.close();
	
	
		if  (flag==0)
		cout<<"\n***No Such Rollno Exists in Record***\n"<<endl;
		
		system("color 4");
	
}

int main()
{
	char ch;	
	while (1)
	{
		system("color d");
		cout<<"***STUDENT DATA MENU***\n"<<endl;
		cout <<"1. Add Student data" << endl;
		cout <<"2. Display all Students data" << endl;
		cout <<"3. Modify Student data" << endl;
		cout <<"4. Delete Student data" << endl;
		cout <<"5. Search By Name" << endl;
		cout <<"6. Search By Roll No" << endl;
		cout <<"7. Display student with highest marks" <<endl;
		cout <<"8. Exit" << endl<<endl;
		cout<<"Enter Your Choice : ";
		ch = getche();
		cout << endl;
		if (ch =='1')
		  AddData();
		else if (ch =='2')
			DisplayData();		  
		else if (ch =='3')
			ModifyData();
		else if (ch =='4')
			DeleteData();
		else if (ch =='5')
			SearchByName();	
		else if (ch =='6')
			SearchByRollno();
		else if (ch =='7')
			DisplayHighest();
		else if (ch =='8')
		{
			system("color 2");
		
		cout<<"\n***GoodBye***"<<endl;
		
		 cout<<"========================"<<endl;
		 cout<<"credit : M Zeeshan Zafar"<<endl;
		 cout<<"========================"<<endl; 
		
		break;
		}
		else 
			cout << "\nInvalid option"<<endl
			 << endl;	
			 
			 
			 system ("pause");
			 system("cls");	
			 	
	}






getch();
return 0;
}

