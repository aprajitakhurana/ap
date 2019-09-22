Static stack program
#include<stdlib.h>
#include<math.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
const int size=5;
void push(int a[],int &top)
{ if(top==size-1)cout<<"overflow";
	else
	{int n;
	  cin>>n;
	  top+=1;
	  a[top]=n;
	}
}
void pop(int a[],int &top)
{  if(top==-1)cout<<"underflow";
	else
	{cout<<"element deleted is:" <<  a[top]<<endl;
	top-=1;
	}
}
void traversal(int a[],int top)
{
if(top==-1)cout<<"stack empty";
	else
	{  cout<<"contents are\n";
		for(int i=top;i>=0;i--)
	  cout<<a[i]<<'\t';
	  cout<<endl;
	}
}





void main()
{
int ch;
int a[size],top=-1;
while(1)
{  cout<<"\n 1.push \n. 2 pop \n 3 Display\n4. exit\n";
	cout<<"enter choice:";
	cin>>ch;
	switch(ch)
	{
	case 1: push(a,top);break;
	case 2: pop(a,top);break;
	case 3: traversal(a,top);break;
	case4: exit(0);
}}}
