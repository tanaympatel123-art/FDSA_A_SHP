#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    string message;
    getline(cin,message);

    int count=0;
    stringstream ss(message);

    string longestword="";

    while(1)
    {
        string word;
        
        string w[10];

        for(int i=0;i<10;i++)
        {
            ss>>word;
            w[i]=word;
        }

        count=w[0].length();
        longestword=w[0];
        
        for(int i=1;i<10;i++)
        {
            if(w[i].length()>count)
            {
                count=w[i].length();
                longestword=w[i];
            }
        }

        break;
    }

    cout<<"Longest word: "<<longestword<<"\n";
    cout<<"Length is: "<<count;
    return 0;
}