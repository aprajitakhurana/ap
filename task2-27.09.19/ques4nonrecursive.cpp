#include<iostream>

using namespace std;

void find_sum(int n)
{
      int r;
      int sum=0;
    while(n>=10)
  {
    while(n!=0)
    {
      r=n%10;
      sum+=r;
      n=n/10;
    }
      n=sum;
      sum=0;
  }        
          
          
    
        cout<<"Sum is : \t"<<n<<endl;

}

int main()
{
    int num;
    cout<<"Enter number : \t";
    cin>>num;
    cout<<endl;
    find_sum(num);
    return(0);

}