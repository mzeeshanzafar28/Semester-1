/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
void WriteText(char f[],char j[])
{
	ofstream ofs;
	ofs.open(f,ios_base::app|ios::out);
	ofs<<j;
	ofs.close();
}
int main()
{
char filename[30];
char text[1000];
cout<<"Enter the filename with extension on which you want to write : ";
cin>>filename;
cout<<"\nEnter the text you want to write on file : ";
cin.ignore();
cin.getline(text,1000);
WriteText(filename,text);
cout<<"\n Data Successfully Written on file "<<filename<<endl;



getch();
return 0;
}

