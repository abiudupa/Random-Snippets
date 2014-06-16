//Read k lists and merge using k-way algorithm
include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

class list
{
	public:char name[20][30];
	       void read(int );
	       list();
	       int size,over,cur;
}a[8];

list::list()
{
	over=0;
	cur=0;
}
void list::read(int ch)
{
	int i=0;
    fstream fp;
	switch(ch)
	{
		case 0: fp.open("a0.txt",ios::in);
			if(!fp)
			{
				cout<<"Unable to open list1.txt"<<endl;
				exit(0);
			}
			while(!fp.eof())
			{
                  fp.getline(name[i++],20);
            }
                  size=i-1;
                  fp.close();     
                  break;
  	   case 1: fp.open("a1.txt",ios::in);
			if(!fp)
			{
				cout<<"Unable to open list1.txt"<<endl;
				exit(0);
			}
			while(!fp.eof())
			{
                  fp.getline(name[i++],20);
            }
                  size=i-1;
                  fp.close();
                  break;      
  	case 2: fp.open("a2.txt",ios::in);
			if(!fp)
			{
				cout<<"Unable to open list1.txt"<<endl;
				exit(0);
			}
			while(!fp.eof())
			{
                  fp.getline(name[i++],20);
            }
                  size=i-1;
                  fp.close();
                  break;
                        
  	case 3: fp.open("a3.txt",ios::in);
			if(!fp)
			{
				cout<<"Unable to open list1.txt"<<endl;
				exit(0);
			}
			while(!fp.eof())
			{
                  fp.getline(name[i++],20);
            }
                  size=i-1;
                  fp.close();
                  break;      
  	case 4: fp.open("a4.txt",ios::in);
			if(!fp)
			{
				cout<<"Unable to open list1.txt"<<endl;
				exit(0);
			}
			while(!fp.eof())
			{
                  fp.getline(name[i++],20);
            }
                  size=i-1;
                  fp.close();
                  break;   
  	case 5: fp.open("a5.txt",ios::in);
			if(!fp)
			{
				cout<<"Unable to open list1.txt"<<endl;
				exit(0);
			}
			while(!fp.eof())
			{
                  fp.getline(name[i++],20);
            }
                  size=i-1;
                  fp.close();
                  break;      
  	case 6: fp.open("a6.txt",ios::in);
			if(!fp)
			{
				cout<<"Unable to open list1.txt"<<endl;
				exit(0);
			}
			while(!fp.eof())
			{
                  fp.getline(name[i++],20);
            }
                  size=i-1;
                  fp.close();      
                  	break;
    case 7: fp.open("a7.txt",ios::in);
			if(!fp)
			{
				cout<<"Unable to open list1.txt"<<endl;
				exit(0);
			}
			while(!fp.eof())
			{
                  fp.getline(name[i++],20);
            }
                  size=i-1;
                  fp.close();      
                  	break;
	
	}
	
}

int main()
{
	list a[8];
	int i,x=0;
	for(int k=0;k<8;k++)
       a[k].read(k);
 while(1)
 {
         for(i=0;i<8;i++)
         {
                         if(a[0].over==1 && a[1].over==1 && a[2].over==1 && a[3].over==1 && a[4].over==1 && a[5].over==1 && a[6].over==1 && a[7].over==1 )
                           exit(0);
                         if(a[i].over!=1 && i!=x)
                            if(strcmp(a[x].name[a[x].cur],a[i].name[a[i].cur])>0)
                            x=i;
         }
         cout<<a[x].name[a[x].cur++]<<"\n";
         if(a[x].cur>=a[x].size)
          a[x++].over=1;
}

	return 0;
getch();
}
