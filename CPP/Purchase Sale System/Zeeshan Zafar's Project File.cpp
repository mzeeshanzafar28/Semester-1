/*write a program to */
#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>
#include<string.h>
#include<iomanip>

struct product							//<<<STRUCT PRODUCT PART>>>
{
	int Pid;
	char Pname[30];
	int Bal;
	int PuId;
	int PurchaseQty;
	int SaleQty;
	int PurchasePrice;
	int SalePrice;
	int SaId;
};

//PRODUCT SECTION FUNCTIONS STARTED

void AddProduct()
{
product p;
int r,flag=0;
cout<<"\nProduct Id : ";
cin>>r;
ifstream ifs("product.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	if (r==p.Pid)
	flag=1;
}
ifs.close();
if (flag==1)
{
	cout<<"\nA Product with Same Product Id already Exists"<<endl<<endl;
}
else
{
	p.Pid=r;
	cout<<"\nProduct Name : ";
	cin.ignore();
	cin.getline(p.Pname,30);
	p.Bal=0;
	p.PuId=0;
	p.PurchaseQty=0;
	p.SaleQty=0;
	p.PurchasePrice=0;
	p.SalePrice=0;
	p.SaId=0;
	
ofstream ofs("product.bin",ios_base::app);
ofs.write(reinterpret_cast<char*>(&p), sizeof(p));
ofs.close();

cout<<"\nData Successfully Stored\n"<<endl;
							}
}

void ModifyProduct()
{
product p;
int r,flag=0;
cout<<"Enter the Product's Id You Wanna Modify : ";
cin>>r;

ifstream ifs("product.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	if (p.Pid==r)
	flag=1;
}
ifs.close();

if (flag==0)
 {
 	cout<<"\nNo Product with Such Product Id exists"<<endl<<endl;
 }


else
	
	{
		ifstream ifs2("product.bin");
		ofstream ofs("temp.bin");

while ( ifs2.read (reinterpret_cast<char*>(&p) , sizeof(p) ) )
		{
			if (p.Pid == r)
			{
				cout<<"\n***Enter new Data***"<<endl;
				cout<<"Product Id : ";
				cin>>p.Pid;
				cout<<"Product Name : ";
				cin>>p.Pname;
				p.Bal=0;
							}
				ofs.write(reinterpret_cast<char*>(&p), sizeof(p));					
		}
		ifs2.close();
		ofs.close();
		ifstream ifs3("temp.bin");
		ofstream ofs2("product.bin");
		while (ifs3.read(reinterpret_cast<char*> (&p), sizeof(p)))
		ofs2.write(reinterpret_cast<char*>(&p) ,sizeof(p));
		ifs3.close();
		ofs2.close();
		
		cout<<"\nData Successfully Modified"<<endl<<endl;
																}
}

void DeleteProduct()
{
product p;
int r,flag=0;
cout<<"Enter the Product's Id You Wanna Delete : ";
cin>>r;

ifstream ifs("product.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	if (p.Pid==r)
	flag=1;
}
ifs.close();

if (flag==0)
 {
 	cout<<"\nNo Product with Such Product Id exists"<<endl<<endl;
 }


else	
	{
		ifstream ifs2("product.bin");
		ofstream ofs("temp.bin");

while ( ifs2.read (reinterpret_cast<char*>(&p) , sizeof(p) ) )
		{
			if (p.Pid != r)
			{	
			ofs.write(reinterpret_cast<char*>(&p), sizeof(p));					
							}
		}
		ifs2.close();
		ofs.close();
		ifstream ifs3("temp.bin");
		ofstream ofs2("product.bin");
		while (ifs3.read(reinterpret_cast<char*> (&p), sizeof(p)))
		ofs2.write(reinterpret_cast<char*>(&p) ,sizeof(p));
		ifs3.close();
		ofs2.close();
		
		cout<<"\nData Successfully Deleted"<<endl<<endl;	

													}
}

