#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
int  suite[15]={0,0} ;
int  stan[50]={0,0} ;
class hotelroom
{	int rno;
	char name[30];
	int cid ,cim ,ciy;
	int cod ,com ,coy;
	char type[20];
public :
	void enter()
	{	cout<<"Enter Details  : "<<'\n';
		cout<<"Name : " ;
		gets(name);
		cout<<'\n'<<"Check in Date : "<<'\n';
		cout<<"Date :  ";
		cin>>cid;
		cout<<"Month : ";
		cin>>cim ;
		cout<<"Year : ";
		cin>>ciy ;
		cout<<'\n'<<"Check out Date : "<<'\n';
		cout<<"Date :  ";
		cin>>cod;
		cout<<"Month : ";
		cin>>com ;
		cout<<"Year : ";
		cin>>coy ;

		cout<<'\n' <<"Room Type : ";
		gets(type) ;
		cout<<'\n';
	}
	void show()
	{	cout<<"Your Details are as follows : "<<'\n';
		cout<<"Name : "<<name<<'\n';
		cout<<'\n'<<"Check in Date : "<<cid<<'/'<<cim<< '/'<<ciy;
		cout<<'\n'<<"Check out Date : "<<cod<<'/'<<cim<<'/'<<ciy;
		cout<<'\n'<<"Room Type : "<<type<<'\n'  ;
		cout<<"Room Number : "<<rno<<'\n' ;
	}
	void cidmod(int d, int m ,int y)
	{	cid =d ;
		cim =m ;
		ciy =y ;
	}
	void codmod(int d, int m ,int y)
	{	cod =d ;
		com =m ;
		coy =y ;
	}

	int returnrno()
	{	return rno ;
	}
	char * rettype()
	{	return type;
	}
	char * retname()
	{ 	return name;
	}
	void assignrno(int r)
	{	rno=r;
	}
};
int checksuite()
{	hotelroom  h ;
	int flag , c = 0 ,a = 0 ;
	ifstream  fin("hotel.dat",ios::binary);
	for(int i =1  ; i<=15 ; i++)
	{	flag =1;
		while(!fin.eof())
		{    if(!fin.read((char *)&h , sizeof(h)))
			break;
		   else
		    {  if(h.returnrno()==i)
			{	flag = 2 ;
				break ;
			}
		    }
		}
	if(flag!=2)
	{	a = 100+i ;
		break ;
	}
	}
	fin.close() ;
return a;
 }
