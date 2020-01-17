#include<iostream>
#include<bits/stdc++.h> 
#include<unistd.h>
#include<fstream>
using namespace std;
class Node{
	public:
		string word;
		Node *next;
		
		Node()
		{
			this->word = '\0';
			this->next = NULL;
		}
		
		Node(string word)
		{
			this->word = word;
			next = NULL;
		}
		
		Node(string word, Node *next)
		{
			this->word = word;
			this->next = next;
		}
};

class Student{
	private:
		string Name;
		string Hobby;
		int age;
		
		
	public:
		Student *left;
		Student *right;
			
		Student(string Name, string Hobby, int age=0)
		{
			this->Name = Name;
			this->Hobby = Hobby;
			this->age = age;
			this->left = NULL;
			this->right = NULL;
		}
		
		void set_data(string Name, string Hobby, int age=0)
		{
			this->Name = Name;
			this->Hobby = Hobby;
			this->age = age;
		}
		
		string get_Name(void)
		{
			return Name;
		}
		
		string get_Hobby(void)
		{
			return Hobby;
		}
		
		int get_age(void)
		{
			return age;
		}
};

class BST{
	public:
		Student *root;
		
		BST(){
			root = NULL;
			 }
	 	bool searching(string n, Student *r)
		{
			if(r == NULL)
			{
				return 0;
			}
			if(r->get_Name() == n)
			{
				return 1;
			}
			else if(n < r->get_Name())
			{
				return searching(n, r->left);
			}
			else
			{
				return searching(n, r->right);
			}
		}
		void search(string key){
			//	Student *r=root;
				
			
				
				
			
				
			} 
		
		void insert(string n, string h, int a,int x=0)
		{
			if(root == NULL)
			{
				root = new Student(n, h, a);
			}
			else if(x==0)
			{
				Student *current = root;
				Student *parent;
		    	string temp=n;
				transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
				while(current != NULL)
				{
					parent = current;
					if(temp < current->get_Name())
					{
						current = current->left;
					}
					else
					{
						current = current->right;
					}
				}
				string temp1=parent->get_Name();
				transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
				if(temp < temp1)
				{
					 
					parent->left = new Student(n, h, a);
				}
				else
				{
					 
					parent->right = new Student(n, h, a);
				}
				
			}
			else if(x==1)//by hobby
			{ 
				Student *current = root;
				Student *parent;
				string temp=h;
				transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			  
				while(current != NULL)
				{
					parent = current;
					if(temp < current->get_Hobby())
					{
						current = current->left;
					}
					else
					{
						current = current->right;
					}
				}
				string temp1=parent->get_Hobby();
				transform(temp1.begin(), temp1.end(), temp1.begin(), ::tolower);
				if(temp < temp1)
				{
					 
					parent->left = new Student(n, h, a);
				}
				else
				{
					 
					parent->right = new Student(n, h, a);
				}
				
				
			}
			else if(x==2)//by age
			{
				
				Student *current = root;
				Student *parent;
				while(current != NULL)
				{
					parent = current;
					if(a < current->get_age())
					{
						current = current->left;
					}
					else
					{
						current = current->right;
					}
				}
				if(a < parent->get_age())
				{
					parent->left = new Student(n, h, a);
				}
				else
				{
					parent->right = new Student(n, h, a);
				}
				
				
				
				
			}	
		}
		void deleteTree(Student *r)
		{
			if(r==NULL)
			{
				return;
			}
			deleteTree(r->left);
			deleteTree(r->right);
			delete r;
		}
		void inorder_display(Student *r)
		{
			if(r == NULL)
			{
				return;
			}
			else
			{
				static int i=0;
				int sp_lim=30;
				if(i==0)
				{
					cout<<" Name:";
					for(int j=0;j<sp_lim-5;j++)
					{
						cout<<" ";
					}
					cout<<"Hobby:";
					for(int j=0;j<sp_lim-7;j++)
					{
						cout<<" ";
					}
					cout<<"Age:";
					cout<<endl;
				}
				i++;
				inorder_display(r->left);
				int sp_count=sp_lim-r->get_Name().length();
				cout<<r->get_Name();
				for(int j=0;j<sp_count;j++)
					{
						cout<<" ";
					}
				cout<<r->get_Hobby();
				sp_count=sp_lim-r->get_Hobby().length();
				for(int j=0;j<sp_count;j++)
					{
						cout<<" ";
					}
				cout<<r->get_age()<<endl;
				inorder_display(r->right);
			}
		}
};

