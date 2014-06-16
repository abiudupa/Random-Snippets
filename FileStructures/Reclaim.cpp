//Reclaim free space using linked lists
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class student 
{
	char usn[11],name[20],sem[2],buffer[50];
	public: friend istream & operator >>(istream &,student &);
            friend ostream & operator <<(ostream &,student &);
	        void pack(),unpack(),read(),write(),delet(char*),useOffset(int x);
	        int search(char u[]);
}s;
istream & operator >>(istream & in,student & stud)
{
	cout<<"Enter the usn,name,sem of the student"<<endl;
	cin>>stud.usn>>stud.name>>stud.sem;
	return in;
}
ostream & operator <<(ostream & out,student & stud)
{
	out<<"usn: "<<stud.usn<<"\tname: "<<stud.name<<"\tsem: "<<stud.sem<<endl;
	return out;
}
void student::pack()
{   strcpy(buffer,usn);
	strcat(buffer,"|");
	strcat(buffer,name);
	strcat(buffer,"|");
	strcat(buffer,sem);
	strcat(buffer,"|");
	for(int i=strlen(buffer);i<50;i++)
	    buffer[i]='_'; //	buffer[i]='\0';
}

void student::read()
{
	fstream fp1;
    fp1.open("12.txt",ios::in);
	if(!fp1)   {   cout<<"Unable to Open the File"<<endl;  return ;  }
	while(1)
	{
		fp1.getline(buffer,51);
		if(fp1.eof())
			break; //	if(buffer[0]=='$')continue;
		unpack();
		cout<<*this;
	}
	fp1.close();
}


void student::unpack()
{
	int i,j=0;
	for(i=0;buffer[j]!='|';i++,j++)
		usn[i]=buffer[j];
	usn[i]='\0';
	j++;
	for(i=0;buffer[j]!='|';i++,j++)
		name[i]=buffer[j];
	name[i]='\0';
	j++;
	for(i=0;buffer[j]!='|';i++,j++)
		sem[i]=buffer[j];
	sem[i]='\0';
	j++;
}

void student::write()
{
	fstream fp2;
    fp2.open("12.txt",ios::out|ios::app);
	if(!fp2) { cout<<"Unable to open the file"<<endl; return ; }
	cin>>*this;
	pack();
	fp2<<buffer<<endl;
	fp2.close();
}

int student::search(char u[])
{
	int flag=0,pos;
	fstream fp;
    fp.open("12.txt",ios::in); if(!fp){ cout<<"Unable to open the file"<<endl; return -1;}
	while(1)
	{
		pos=fp.tellg();
		fp.getline(buffer,51);
		if(fp.eof())
			break;
		if(buffer[0]=='$')
			continue;
		unpack();
		if(strcmp(usn,u)==0)
		{   flag=1;
			break;
		}
	}
	if(flag==1)
	{
		cout<<*this;
		fp.close();
		return pos;
	}
	else
		return -1;
}
void student::delet(char u[])
{
	int pos=search(u);
	if(pos==-1)
	{
		cout<<"No such student record exists\n";
		return ;
	}
	else
	{
		fstream fp3;
        fp3.open("12.txt",ios::out|ios::in);
		if(!fp3) { cout<<"Unable to open the file"; return ;}
		fp3.seekg(pos,ios::beg);
		fp3.getline(buffer,51);
		buffer[0]='$';
		fp3.seekp(pos,ios::beg);
		fp3<<buffer;
		fp3.close();
	}
}
void student::useOffset(int x)
{
	fstream fp4;
    fp4.open("12.txt",ios::out|ios::in);
	fp4.seekg(x,ios::beg);
	fp4.getline(buffer,51);
	cin>>*this;
	pack();
	fp4.seekp(x,ios::beg);
	fp4<<buffer;
	fp4.close();
}
class node
{
	public:int offset;
	       node *link;
};
class list
{
	node * head,* curr,* newNode;
	public: list();
	        void delet(char u[]),use();
}l;
list::list()
{   head='\0';   
}
void list::delet(char u[])
{
	int pos=s.search(u);
	if(pos==-1)
	{
		cout<<"no such record found\n";
		return ;
	}	
	newNode=new node;
	s.delet(u);
	newNode->link='\0';
	newNode->offset=pos;
	if(head==NULL)
	   head=newNode;
	else
	{
		newNode->link=head;
		head=newNode;
	}
}
void list::use()
{
	if(head=='\0')
		s.write();
	else
	{
		curr=head;
		s.useOffset(curr->offset);
		head=head->link;
		delete curr;
	}
}

int  main()
{
	int choice;
	char u[11];
	while(1)
	{
		cout<<"Enter the choice 1.insert(pack) 2.reclaim space 3.display(unpack) 4.delete 5.exit"<<endl;
	        cin>>choice;
		switch(choice)
		{
			case 1: s.write(); break;
			case 2: l.use(); break;
			case 3: s.read(); break;
			case 4: cout<<"Enter the usn\n";
                    cin>>u;
				    l.delet(u); break;
			case 5: exit(0);
		}
	}
	return 0;
}
	
