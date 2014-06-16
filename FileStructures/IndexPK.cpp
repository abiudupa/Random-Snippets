//Simple index based on primary key
#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<conio.h>
using namespace std;
char u[11],name[20],sem[2],buffer[20];
int indsize;

class student
{            char usn[11],name[20],sem[2];
}s;

class index
{           public: char usn[11],offset[5];
}ind[10];

class indfile
{           public: void initind(),write(),add(),remove(),display(),unpack();
	                int search(int);
}o; 

void indfile::initind()
{
	fstream fp;
    fp.open("index.txt",ios::in);
	if(!fp)
	{
		indsize=0;
		return;
	}
	for(indsize=0;;indsize++)
	{
		fp.getline(ind[indsize].usn,11,'|');		
        fp.getline(ind[indsize].offset,5,'\n'); 
		if(fp.eof())
			break;
	}
	fp.close();
}
void indfile::unpack()
{    for(int i=0;buffer[i]!='\0';i++)
    {       if(buffer[i]=='|')
               cout<<"\t";
            else
               cout<<buffer[i];
    }
    cout<<endl;
}

void indfile::display()
{ 
		fstream fp1;
        fp1.open("5.txt",ios::in);  if(!fp1){cout<<"unable to open";return ;}
		cout<< "\nDATA FILE.....\n";
		while(!fp1.eof())
		{ 
			fp1.getline(buffer,50,'#');
			o.unpack();
		}
		fp1.close();
		cout << "\nINDEX FILE \n";
		 for(int i=0;i<indsize;i++)
		   cout<<ind[i].usn << "\t\t"<<ind[i].offset<<"\n";
}

int indfile::search(int add_search)
{
	int low=0,high=indsize-1,mid,rec;
	while(1)
	{
		mid=(low+high)/2;
		if(strcmp(ind[mid].usn,u)==0)
			break;
		else if(low>high)
		{
			mid=-1;
			break;
		}
		else if(strcmp(u,ind[mid].usn)>0)
			low=mid+1;
		else if(strcmp(u,ind[mid].usn)<0)
			high=mid-1;
	}
	if(mid!=-1)
	{  if(add_search==0)
	   {
		cout<<"Record found"<<endl;
		fstream fp2;
        fp2.open("5.txt",ios::in);
		rec=atoi(ind[mid].offset);
		fp2.seekg(rec,ios::beg);
		cout<<"\nrec "<<atoi(ind[mid].offset);
		fp2.getline(buffer,50,'#');
		o.unpack();
		fp2.close();
	   }
	}
	return mid;
}

void indfile::add()
{ 
	int pos, ndig,dec,sign,i;
	char *str;
	if(indsize==10)
	{
		cout<<"\n\ncan't enter any more record (index size has reached its max value)"<<endl;
		return;
	}
	cout<<"\n\nEnter the usn  :";
	cin>>u;
	if(search(0)==1)
	{
		cout<<"\n\nRecord with this usn already exits ===> PRIMARY KEY CONTRAINT VIOLATION"<<endl;
		return;
	}
	for(i=indsize;i>0;i--)
	{
		if(strcmp(u,ind[i-1].usn)<0)
			ind[i]=ind[i-1];
		else
			break;
	}
    fstream fp3;
    fp3.open("5.txt",ios::out|ios::app);
	cout<<"Enter student Name,sem  :";
	cin>>name>>sem;
	pos=fp3.tellp();
	fp3<<u<<"|"<<name<<"|"<<sem<<"|#";
	fp3.close();
	  if(pos<10) ndig=1;
	  else if(pos>=10 && pos<100) ndig=2;
      else if(pos>=100 && pos < 1000) ndig=3;
	  else if(pos>=1000 && pos <10000) ndig=4;
	  else ndig=5;
    str=ecvt(pos,ndig,&dec,&sign);
	strcpy(ind[i].usn,u);
	strcpy(ind[i].offset,str);
	indsize++;
}
void indfile::remove()
{
	cout<<"\n\nEnter the usn to be deleted"<<endl;
	cin>>u;
	int pos,rec_mark;
	pos=search(0);
	if(pos==-1)
	{
		cout<<"\n\nNo such record present"<<endl;
		return;
	}
	rec_mark=atoi(ind[pos].offset);
	char ch;
	fstream fp4;
    fp4.open("5.txt",ios::in|ios::out);
	fp4.seekp(rec_mark,ios::beg);
        fp4.put('$'); 
	for(int i=pos;i<indsize;i++)
		ind[i]=ind[i+1];
	fp4.close();
	cout<<endl<<"\n\nrecord is deleted\n\n\n";
	indsize--;
}


void indfile::write()
{
	fstream fp5;
    fp5.open("index.txt",ios::out);
	for(int i=0;i<indsize;i++)
		fp5<<ind[i].usn<<"|"<<ind[i].offset<<"\n";
	fp5.close();
}

int main()
{
	int choice,flag;
	o.initind();
	while(1)
	{
		cout<<"\n\nEnter the choice  1.Add 2.Remove 3.Search 4.Display 5.Write 6.Exit\n\n"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: o.add();  break;
			case 2: o.remove(); break;
			case 3: cout<<"\n\nEnter the usn to be searched\n"<<endl;
				       cin>>u;
				    if(o.search(0)==-1)
					     cout<<"\n\nrecord not found\n\n";  break;
			case 4: o.display(); break;
			case 5: o.write(); break;
			case 6: exit(0);
		}

	}
getch();
}

