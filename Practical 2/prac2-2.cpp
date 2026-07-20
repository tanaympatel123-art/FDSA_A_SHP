#include<iostream>
using namespace std;

void Check(int A[],int start,int end,int x)
{
    int mid=(start+end)/2;
    if(start>end)
    {
        cout<<"The book is not in the catalog."<<endl;
        return;
    }

    if(A[mid]==x)
        {
            cout<<"The book is at position: "<<mid+1<<endl;
            return;
        }

        else if(A[mid]>x)
        {
            Check(A,start,mid-1,x);
        }

        else if(A[mid]<x)
        {
            Check(A,mid+1,end,x);
        }

   

}

int main()
{
    int A[]={2,4,5,7,9,15,45,55,62,71};
    int x=45;
    int n=sizeof(A)/sizeof(A[0]);
    int start=0;
    int end=n-1;
    int mid=(start+end)/2;
    bool found=false;

    //iterative approach
    while(start<=end)
    {
        mid=(start+end)/2;

        if(A[mid]==x)
        {
            found=true;
            cout<<"The book is at position: "<<mid+1<<endl;
            break;
        }

        else if(A[mid]>x)
        {
            end=mid-1;
        }

        else if(A[mid]<x)
        {
            start=mid+1;
        }
    }
    
    if(!found)
    {
        cout<<"The book is not on the catalog."<<endl;
    }

    start=0;
    end=n-1;

    //recursive approach
    Check(A,start,end,x);

    return 0;
}