#include<iostream>
using namespace std;

int main()
{
    int A[]={6,2,87,55,23};
    int B[]={};
    int n=sizeof(A)/sizeof(A[0]);//number of elements in array
    int t=n,size=n;

    //Bubble sort
    while(t--){
    for(int i=0;i<size-1;i++)
    {
        if(A[i]>A[i+1])
        {
            int temp;
            temp=A[i];
            A[i]=A[i+1];
            A[i+1]=temp;
        }
    }
    size--;
    }

     cout<<"Sorted through Bubble sort: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<endl;
    }



    //Selection sort
    for(int i=0;i<n-1;i++)
    {
        int min=A[i];
        int temp;
        int a1=i;


        for(int j=i+1; j<n;j++)
        {
            if(min>A[j])
            {
                a1=j;
                min=A[j]; 
            }
        }
         temp=A[i];
        A[i]=A[a1];
        A[a1]=temp;
    }

    cout<<"Sorted through Selection sort: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<endl;
    }


    //Insertion sort
    for(int i=1;i<n;i++)
    {
        int key=A[i];
        int j=i-1;

        while(j>=0 && A[j]>key)
        {
            A[j+1]=A[j];
            j--;
        }

        A[j+1]=key;
    }

    cout<<"Sorted through Insertion sort: "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<endl;
    }
    return 0;
}