class LinkedList{
	
		Node *head;
		Node *tail;
		BST B;
		
	
	public:
		LinkedList()
		{
			head = NULL;
		    tail = NULL;
		}
		
		void add_to_head(string w)
		{
			if(head == NULL)
			{
				head = new Node(w);
			}
			else
			{
				Node *newNode = new Node(w, head);
				head = newNode;
			}
		}
		
		void display(){
			Node *temp = head;
			while(temp != NULL)
			{
				cout<<temp->word<<endl;
				temp = temp->next;
			}
		}
		
		void input_data1(){
			ifstream infile1;
			infile1.open("dictionary.txt");
			while(!infile1.eof())
			{
				string x;
				infile1>>x;
				add_to_head(x);
			}
			infile1.close();
		}
		
		void input_data2()
		{
			ifstream infile1;
			infile1.open("dictionary2.txt");
			while(!infile1.eof())
			{
				string x;
				infile1>>x;
				add_to_head(x);
			}
			infile1.close();
		}
		bool search(string w)
		{
			string sl=w;
			transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
			
			Node* tmp=head;
			while(tmp!=NULL)
			{
				if(sl!=tmp->word)
				{
					tmp=tmp->next;
				}
				else
				{
					return true;
				}
			}
			return false;
		}

		
		
		void comparision()
		{
			ifstream infile2;
			infile2.open("input.txt");
			ofstream outfile;
			outfile.open("output.txt");
			while(!infile2.eof())
			{
				string w;
				infile2>>w;
				if(search(w) == false)
				{
					outfile<<w<<" ";
				}
			}
			infile2.close();
			outfile.close();
		}
		
		void comparision1(int x=0)
		{
			ifstream infile2;
			infile2.open("output.txt");
			string n;
			string h;
			int a;
			string w;
			
			do{
				
					infile2>>w;
					
				
					getline(infile2, n, ',');
					infile2>>w;
					
					getline(infile2, h, ',');
					infile2>>w;
					
					infile2>>a;
					
					infile2>>w;
					
				B.insert(n, h, a,x);
				
			}while(!infile2.eof());
			infile2.close();
		}
		void search(){
			system("cls");
			cout<<"hello";
			cout<<"enter key word";
			string key;
			cin>>key;
			B.search(key);
			
		}
		void displaytree( ){
			
			B.inorder_display(B.root);
						  }
		void deletetree()
		{
			B.deleteTree(B.root);
						  }				  
};
int main_menu(){
	LinkedList L;
	LinkedList L1;
	L.input_data1();//dictionary to L
	L1.input_data2();//dictionary1 to L1
	cout<<endl;
	L.comparision();//input to output
	L1.comparision1();//bst creation
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tData Extraction";
	cout<<endl;
	string x="Azeem Ahmed Khan";
	int j=0;
	for(j=0;j<3;j++)
	{
		for(int i=0;i<x.length();i++)
		{
			cout<<x[i];
			usleep(100000);
		}
		cout<<endl;
		if(j==1)
		{
			x="Usman Yousuf";
		}
		else{
			x="Mohit Kumar";
		}
	}
	system("cls");
	int type;
	cout<<"\t\t\t\t**********Menu**********"<<endl;
	do{
	cout<<"1) Display"<<endl;
	cout<<"2) Search"<<endl;
	cout<<"3) Update"<<endl;
	cout<<"4) Delete"<<endl;
	cout<<"0) Exit"<<endl;
	cin>>type;
	if(type==1)
	{
		system("cls");
		cout<<"1) Display by Name"<<endl;
		cout<<"2) Display by Hobby"<<endl;
		cout<<"3) Display by Age"<<endl;
		cout<<"0) Return"<<endl;
		cin>>type;
		if(type==1)
		{
			//L1.deletetree();
			system("cls");
			//L1.comparision1();//output to BST
			L1.displaytree();
			
		}
		else if(type==2)
		{
			system("cls");
			L1.deletetree();
			L1.comparision1(1);//output to BST
			L1.displaytree();
		
		}
		else if(type==3)
		{
			system("cls");
			L1.deletetree();
			L1.comparision1(2);//output to BST
			L1.displaytree();
		
		}
		else if (type==0)
		{
			type=-1;
		}
	}
	else if(type==2)
	{
		L1.search();
	}
	else if(type==3)
	{
		
	}
	else if(type==4)
	{
		
	}
}
	while(type!=0);
	
}
int main(void)
{
	BST B;
	main_menu();
	
}
