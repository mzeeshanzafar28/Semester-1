/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
	void ReadText(char f[])
	{
		
		ifstream ifs;
		ifs.open(f);
		char ch;
		while (!ifs.eof())
		{
			ch=ifs.get();
			cout<<ch;
		}
		ifs.close();
							}

int main()
{
	char Filename[30];
	cout<<"Enter the Binary fiename with extension you want to read : ";
	cin.getline(Filename,30);
	ReadText(Filename);
		
getch();
return 0;
}

