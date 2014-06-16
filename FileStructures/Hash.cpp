//Hashing and collision resolution
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char hash_table[100][30],buffer[30],tombstone[]={"####"};
class student
{
  public: char key[5],name[20],sem[2];
	      void pack(),retrieve(int addr, char *),unpack(char *),initialize(),store(int);
}s;

void student :: initialize()
{
  for(int i=0;i<100; i++)
		strcpy(hash_table[i],tombstone);
}

int hash(char key[])
{
  int i=0,sum=0;	
  for(i=0;key[i]!='\0';i++)
	sum+=key[i]-48;
  return sum%99;
}

void student ::pack()
{
cout<<"\nEnter record key,name,sem:";
cin>>key>>name>>sem;
	strcpy(buffer,key);
	strcat(buffer,"|");
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,sem);
	strcat(buffer,"|");
}
void store(int addr)
{   
	int flag=0, i;
		   if(strcmp(hash_table[addr],tombstone)==0)	
			{     
				strcpy(hash_table[addr],buffer);
                flag=1;
				cout<< "Record is insert at its home address :"<<addr<<"\n";
			}		
			else  
                 for( i=addr+1; i!=addr;i++)
                 {
                    if(i%100==0)
                       i=0;
				    if(strcmp(hash_table[i], tombstone)==0)
					{	
					    cout<<"\ncollision..Home is  "<< addr << " Actual Address is "<< i<<"\n";
					    strcpy(hash_table[i],buffer);
				        flag=1;
					    break;
					}
			     }
           if(i==addr && (flag==0)) 
              cout<< "Hash File is Full, Record cannot be insert \n";
}
void student :: unpack(char buffer[])
{ int k=0,i;
  for(i=0; buffer[i]!='|'; i++)
		key[k++]=buffer[i];
	key[k]='\0';
    k=0;
  for(++i ; buffer[i]!='|'; i++)
        name[k++]=buffer[i];
    name[k]='\0';
    k=0;
  for(++i ; buffer[i]!='|'; i++)
        sem[k++]=buffer[i];
    sem[k]='\0';
}

void student :: retrieve(int addr,char k[])
{  int found=0,i=addr;
		do{
             if(strcmp(hash_table[i],tombstone)==0)
				break;
             s.unpack(hash_table[i]);	
			 if(strcmp(key,k)==0)
		     { found=1;
		       break;
		     }
			 else
	         {	i++;	
				if(i == 100 )
				i=0;
             }	 
		  }while(i!=addr);
    if(found==0)
		cout<<"\nRecord Does not Exists in Hash File\n";
	else
		cout<<"\nRecord Found\n\n"<<key <<"\t"<<name<<"\t"<<sem<<"\n\n";
}

int main()
{
 int choice,addr;char kk[5];
 s.initialize();
 while(1)
 {
   cout<<"\n1=>Store\n2=>Retrieve\n3=>Exit\nEnter your choice:";
   cin >> choice;
switch(choice)
{
case 1: s.pack();
	    addr=hash(s.key);
	    s.store(addr);           break;
case 2: cout<<"Enter Key: ";
        cin>>kk;
	    addr=hash(kk);
	    s.retrieve(addr, kk);  break;	
default:exit(0);
}
}
return 0;
}


