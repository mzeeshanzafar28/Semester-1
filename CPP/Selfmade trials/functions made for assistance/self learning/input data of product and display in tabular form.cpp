/*write a program to  */

#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<iomanip>
struct product
{
	int pid;
	char name[30];
	int price;
	int qty;

void AddProduct()
{
	cout<<"Enter Pid : ";
	cin>>pid;
	cout<<endl<<"Enter Product Name : ";
	cin>>name;
	cout<<endl<<"Enter Price : ";
	cin>>price;
	cout<<endl<<"Enter Quantity : ";
	cin>>qty;
	cout<<endl;
	cout<<"Data successfully added"<<endl;
}
void Heading()
{
	cout.setf(ios::left);
	cout<<setw(20)<<"Pid";
	cout<<setw(20)<<"Name";
	cout<<setw(20)<<"Price";
	cout<<setw(20)<<"Quantity";	
	cout<<endl;
}
void ListData()
{
	cout.setf(ios::left);
	cout<<setw(20)<<pid;
	cout<<setw(20)<<name;
	cout<<setw(20)<<price;
	cout<<setw(20)<<qty;	
	cout<<endl;
}
	
};


int main()
{
int n;
cout<<"Enter How many product details you want to input and display : ";
cin>>n;
product p[n];
int i;
for (i=0; i<n; i++)
{
	cout<<"*** ENTER DETAILS FOR PRODUCT NUMBER "<<i+1<<" ***"<<endl;
	p[i].AddProduct();	
}
	p[0].Heading();
	for (i=0; i<n; i++)
	p[i].ListData();


getch();
return 0;
}

