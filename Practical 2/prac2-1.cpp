#include<iostream>
using namespace std;

void Check(int A[],int n,int x,int i)
{
    if(i>=n)
    {
        cout<<"The car is not in the parking lot."<<endl;
        return;
    }

    if(A[i]==x)
    {
     cout<<"Found the car at: "<<i+1<<" position."<<endl;
     return; 
    }

    
 Check(A,n,x,i+1);

}

int main()
{
    int A[]={2,4,3,5,6,7,8,9};
    int x=5;
    int n=sizeof(A)/sizeof(A[0]);
    bool found=false;

    //iterative approach
    for(int i=0;i<n;i++)
    {
        
        if(A[i]==x)
        {
            found=true;
            cout<<"Found the car at: "<<i+1<<" position."<<endl;
            break;
        }
        
       
    }

    if(!found)
    {
         
        
            cout<<"The car is not in the Parking lot."<<endl;
        
    }

    //recursive approach
    Check(A,n,x,0);


    return 0;
}