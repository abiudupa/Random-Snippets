//Reverse contents of file
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
int main()
{
    int i=0,j=0,len;
    char name[10],ch;
    while((ch=getc(stdin))!=EOF)
    {
                                if(ch!='\n')
                                 name[i++]=ch;
                                else
                                {
                                    name[i]='\0';
                                    len=strlen(name);
                                    for(j=len-1;j>=0;j--)
                                        cout<<name[j];
                                    cout<<endl;
                                    i=0;
                                }
    }
getch();
}

//./a.out <input.txt>output.txt
