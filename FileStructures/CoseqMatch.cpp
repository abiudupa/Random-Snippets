//Cosequential match to match names between two lists
#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;

class names
{ 
    public:  char name[30];
}a[20],b[20];

int  main()
{
 int i,j,m=0,n=0;
 ifstream  fp1("list1.txt");
 ifstream  fp2("list2.txt");
 ofstream  fp3("list3.txt");
 while(!fp1.eof())
 {
  fp1.getline(a[++m].name,30,'\n');
  cout<<a[m].name;
 }
 while(!fp2.eof())
 {
  fp2.getline(b[++n].name,30,'\n');
  cout<<b[n].name;
 }
 for(i=0,j=0;i<m||j<n;)
    if(strcmp(a[i].name,b[j].name)<0)
       i++;
    else if(strcmp(a[i].name,b[j].name)>0)
       j++;
    else
    {
       fp3<<a[i].name;
       cout<<"\n"<<a[i].name;
       i++;j++;
    }
getch();
return 0;
}
