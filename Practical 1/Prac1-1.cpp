#include<iostream>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,5};
    int hour;

    cout << "Enter the number of hours: ";
    cin >> hour;

    int n = sizeof(a)/sizeof(a[0]);

    int b = hour % n;

    for(int j = 0; j < b; j++)
    {
        int temp = a[0];

        for(int i = 0; i < n-1; i++)
        {
            a[i] = a[i+1];
        }

        a[n-1] = temp;
    }

    for(int i = 0; i < n; i++)
        cout << a[i];

    return 0;
}