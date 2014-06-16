//Reverse the string entered
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
int main()
{
    int j=0,len;
    char name[10];
    while(1)
    {
            cout<<"\nenter name : ";
            cin>>name;
            len=strlen(name);
            cout<<"\nrev name : ";
            for(j=len-1;j>=0;j--)
                cout<<name[j];
    }
getch();
} 
