//B+ tree,operations : insert,search,display
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
char filename[]={"data.txt"};
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
int student::search(char u[])
{
	int flag=0,pos;
	fstream fin;
	fin.open(filename,ios::in);
	if(!fin)
	{
		cout<<"Unable to open the file"<<endl;
		return -1;
	}
	while(1)
	{
		pos=fin.tellg();
		fin.getline(buffer,51);
		if(fin.eof())
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
		fin.close();
		return pos;
	}
	else
		return -1;
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
void student::read()
{
	fstream fin;
	fin.open(filename,ios::in);
	if(!fin)   {   cout<<"Unable to Open the File"<<endl;  return ;  }
	while(1)
	{
		fin.getline(buffer,51);
		if(fin.eof())
			break; //	if(buffer[0]=='$')continue;
		unpack();
		cout<<*this;
	}
	fin.close();
}
void student::write()
{
	fstream fout;
	fout.open(filename,ios::out|ios::app);
	if(!fout) { cout<<"Unable to open the file"<<endl; return ; }
	cin>>*this;
	pack();
	fout<<buffer<<endl;
	fout.close();
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
		fstream fout;
		fout.open(filename,ios::out|ios::in);
		if(!fout) { cout<<"Unable to open the file"; return ;}
		fout.seekg(pos,ios::beg);
		fout.getline(buffer,51);
		buffer[0]='$';
		fout.seekp(pos,ios::beg);
		fout<<buffer;
		fout.close();
	}
}
void student::useOffset(int x)
{
	fstream fout;
	fout.open(filename,ios::out|ios::in);
	fout.seekg(x,ios::beg);
	fout.getline(buffer,51);
	cin>>*this;
	pack();
	fout.seekp(x,ios::beg);
	fout<<buffer;
	fout.close();
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
	