void DisplayAllProduct()
{
product p;
ifstream ifs("product.bin");

	cout<<"\n***Product Data***\n"<<endl;
	
	cout.setf(ios::left);
	cout<<setw(20)<<"Product Id";
	cout<<setw(20)<<"Product Name";
	
	cout<<endl;

 while (	ifs.read(reinterpret_cast<char*>(&p),sizeof(p))  )
{
	
	cout.setf(ios::left);
	cout<<setw(20)<<p.Pid;
	cout<<setw(20)<<p.Pname;

	cout<<endl;
	
	
	}
	ifs.close();
}

void SearchProductbyId()
{
product p;
int r,flag=0;
cout<<"\nEnter Product Id to Search : ";
cin>>r;

ifstream ifs("product.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{


if (p.Pid==r)
{
	cout<<"\nData of Product With Product Id "<<r<<" is as :"<<endl<<endl;
	cout<<"Product Name : "<<p.Pname<<endl;
	cout<<"Product Id : "<<p.Pid<<endl;
	flag=1;
		}
			 
				
												}
ifs.close();
if (flag==0)
{
	cout<<"\nNo Product with such Product Id Exists"<<endl<<endl;
}

}

//PRODUCT SECTION FUNCTIONS ENDED



//PURCHASE SECTION FUNCTIONS STARTED
	
void AddPurchase()
{
product p;
int r,flag=0;
cout<<"Product Id : ";
cin>>r;

ofstream ofs("temp.bin");
ifstream ifs("Product.bin");
while (ifs.read(reinterpret_cast<char*>(&p),sizeof(p)))
{
	
	if (p.Pid == r)
		{
			flag=1;
			cout<<"\nPurchase Id : ";
			cin>>p.PuId;
			cout<<"\nPrice : ";
			cin>>p.PurchasePrice;
			cout<<"\nQuantity : ";
			cin>>p.PurchaseQty;
			cout<<"Purchase Successfully Added"<<endl<<endl;
			p.Bal=p.Bal+p.PurchaseQty;
									}
			
			ofs.write(reinterpret_cast<char*>(&p),sizeof(p));
			
							}
													
	ifs.close();
	ofs.close();	
		
	ifstream ifs2("temp.bin");
	ofstream ofs2("product.bin");
	while (ifs2.read(reinterpret_cast<char*>(&p),sizeof(p)))
		{
		ofs2.write(reinterpret_cast<char*>(&p),sizeof(p));
			}
		ifs2.close();
		ofs2.close();
												
		if (flag==0)
		{
			cout<<"\nNo Product with Such Product Id Exists"<<endl<<endl;
		}

	}

void ModifyPurchase()
{
product p;
int r,flag=0;
cout<<"Enter Purchase Id of the Product you Want to Modify : ";
cin>>r;
ifstream ifs("product.bin");
ofstream ofs("temp.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	if (p.PuId==r)
	{
		flag=1;
		cout<<"\nEnter New Purchase Id : ";
		cin>>p.PuId;
		cout<<"\nEnter New Price : ";
		cin>>p.PurchasePrice;
		cout<<"\nEnter New Quantity : ";
		cin>>p.PurchaseQty;
		p.Bal=p.PurchaseQty-p.SaleQty;
		
		cout<<"\nPurchase Successfully Modified"<<endl<<endl;
		
	}
	
	ofs.write(reinterpret_cast<char*>(&p), sizeof(p));
	
	
								}
ifs.close();
ofs.close();

ifstream ifs2("temp.bin");
ofstream ofs2("product.bin");
while (ifs2.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	ofs2.write(reinterpret_cast<char*>(&p), sizeof(p));
}

ifs2.close();
ofs2.close();

if (flag==0)
{
	cout<<"\nNo Product With Such Purchase Id Exists"<<endl<<endl;
}

}

