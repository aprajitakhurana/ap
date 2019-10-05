#include<iostream>
using namespace std;

int moves=0;

void toi (int n,char source,char temp,char dest)
{
    if(n==1)
    {
        cout<<"disc"<<n<<" moves from "<<source<<" to "<<dest;
        moves++;
        cout<<endl;
        return;
    }
    
    
        toi(n-1,source,dest,temp);
    
        cout<<"disc"<<n<<" moves from "<<source<<" to "<<dest;
        cout<<endl;
        moves++;

        toi(n-1,temp,source,dest);
    
      
        
    
    


}

int main()
{   int n;
    char source , dest , temp;
    cout<<" Enter no. of discs";
    cin>>n;
    cout<<endl<<" name source ";
    cin>>source;
    cout<<endl<<" name temp ";
    cin>>temp;
    cout<<endl<<" name dest ";
    cin>>dest;
    cout<<endl;
    toi(n,source,temp,dest);
    cout<<endl<<"no. of moves are "<<moves<<endl;
}