/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>

	void ReadText(char f[])
	{
	
	ifstream ifs(f);
	char ch[5000];
	while (1)
	{
		ifs.getline(ch,5000);
		if (ifs.eof()) break;
		cout<<ch<<endl;
					}
		ifs.close();
									}

int main()

{
	char Filename[30];
	cout<<"Enter the Text Filename with Extension You want to read : ";
	cin.getline(Filename,30);
	ReadText(Filename);

getch();
return 0;
}

