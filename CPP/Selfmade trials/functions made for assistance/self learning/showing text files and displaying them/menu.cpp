/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>




void ListFiles()
{
	system("cls");
	system("dir *.txt/w");
	
}
void ReadFile()
{
	char filename[30];
	cout<<"Enter The filename with extension you want to read : ";
	cin.ignore();
	cin.getline(filename,30);
	ifstream ifs(filename);
	char ch[1000];
	while (1)
	{
		ifs.getline(ch,1000);
		if(ifs.eof()) break;
		cout<<ch<<endl;
	}
	ifs.close();
}




int main()
{

	while (1)
	{

	int n;
	cout<<"0. EXIT\n";
	cout<<"1. List All Text Files\n";
	cout<<"2. Read a specific File\n";
	cout<<"Enter your choice : ";
	cin>>n;
	switch(n)
	{
		case 1: ListFiles();    break;
		case 2: ReadFile();     break;	
			}
		
		if (n==0)
		{
		cout<<"\n***Program Exitted****"<<endl;
		break;
		}
	}





getch();
return 0;
}

