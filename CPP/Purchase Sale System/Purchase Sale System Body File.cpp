#include<iostream>
using namespace std;
#include<conio.h>
#include<fstream>

struct product							//<<<STRUCT PRODUCT PART>>>
{
	int Pid;
	char Pname[30];
	int Bal;
	int PuId;
	int Qty;
	int Price;
	int SaId;
};




//PRODUCT SECTION FUNCTIONS STARTED

void AddProduct()
{
cout<<"addProduct function called"<<endl;	
}

void ModifyProduct()
{
cout<<"modifyProduct function called"<<endl;		
}

void DeleteProduct()
{
cout<<"deleteProduct function called"<<endl;	
}

void DisplayAllProduct()
{
cout<<"displayAllProduct function called"<<endl;	
}

void SearchProductbyId()
{
cout<<"SearchProductbyId function called"<<endl;
}

//PRODUCT SECTION FUNCTIONS ENDED





//PURCHASE SECTION FUNCTIONS STARTED
	
void AddPurchase()
{
cout<<"addPurchase function called"<<endl;	
}

void ModifyPurchase()
{
cout<<"modifyPurchase function called"<<endl;		
}

void DeletePurchase()
{
cout<<"deletePurchase function called"<<endl;	
}

void DisplayAllPurchase()
{
cout<<"displayAllpurchase function called"<<endl;	
}

void SearchPurchasebyId()
{
cout<<"SearchPurchasebyId function called"<<endl;
}

//PURCHASE SECTION FUNCTIONS ENDED





//SALES SECTION FUNCTIONS STARTED
	
void AddSale()
{
cout<<"addSale function called"<<endl;	
}

void ModifySale()
{
cout<<"modifySale function called"<<endl;		
}

void DeleteSale()
{
cout<<"deleteSale function called"<<endl;	
}

void DisplayAllSale()
{
cout<<"displayAllSale function called"<<endl;	
}

void SearchSalebyId()
{
cout<<"SearchSalebyId function called"<<endl;
}


//SALES SECTION FUNCTIONS ENDED






//REPORT SECTION FUNCTIONS STARTED

void transactions()
{
	cout<<"transactions function called"<<endl;	
}

void balance()
{
	cout<<"balance function called"<<endl;	
}

//REPORT SECTION FUNCTIONS ENDED













void Product()        					//*****PRODUCTS SECTION*****
{
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

	system("color a");
	
	
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