void DeletePurchase()
{

product p;

int r,flag=0;
cout<<"Enter the Product's Purchase Id You Wanna Delete : ";
cin>>r;

ifstream ifs("product.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	if (p.PuId==r)
	flag=1;
}
ifs.close();

if (flag==0)
 {
 	cout<<"\nNo Product with Such Purchase Id exists"<<endl<<endl;
 }
else
		{

			ifstream ifs2("product.bin");
			ofstream ofs("temp.bin");

while ( ifs2.read (reinterpret_cast<char*>(&p) , sizeof(p) ) )
		{
			if (p.PuId != r)
			{	
			ofs.write(reinterpret_cast<char*>(&p), sizeof(p));					
							}
							
				else
				{
					p.PuId=0;
					p.PurchasePrice=0;
					p.PurchaseQty=0;
					ofs.write(reinterpret_cast<char*>(&p), sizeof(p));
							}			
							
							}
		ifs2.close();
		ofs.close();
		ifstream ifs3("temp.bin");
		ofstream ofs2("product.bin");
		while (ifs3.read(reinterpret_cast<char*> (&p), sizeof(p)))
		ofs2.write(reinterpret_cast<char*>(&p) ,sizeof(p));
		ifs3.close();
		ofs2.close();
		
		cout<<"\nPurchase Successfully Deleted"<<endl<<endl;	

													}

}

void DisplayAllPurchase()
{
		product p;
		ifstream ifs("product.bin");
		
			cout<<"\n***PURCHASES DATA***"<<endl;
			
			cout.setf(ios::left);
			cout<<setw(20)<<"PRODUCT ID";
			cout<<setw(20)<<"PRODUCT NAME";
			cout<<setw(20)<<"PURCHASE ID";
			cout<<setw(20)<<"PRICE";
			cout<<setw(20)<<"QUANTITY";
			cout<<endl;
			
				while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
		{
			
				cout.setf(ios::left);
			cout<<setw(20)<<p.Pid;
			cout<<setw(20)<<p.Pname;
			cout<<setw(20)<<p.PuId;
			cout<<setw(20)<<p.PurchasePrice;
			cout<<setw(20)<<p.PurchaseQty;
			cout<<endl;
		}
		ifs.close();
		
	}

void SearchPurchasebyId()
{
product p;
int r,flag=0;
cout<<"\nEnter Product Id to Search : ";
cin>>r;

ifstream ifs("product.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{


if (p.Pid==r)
{
	cout<<"\nData of Product With Product Id "<<r<<" is as :"<<endl<<endl;

			cout<<"Product Id : "<<p.Pid<<endl;
			cout<<"Product Name : "<<p.Pname<<endl;
			cout<<"Purchase Id : "<<p.PuId<<endl;
			cout<<"Price : "<<p.PurchasePrice<<endl;
			cout<<"Quantity : "<<p.PurchaseQty<<endl;
			cout<<endl;

		flag=1;
									}
		 
												}
ifs.close();
if (flag==0)
{
	cout<<"\nNo Product with such Product Id Exists"<<endl<<endl;
		}

							}

//PURCHASE SECTION FUNCTIONS ENDED





//SALES SECTION FUNCTIONS STARTED
	
void AddSale()
{

product p;
int r,flag=0;
cout<<"Product Id : ";
cin>>r;

ofstream ofs("temp.bin");
ifstream ifs("Product.bin");
while (ifs.read(reinterpret_cast<char*>(&p),sizeof(p)))
{
	
	if (p.Pid == r)
		{
			flag=1;
			cout<<"\nSale Id : ";
			cin>>p.SaId;
			cout<<"\nPrice : ";
			cin>>p.SalePrice;
			cout<<"\nQuantity : ";
			cin>>p.SaleQty;
			cout<<"Sale Successfully Added"<<endl<<endl;
			p.Bal=p.Bal-p.SaleQty;
									}
			
			ofs.write(reinterpret_cast<char*>(&p),sizeof(p));
			
							}
													
	ifs.close();
	ofs.close();	
		
	ifstream ifs2("temp.bin");
	ofstream ofs2("product.bin");
	while (ifs2.read(reinterpret_cast<char*>(&p),sizeof(p)))
		{
		ofs2.write(reinterpret_cast<char*>(&p),sizeof(p));
			}
		ifs2.close();
		ofs2.close();
												
		if (flag==0)
		{
			cout<<"\nNo Product with Such Product Id Exists"<<endl<<endl;
		}


	
}

