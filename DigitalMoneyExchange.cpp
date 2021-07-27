#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

void display();

struct Node{
	
	string Name;
	string Email;
	string PhoneNumber;
	string Cnic;
	string AccountNumber;
	int Amount;
	Node *left, *right;
};
struct list{
	
	Node *root;
	Node *prev, *curr;
	int n,num;
	string aNumber;
	
	list()
	{
		root = NULL;
	}	
/////////////////////////////////////////////////////////////// createAccount()
void createAccount()
	{
		string name, email, phoneNumber, cnic, accountNumber;
		int amount;
		cout<<endl<<"\t\t\t:::>> Enter Client Information <<:::"<<endl<<endl;
		cout<<"\t\t\tEnter Name : ";
		cin.ignore();
		getline(cin,name);
		cout<<"\t\t\tEnter Email : ";
		cin>>email;
		cout<<"\t\t\tEnter Phone Number : ";
		cin>>phoneNumber;
		cout<<"\t\t\tEnter CNIC Number : ";
		cin>>cnic;
		cout<<"\t\t\tEnter Account Number : ";
		cin>>accountNumber;
		cout<<"\t\t\tEnter Ammount : ";
		cin>>amount;
		
		
		Node *newNode = new Node;
		newNode->AccountNumber = accountNumber;
		newNode->Cnic = cnic;
		newNode->Email = email;
		newNode->Name = name;
		newNode->PhoneNumber = phoneNumber;
		newNode->Amount = amount;
		newNode->left = NULL;
		newNode->right = NULL;
		int n;
		
		if(!root)
		{
			root = newNode;
			system("cls");
			cout<<endl<<"\t\t\t>-------ACCOUNT-INFORMATION-------<";
			cout<<endl<<endl;
			cout<<"\t\t\tAccount Number : "<<accountNumber<<endl;
			cout<<"\t\t\tName :           "<<name<<endl;
			cout<<"\t\t\tPhone Number :   "<<phoneNumber<<endl;
			cout<<"\t\t\tCNIC Number :    "<<cnic<<endl;
			cout<<"\t\t\tEmail :          "<<email<<endl;
			cout<<"\t\t\tAmount :         "<<amount<<endl;
			cout<<endl;
			cout<<"\t\t\tAccount created Successfully."<<endl<<endl;
			cout<<"\t\tThankyou For Using PKR Digital Money Exchange Service..."<<endl;
			cout<<endl;

		}
		else
		{
			curr = root;
			while(curr)
			{
				prev = curr;
				if(curr->AccountNumber<accountNumber)
				{
					curr = curr->right;
				}		
				else if(curr->AccountNumber>accountNumber)
				{
					curr = curr->left;
				}
				else
				{
					cout<<"Account Number can't be duplicate!!! "<<endl;
					delete newNode;
					cout<<"\t\t\t1. Main Menu			2. Exit"<<endl;
					cout<<"\t\t\t";
					cin>>n;
					if(n == 1)
					{
						system("cls");
						second();
					}						
				}
			}
			if(prev->AccountNumber>accountNumber)
			prev->left=newNode;
			else
			prev->right=newNode;
			
		}
	}
/////////////////////////////////////////////////////////////////// DisplayAccounts()	
void displayAccounts(Node *nodePtr)
{	
		if(nodePtr != NULL)
		{
			displayAccounts(nodePtr->left);
			cout<<endl;
			cout<<"\t\t\tAccount Number : "<<nodePtr->AccountNumber<<endl;
			cout<<"\t\t\tName :           "<<nodePtr->Name<<endl;
			cout<<"\t\t\tEmail :          "<<nodePtr->Email<<endl;
			cout<<"\t\t\tPhone Number :   "<<nodePtr->PhoneNumber<<endl;
			cout<<"\t\t\tCNIC Number :    "<<nodePtr->Cnic<<endl;
			cout<<"\t\t\tAmount :         "<<nodePtr->Amount<<endl;
			displayAccounts(nodePtr->right);		
		}
}
//////////////////////////////////////////////////////////////// DisplayInfo()
void display()
{
	cout<<endl;
	cout<<"\t\t\t :::> Developer Info <:::"<<endl;
	cout<<endl<<endl;
	cout<<"\t\t\t Madan Lal (Semester III)"<<endl;
	cout<<"\t\t\t Department of Software Engineering"<<endl;
	cout<<"\t\t\t Sukkur IBA University"<<endl;
	cout<<"\t\t\t Project Name: PKR Digital Money Exchange"<<endl;
	cout<<"\t\t\t Date of creation: December 1, 2019"<<endl<<endl;
	cout<<"\t\t\t 1. Main Menu			2. Exit"<<endl;
	cout<<"\t\t\t";
	cin>>n;
	if(n == 1)
	{
		system("cls");
		second();
	}
} 
////////////////////////////////////////////////////////////// signIn()?
void signIn(Node *curr, string aNumber)
{
	while(curr && curr->AccountNumber != aNumber)
	{
		//prev = curr;
		if(curr->AccountNumber>aNumber)
		curr=curr->left;
		else
		curr=curr->right;
	}
	if(curr)
	{
			system("cls");
			cout<<endl<<"\t\t\t :::> Account Find Successfully <:::";
			cout<<endl<<endl<<endl;
	 		cout<<"\t\t\tAccount Number : "<<curr->AccountNumber<<endl;
			cout<<"\t\t\tName :           "<<curr->Name<<endl;
			cout<<"\t\t\tPhone Number :   "<<curr->PhoneNumber<<endl;
			cout<<"\t\t\tCNIC Number :    "<<curr->Cnic<<endl;
			cout<<"\t\t\tEmail :          "<<curr->Email<<endl;
			cout<<"\t\t\tAmount :         "<<curr->Amount<<endl;
	}	
	else
	{
		cout<<endl<<"\t\t\tAccount Not Found!!!"<<endl;
	}
	
}
////////////////////////////////////////////////////////////// shopping()
void shopping()
{
	int buy, price=0,quantity;
	bool condition=true;
	string accountNumber;
	char cl;
	again:
	system("cls");
	cout<<endl;
	cout<<"\t\t\t :::> Welcome to TUCK SHOP <:::"<<endl<<endl;
	cout<<" ::> Shop Menu <:: "<<endl;
	cout<<"1. Chocolates (50) "<<endl;
	cout<<"2. Cookies    (100)"<<endl;
	cout<<"3. Pizza      (150)"<<endl;
	cout<<"4. Burger     (100)"<<endl;
	cout<<"5. Cafe Tea   (50) "<<endl;
	
		cout<<endl<<"What you want to buy : ";
		cin>>buy;
		cout<<"Quantity : ";
		cin>>quantity;
		if(buy==1)
		{
		price=(price+50)*quantity;	
		}
		if(buy==2)
		{
		price=(price+100)*quantity;	
		}
		if(buy==3)
		{
		price=(price+150)*quantity;	
		}
		if(buy==4)
		{
		price=(price+100)*quantity;	
		}
		if(buy==5)
		{
		price=(price+50)*quantity;
		}
		cout<<"C. Continue Shopping       E. Exit Shopping"<<endl;
		cin>>cl;
		if(cl == 'C'|| cl == 'c')
		goto again;
		
		close:
		system("cls");	
			cout<<endl;	
			cout<<"\t\t\t :::> Login Your Account Here <:::"<<endl<<endl;
			cout<<"\t\t\t      Enter Account Number : ";
			cin>>accountNumber;
			cout<<endl;
			curr = root;

			while(curr && curr->AccountNumber != accountNumber)
			{
				if(curr->AccountNumber>accountNumber)
				curr=curr->left;
				else
				curr=curr->right;
			}
			if(curr)
			{
				curr->Amount-=price;
				cout<<"\t\t\t Total Bill is: "<<price<<endl<<endl;
				cout<<"\t\t\t Payment deducted."<<endl;
				cout<<"\t\t\t Thankyou for shopping..."<<endl;
				condition=true;
			}	
			else
			{
				cout<<"\t\t\t Account Not Found!!!"<<endl;
				system("pause");
				goto close;
			}
}
/////////////////////////////////////////////////////////////// deleteAccount()
void deleteAccount(string accountNumber)
{
	if(root == NULL)
	{
		cout<<"Account Not found!"<<endl;
	}
	else
	{
		curr=root;
		prev = root;
		
		while(curr && curr->AccountNumber != accountNumber)
		{
			prev=curr;
			if(curr->AccountNumber > accountNumber)
			curr=curr->left;
			else
			curr=curr->right;
		}
		if(!curr->left  &&  !curr->right)
		{
			if(curr == root)
			{
				delete curr;
			}
			else if(curr==prev->left)
			{
				prev->left=NULL;
				delete curr;
			}
			else if(curr==prev->right)
			{
				prev->right=NULL;
				delete curr;
			}
			
		}
		else if(!curr->left)
		{
			if(curr==prev->left)
			{
				prev->left=curr->right;
				delete curr;
			}
			else
			{
				prev->right=curr->right;
				delete curr;
			}
		}
		else if(!curr->right)
		{
			if(curr==prev->left)
			{
				prev->left=curr->left;
				delete curr;
			}
			else
			{
				prev->right=curr->left;
				delete curr;
			}
		}
		
		else if(curr->left && curr->right)
		{
			curr = prev->left;
			prev = NULL;
			while (curr->right != NULL)
			{
				prev = curr;
				curr = curr->right;
			}
			prev->AccountNumber = curr->AccountNumber;
			if (prev == NULL)
				prev->left = curr->left;
			else
				prev->right = curr->left;
			delete curr;
			cout<<endl<<"Account deleted Successfully."<<endl<<endl;
		}
	}
}
/////////////////////////////////////////////////////////////// depositMoney()
void depositMoney(int deposit)
{
	string accountNumber;
	close:
		cout<<endl;
		cout<<"Enter Account Number : ";
		cin>>accountNumber;
		curr = root;
			while(curr && curr->AccountNumber != accountNumber)
			{
				if(curr->AccountNumber>accountNumber)
				curr=curr->left;
				else
				curr=curr->right;
			}
			if(curr)
			{
				curr->Amount+=deposit;
				cout<<"successfully deposited..."<<endl;
			}	
			else
			{
				cout<<endl<<"\t\t\tAccount Not Found!!!"<<endl;
			}
}
////////////////////////////////////////////////////////////// second()
void second()
{
	int n;
	cout<<endl;
	cout<<"\t\t\t:::> PKR Digital Money Exchange <:::"<<endl;
	cout<<endl<<endl<<endl;
	cout<<" 1. Create a New Account"<<endl;
	cout<<" 2. Sign in Your Account"<<endl;
	cout<<" 3. Display all accounts"<<endl;
	cout<<" 4. For Shopping"<<endl;
	cout<<" 5. Delete Account"<<endl;
	cout<<" 6. Deposit Money"<<endl;
	cout<<" 7. Developer Info"<<endl;
	cin>>num;
	
	if(num == 1)
	{
		system("cls");
		createAccount();
		cout<<"\t\t\t1. Main Menu			2. Exit"<<endl;
		cout<<"\t\t\t";
		cin>>n;
		if(n == 1)
		{
			system("cls");
			second();
		}
	}
	if(num == 2)
	{
		cout<<"Enter Account Number : ";
		cin>>aNumber;
		signIn(root,aNumber);
		cout<<"\t\t\t1. Main Menu			2. Exit"<<endl;
		cout<<"\t\t\t";
		cin>>n;
		if(n == 1)
		{
			system("cls");
			second();
		}
	}
	if(num == 3)
	{
		system("cls");
		cout<<endl<<"\t\t\t>-------ACCOUNTS-INFORMATION-------<"<<endl<<endl;
		displayAccounts(root);
		cout<<"\t\t\t1. Main Menu			2. Exit"<<endl;
		cout<<"\t\t\t";
		cin>>n;
		if(n == 1)
		{
			system("cls");
			second();
		}
	}
	if(num == 4)
	{
		cout<<endl;
		shopping();	
		cout<<"1. Main Menu			2. Exit"<<endl;
		cin>>n;
		if(n == 1)
		{
			system("cls");
			second();
		}
	}
	if(num == 5)
	{
		system("cls");
		string accountNumber;
		cout<<"Enter Account Number : ";
		cin>>accountNumber;
		deleteAccount(accountNumber);
		cout<<"1. Main Menu			2. Exit"<<endl;
		cin>>n;
		if(n == 1)
		{
			system("cls");
			second();
		}
	}
	if(num == 6)
	{
		int deposit;
		again:
		system("cls");
		cout<<"Enter Money you want to deposit : ";
		cin>>deposit;
		if(deposit<0)
		{
		cout<<"Deposit money Error! Try again..."<<endl;
		system("pause");	
		goto again;	
		}
		depositMoney(deposit);
		cout<<"1. Main Menu			2. Exit"<<endl;
		cin>>n;
		if(n == 1)
		{
			system("cls");
			second();
		}
	}
	if(num == 7)
	{
		system("cls");
		display();
	}	
}	

};
/////////////////////////////////////////////// Main...
int main()
{
	list obj;
	string Username, Password;
	char c;
	sec:
	cout<<endl<<"\t\t\t:::> PKR Digital Money Exchange <:::"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t  Login Here"<<endl<<endl;
	cout<<"\t\t\t\tUsername: ";
	cin>>Username;
	cout<<"\t\t\t\tPassword: ";
	while(c != 13)
	{
		c=getch();
		if(c != 13)
		{
			Password+=c;
			cout<<"*";
		}
	}
	if(Username == "admin" && Password == "admin")
	{
		system("cls");
		obj.second();
	}	
	else
	{
		cout<<endl<<endl<<"\t\t\t"<<"Password Denied! Try again."<<endl;
		system("pause");
		system("cls");
		Password = "";
		c = ' ';
		goto sec;	
	}
}
