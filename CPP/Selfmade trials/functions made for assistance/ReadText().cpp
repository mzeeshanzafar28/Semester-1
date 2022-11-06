/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
void ReadText(char f[])
{
	ifstream ifs;
	ifs.open(f,ios::in);
	char ch;
	while (!ifs.eof())
	{
		ch = ifs.get();
		cout<<ch;
	}
	ifs.close();
}
int main()

{
char filename[30];
cout<<"Enter the filename with extension you want to read : ";
cin>>filename;
ReadText(filename);



getch();
return 0;
}