void ModifySale()
{
  
  product p;
int r,flag=0;
cout<<"Enter Sale Id of the Product you Want to Modify : ";
cin>>r;
ifstream ifs("product.bin");
ofstream ofs("temp.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	if (p.SaId==r)
	{
		flag=1;
		cout<<"\nEnter New Sale Id : ";
		cin>>p.SaId;
		cout<<"\nEnter New Price : ";
		cin>>p.SalePrice;
		p.Bal=p.Bal+p.SaleQty;
		cout<<"\nEnter New Quantity : ";
		cin>>p.SaleQty;
		p.Bal=p.Bal-p.SaleQty;
		
		cout<<"\nSale Successfully Modified"<<endl<<endl;
		
	}
	
	ofs.write(reinterpret_cast<char*>(&p), sizeof(p));
	
	
								}
ifs.close();
ofs.close();


ifstream ifs2("temp.bin");
ofstream ofs2("product.bin");
while (ifs2.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	ofs2.write(reinterpret_cast<char*>(&p), sizeof(p));
}
ifs2.close();
ofs2.close();




if (flag==0)
{
	cout<<"\nNo Product With Such Sale Id Exists"<<endl<<endl;
}
  
  
  
  		
}

void DeleteSale()
{

product p;

int r,flag=0;
cout<<"Enter the Product's Sale Id You Wanna Delete : ";
cin>>r;

ifstream ifs("product.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{
	if (p.SaId==r)
	flag=1;
}
ifs.close();

if (flag==0)
 {
 	cout<<"\nNo Product with Such Sale Id exists"<<endl<<endl;
 }


else
	
	{

ifstream ifs2("product.bin");
ofstream ofs("temp.bin");

while ( ifs2.read (reinterpret_cast<char*>(&p) , sizeof(p) ) )
		{
			if (p.SaId != r)
			{	
			ofs.write(reinterpret_cast<char*>(&p), sizeof(p));					
							}
							
				else
				{
					p.SaId=0;
					p.SalePrice=0;
					p.SaleQty=0;
					ofs.write(reinterpret_cast<char*>(&p), sizeof(p));
							}			
							
							
							
		}
		ifs2.close();
		ofs.close();
		ifstream ifs3("temp.bin");
		ofstream ofs2("product.bin");
		while (ifs3.read(reinterpret_cast<char*> (&p), sizeof(p)))
		ofs2.write(reinterpret_cast<char*>(&p) ,sizeof(p));
		ifs3.close();
		ofs2.close();
		
		cout<<"\nSale Successfully Deleted"<<endl<<endl;	

													}


}

void DisplayAllSale()
{

	product p;
		ifstream ifs("product.bin");
		
			cout<<"\n***SALE DATA***"<<endl;
			
			cout.setf(ios::left);
			cout<<setw(20)<<"PRODUCT ID";
			cout<<setw(20)<<"PRODUCT NAME";
			cout<<setw(20)<<"SALE ID";
			cout<<setw(20)<<"PRICE";
			cout<<setw(20)<<"QUANTITY";
			cout<<endl;
			
			
	
		
		while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
		{
			
				cout.setf(ios::left);
			cout<<setw(20)<<p.Pid;
			cout<<setw(20)<<p.Pname;
			cout<<setw(20)<<p.SaId;
			cout<<setw(20)<<p.SalePrice;
			cout<<setw(20)<<p.SaleQty;
			cout<<endl;
		}
		ifs.close();

	
}

void SearchSalebyId()
{

product p;
int r,flag=0;
cout<<"\nEnter Product Id to Search : ";
cin>>r;

ifstream ifs("product.bin");
while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
{


if (p.Pid==r)
{
	cout<<"\nData of Product With Product Id "<<r<<" is as :"<<endl<<endl;

			cout<<"Product Id : "<<p.Pid<<endl;
			cout<<"Product Name : "<<p.Pname<<endl;
			cout<<"Sale Id : "<<p.SaId<<endl;
			cout<<"Price : "<<p.SalePrice<<endl;
			cout<<"Quantity : "<<p.SaleQty<<endl;
			cout<<endl;

		flag=1;
									}
		 
												}
ifs.close();
if (flag==0)
{
	cout<<"\nNo Product with such Product Id Exists"<<endl<<endl;
}


}


//SALES SECTION FUNCTIONS ENDED






