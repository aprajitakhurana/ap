#include<stdlib>
#include<math>
#include<fstream>
#include<conio>
#include<stdio>
struct emp
{
	char name[30];
	int empno;
	emp *next;
};
class stack
{   	emp * top;
	public:
		stack(){top=NULL;}
	void push()
		{emp *temp=new emp;
		 cin>>temp->empno;
		 gets(temp->name);
		 temp->next=NULL;
		 if(top==NULL)
		  { top=temp;}
		  else
		  {temp->next=top;
		  top=temp;
        }
		}
	void pop()
		{   if(top==NULL)
                    cout<<”Underflow”;
		else
{
emp *temp=top;
		  cout<<"\n node deleted are ";
		  cout<<temp->name<<temp->empno;
		  top=top->next;
	//free memory of node after pointing to NULL  
temp->next=NULL;
		  delete temp;
		}}
	void display()
		{
			emp *temp=top;
			if (top==NULL)
			cout<<"stack empty , Underflow";
			else
			{
			  cout<<"\n The details are ";
			  while(temp!=NULL)
			  {
	            cout<<temp->name<<temp->empno;                                                       
				  temp=temp->next;

		  }
		  }
		}
};

void main()
{
stack s1;
int ch;






while(1)
{
	cout<<"\n1. push \n 2. pop \n 3. Traversal \n";
	cin>>ch;
	switch(ch)
	{
		case 1: s1.push();break;
		case 2: s1.pop();break;
		case 3: s1.display();break;
		case 4: exit(0);
	}
}
}