int checkstan()
{	hotelroom  h ;
	int flag , a = 0;
	ifstream  fin("hotel.dat",ios::binary);
	for(int i =1  ; i<=50 ; i++)
	{	flag =1;
		while(!fin.eof())
		{    fin.read((char *)&h , sizeof(h));
		      if(h.returnrno()==i)
			{	flag = 2 ;
				break ;
			}
		}
	if(flag!=2)
       {	a =  1000+i;
		break ;
       }
	}
	fin.close();
return a ;
}
void booking()
{	hotelroom  h ;
	h.enter();
	ofstream  fout("hotel.dat",ios::binary);
	int  c;
	if(! strcmpi( h.rettype(), "Suite"))
	       c = checksuite()  ;
	else
		c = checkstan() ;
	if(c==0)
	cout<<"Sorry We are Booked ";
	else
	{	cout<<"Booking Succesful"<<'\n';
		h.assignrno(c);
		fout.write((char *)&h , sizeof(h));
	}
fout.close();
}
void add()
{	hotelroom  h ;
	h.enter();
	ofstream  fout("hotel.dat",ios::binary|ios::app);
	int  c;
	if(! strcmpi( h.rettype(), "Suite"))
	       c = checksuite()  ;
	else
		c = checkstan() ;
	if(c==0)
	cout<<"Sorry We are Booked ";
	else
	{	cout<<"Booking Succesful";
		h.assignrno(c);
		fout.write((char *)&h , sizeof(h));
	}
fout.close();
}
void cancel()
{	char name[20];
	hotelroom h ;
	ofstream fout("temp.dat",ios::binary) ;
	ifstream  fin("hotel.dat",ios::binary);
	cout<<"Enter your Name : ";
	gets(name);
	while(!fin.eof())
	{	fin.read((char *)&h ,sizeof(h));
		if( strcmpi(h.retname(),name)!=0)
			fout .write((char *)&h , sizeof(h));
	}
	fin.close();
	fout.close();
	remove("hotel.dat");
	rename("temp.dat","hotel.dat");
	cout<<"Booking Successfully Cancelled" ;
}
void search()
{	char s[20] ;
	int c=1;
	cout<<"Enter your Name. ";
	gets(s);
	hotelroom h;
	ifstream fin("hotel.dat" ,ios::binary);
	while(!fin.eof())
	{	if(!fin.read((char *)&h , sizeof(h)))
		   break;
		else
		{	if(!strcmpi(h.retname(),s))
			{	h.show();
				c=2 ;
			}
		}
	}
	if(c==1)
	cout<<"Sorry Couldn't find the record."<<'\n';
fin.close();
}
void modify()
{	fstream f("hotel.dat",ios::binary|ios::in|ios::out);
		if(!f)
			cout<<"Sorry couldn't read file. ";
		else
		{	int d ,m ,y ,pos ,c ;
			char s[80];
			hotelroom h ;
				cout<<"Enter your Name " ;
				gets(s) ;
				cout<<"1, Modify Check-in Date"<<'\n';
				cout<<"2. Modify Check-out Date"<<'\n';
				cin>>c ;
			if(c ==1)
		       { cout<<"Date : "; cin>>d ; cout<<"Month : ";
			cin>>m; cout<<"Year : "; cin>>y;
			while(!f.eof())
			{	pos = f.tellp() ;
				if(!f.read((char*)&h, sizeof(h)))
					break;
				if(!strcmpi(h.retname() , s ))
				{	h.cidmod(d,m,y) ;
					f.seekp(pos);
					f.write((char*)&h , sizeof(h));
					break;
				}
			}
		      }
		else
		{  cin>>d>>m>>y ;
			while(!f.eof())
			{	pos = f.tellp() ;
				if(!f.read((char*)&h, sizeof(h)))
					break;
				if(!strcmpi(h.retname() , s ))
				{	h.codmod(d,m,y) ;
					f.seekp(pos);
					f.write((char*)&h , sizeof(h));
					break;
				}
			}
		}
	}
cout<<"Booking Successfully Modified. "<<'\n';
f.close();
}

void display()
{	ifstream fin("hotel.dat" , ios::binary);
	hotelroom h ;

	if(! fin)
		cout<<"Sorry Couldn't Read File " ;

	else
	{	while(1)
		{   if(! fin.read((char *)&h ,sizeof(h)))
			break ;
		   else
			h.show();
		}
	}
}

void main()
{	cout<<'\t'<<"********* HOTEL TRANSYLVANIA *********"<<'\n';
	cout<<"Room Type : Suite "<<'\t'<<"Cost : 12,000/night"<<'\t'<<"Complimentary Breakfast and Dinner/Lunch"<<'\n';
	cout<<"Room Type : Standard "<<'\t'<<"Cost : 9,000/night"<<'\t'<<"Complimentary Breakfast "<<'\n';
	int c ;
	while(1)
	{	cout<<"1. Booking. "<<'\n' ;
		cout<<"2. Add Booking. "<<'\n';
		cout<<"3. Cancel Booking. "<<'\n' ;
		cout<<"4. Modify Booking. "<<'\n' ;
		cout<<"5. Check Booking. "<<'\n';
		cout<<"6. Display Booking. "<<'\n';
		cout<<"7. Exit. "<<'\n' ;
		cin>>c;

	if(c ==1)
	booking();
	else if(c==2)
	add();
	else if(c ==3)
	cancel() ;
	else if(c==4)
	modify();
	else if(c==5)
	search();
	else if(c==6)
	display();
	else
	exit(0);
	}
}


