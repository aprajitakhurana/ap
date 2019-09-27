#include<iostream>
#include<math.h>


using namespace std;

void input(double a[][10], int r,int c);
void product(double a[][10],double b[][10],double s[][10],int r1,int c1,int c2);
void display(double s[][10],int r,int c);
void norm(double s[][10],int r,int c);
double determinant(double s[][10],int r,int c);
void transpose(double s[][10],int r,int c);
void inverse(double ); 

int main()
{
    double a[10][10],b[10][10],s[10][10],d;
    int r1,r2,c1,c2,i,j,k;
   
    cout<<"Enter the number of rows and columns for the first matrix:"<<endl<<"Rows: ";
    cin>>r1;
    cout<<endl<<"columns: ";
    cin>>c1;
    cout<<endl;

    cout<<"Enter the number of rows and columns for the second matrix:"<<endl<<"Rows: ";
    cin>>r2;
    cout<<endl<<"columns: ";
    cin>>c2;
    cout<<endl;

    if(c1!=r2)
    {
        cout<<"Matrices cannot be multiplied";
        exit(0);
    }

    cout<<"\nEnter First Matrix"<<endl;
    input(a,r1,c1);
    cout<<"\nEnter Second Matrix"<<endl;
    input(b,r2,c2);

    product(a,b,s,r1,c1,c2);

    cout<<"\n First Matrix";
    display(a,r1,c1);
    norm(a,r1,c1);
    cout<<"Transpose ";
    transpose(a,r1,c1);

    cout<<"\n Second Matrix";
    display(b,r2,c2);
    norm(b,r2,c2);
    cout<<"Transpose ";
    transpose(b,r2,c2);

    cout<<"\n Product:";
    display(s,r1,c2);
    norm(s,r1,c2);
    cout<<"Transpose ";
    transpose(s,r1,c2);
    cout<<"\n DETERMINANT OF PRODUCT \t";
    d=determinant(s,r1,c2);
    cout<<d<<endl<<endl;


return 0;

}

void input(double a[][10],int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)

    {
        cout<<"Enter Element"<<i+1<<j+1<<" : ";
        cin>>a[i][j];
    }

}

void display(double a[][10], int r,int c)
{
    int i,j;   
    for(i=0;i<r;i++)
    {
         cout<<endl;
         for(j=0;j<c;j++)
         cout<<a[i][j]<<'\t';

    }
    
}

void product(double a[][10], double b[][10], double s[][10], int r1, int c1, int c2)
{
    int i,j,k;
    for(i=0;i<r1;i++)
    {
        for (j=0;j<c2;j++)
        {
            s[i][j]=0;
            for(k=0;k<c1;k++)
            s[i][j]+=a[i][k]*b[k][j];
        }
    }
}

void norm(double a[][10],int r1, int c1 )
{
    int i,j;
    int sum=0;
    for(i=0;i<r1;i++)
    {
        for (j=0;j<c1;j++)
        {
         sum+=(a[i][j]*a[i][j]); 
        }
    }
    cout<<endl<<"\n Norm of matrix :"<<sqrt(sum)<<endl<<endl;
}

double determinant(double s[][10],int r,int c)
{   if(r!=c) 
    {   
        cout<<endl<<"NOT A SQUARE MATRIX : Determinant can't be computed."<<endl;
    }
    else
    {      
        int n,i,j,subi,subj;
        double submatrix[10][10];
        double det=0;

        if(r==2)
        {
            det=((s[0][0]*s[1][1])-(s[0][1]*s[1][0]));
        }
        else
        {
            for(n=0;n<r;n++)
            {
                subi=0;
                for(i=1;i<r;i++)
                {
                    subj=0;
                    for(j=0;j<r;j++)
                    {
                        if(j==n)
                        {
                            continue;
                        }
                        submatrix[subi][subj]=s[i][j];
                        subj++;
                    }
                    subi++;
                }
                det=det+(pow(-1,n)*s[0][n]*determinant(submatrix,r-1,c-1));
            }
            return det;
        }
        
     
    }
   

}

void transpose(double s[][10],int r, int c)
{
    int i,j;
    double t[10][10];
    for (i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            t[j][i]=s[i][j];
        }
        
    }
    for(i=0;i<c;i++)
    {
         cout<<endl;
         for(j=0;j<r;j++)
         cout<<t[i][j]<<'\t';

    }
    cout<<endl;
}

void inverse()