//REPORT SECTION FUNCTIONS STARTED

void transactions()
{
	
	DisplayAllPurchase();
	cout<<endl<<endl;
	DisplayAllSale();	
}

void balance()
{
 product p;
 ifstream ifs("product.bin");
 	cout<<"\nTotal Balance"<<endl<<endl;
 	
 	cout.setf(ios::left);
 	cout<<setw(20)<<"Product Id";
 	cout<<setw(20)<<"Product Name";
 	cout<<setw(20)<<"Purchase Id";
 	cout<<setw(20)<<"Sale Id";
 	cout<<setw(20)<<"Balance";
 	cout<<endl;
 	
 while (ifs.read(reinterpret_cast<char*>(&p), sizeof(p)))
 {
 	
 	cout.setf(ios::left);
 	cout<<setw(20)<<p.Pid;
 	cout<<setw(20)<<p.Pname;
 	cout<<setw(20)<<p.PuId;
 	cout<<setw(20)<<p.SaId;
 	cout<<setw(20)<<p.Bal;
 	cout<<endl;
 	
 	
 	
 }
 
 
 
 
 	
}

//REPORT SECTION FUNCTIONS ENDED













void Product()        					//*****PRODUCTS SECTION*****
{
	system("color d");
while (1)
	
		{
			char ch;
			cout<<"\n*Product Section*"<<endl;
			cout<<"1. Add"<<endl;
			cout<<"2. Modify"<<endl;
			cout<<"3. Delete"<<endl;
			cout<<"4. Display"<<endl;
			cout<<"5. Exit"<<endl<<endl;
			cout<<"Enter Your Choice : ";
			ch=getche();
			cout<<endl<<endl;
		
			if (ch=='1')
			AddProduct();
			else if (ch=='2')
			ModifyProduct();
			else if (ch=='3')
			DeleteProduct();
			else if (ch=='4')
			
			
			{
				
				while (1)

		{
			char ch;
			
			cout<<"*Display Product*"<<endl;
			cout<<"1. Display All"<<endl;
			cout<<"2. Search By Id"<<endl;
			cout<<"3. Exit"<<endl<<endl;
			cout<<"Enter Your Choice : ";	
			
			ch=getche();
			cout<<endl<<endl;
			
			if (ch=='1')
			DisplayAllProduct();
			else if (ch=='2')
			SearchProductbyId();
			else if (ch=='3')
			{
				cout<<"Returned to Product Section"<<endl;
				break;
			}
			else
			cout<<"Invalid Selection"<<endl<<endl;
				
				system("pause");
				system("cls");
					
				}
				
			}
			
			
			
			else if (ch=='5')
				{
				cout<<"Returned to Main Menu"<<endl<<endl;
				break;
					}
				else
				cout<<"Invalid Selection"<<endl<<endl;
		
		
	system("pause");
	system("cls");
		
		
}	
}
void Purchases()						//*****PURCHAES SECTION*****
{
	system("color a");
while (1)
	
		{
			char ch;
			cout<<"\n*Purchase Section*"<<endl;
			cout<<"1. Add"<<endl;
			cout<<"2. Modify"<<endl;
			cout<<"3. Delete"<<endl;
			cout<<"4. Display"<<endl;
			cout<<"5. Exit"<<endl<<endl;
			cout<<"Enter Your Choice : ";
			ch=getche();
			cout<<endl<<endl;
		
			if (ch=='1')
			AddPurchase();
			else if (ch=='2')
			ModifyPurchase();
			else if (ch=='3')
			DeletePurchase();
			else if (ch=='4')
			{
				
				while (1)

		{
			char ch;
			
			cout<<"*Display Purchase*"<<endl;
			cout<<"1. Display All"<<endl;
			cout<<"2. Search By Id"<<endl;
			cout<<"3. Exit"<<endl<<endl;
			cout<<"Enter Your Choice : ";	
			
			ch=getche();
			cout<<endl<<endl;
			
			if (ch=='1')
			DisplayAllPurchase();
			else if (ch=='2')
			SearchPurchasebyId();
			else if (ch=='3')
			{
				cout<<"Returned to Purchase Section"<<endl;
				break;
			}
			else
			cout<<"Invalid Selection"<<endl<<endl;
				
				system("pause");
				system("cls");
					
				}
				
				
			}
			else if (ch=='5')
				{
				cout<<"Returned to Main Menu"<<endl<<endl;
				break;
					}
				else
				cout<<"Invalid Selection"<<endl<<endl;
		
		
	system("pause");
	system("cls");
		
		
				}		
}
void Sales()							//*****SALES SECTION*****
{
	system("color c");
	while (1)
	
		{
			char ch;
			cout<<"\n*Sale Section*"<<endl;
			cout<<"1. Add"<<endl;
			cout<<"2. Modify"<<endl;
			cout<<"3. Delete"<<endl;
			cout<<"4. Display"<<endl;
			cout<<"5. Exit"<<endl<<endl;
			cout<<"Enter Your Choice : ";
			ch=getche();
			cout<<endl<<endl;
		
			if (ch=='1')
			AddSale();
			else if (ch=='2')
			ModifySale();
			else if (ch=='3')
			DeleteSale();
			else if (ch=='4')
			{
				
				
				while (1)

		{
			char ch;
			
			cout<<"*Display Sale*"<<endl;
			cout<<"1. Display All"<<endl;
			cout<<"2. Search By Id"<<endl;
			cout<<"3. Exit"<<endl<<endl;
			cout<<"Enter Your Choice : ";	
			
			ch=getche();
			cout<<endl<<endl;
			
			if (ch=='1')
			DisplayAllSale();
			else if (ch=='2')
			SearchSalebyId();
			else if (ch=='3')
			{
				cout<<"Returned to Sale Section"<<endl;
				break;
			}
			
			else
			cout<<"Invalid Selection"<<endl<<endl;
				
				system("pause");
				system("cls");
					
				}
				
				
			}
			else if (ch=='5')
				{
				cout<<"Returned to Main Menu"<<endl<<endl;
				break;
					}
				else
				cout<<"Invalid Selection"<<endl<<endl;
		
		
	system("pause");
	system("cls");
		
		
				}	
}
void Report()							//*****REPORT SECTION*****
{
	system("color 3");
while (1)
	{
		char ch;
		cout<<"*Report Section*"<<endl;
		cout<<"1. Transactions"<<endl;
		cout<<"2. Balance"<<endl;
		cout<<"3. Exit"<<endl<<endl;
		cout<<"Enter Your Choice : ";
		ch = getche();
		cout<<endl<<endl;
		
		if (ch=='1')
		transactions();
		else if (ch=='2')
		balance();
		else if (ch=='3')
		{
			cout<<"Returned to Main Menu"<<endl;
			break;
		}
		else 
		cout<<"Invalid Selection"<<endl;
		
		
			
	system("pause");
	system("cls");
		
		
	}		
}






int main()

{	

									//*****main starting bracket*****

	
	
	
	while (1)
	
		{
			char ch;
			cout<<"===================="<<endl;
			cout<<"PURCHASE SALE SYSTEM"<<endl;
			cout<<"===================="<<endl;
			cout<<endl;
			cout<<"1. Product"<<endl;
			cout<<"2. Purchases"<<endl;
			cout<<"3. Sales"<<endl;
			cout<<"4. Report"<<endl;
			cout<<"5. Exit"<<endl<<endl;
			cout<<"Enter Your Choice : ";
			ch=getche();
			cout<<endl<<endl;
		
			if (ch=='1')
			Product();
			else if (ch=='2')
			Purchases();
			else if (ch=='3')
			Sales();
			else if (ch=='4')
			Report();
			else if (ch=='5')
				{
					system("color a");
				cout<<"\n***GoodBye***"<<endl<<endl;
				
				cout<<"========================="<<endl;
				cout<<"creator : M ZEESHAN ZAFAR"<<endl;
				cout<<"========================="<<endl;
				break;
				
					}
				else
				cout<<"Invalid Selection"<<endl<<endl;
		
		
	system("pause");
	system("cls");
		
		
											}							



	getch();
	return 0;
}					//*****main closing bracket*****

