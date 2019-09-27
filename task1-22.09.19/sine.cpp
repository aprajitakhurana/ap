#include<iostream>
#include<iomanip>

using namespace std;

int main()
{	int i,n;
	float x, sum, t;
	
	cout<<"enter the value of x in degrees : ";
	cin>>x;
	x*=3.14159/180;

	cout<<"enter the terms upto which you wish to calculate : ";
	cin>>n;
	
	t=x;
	sum=x;
	
	
	for(i=0;i<=n;i++)
	{
		t=(t*(-1)*x*x)/(2*i*(2*i+1));
		sum=sum+t;
	}

	cout<<"The value of sine ( "<<x<< " )= "<<setprecision(4)<<sum;

return 0;
}

