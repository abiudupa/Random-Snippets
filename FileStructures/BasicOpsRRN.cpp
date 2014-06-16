//Basic operations on file with RRN
#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
fstream fp,fp1;
char buffer[50]; int pos;

class student
{  private : char id[11],name[37],sem[2];
   
   public: void pack(),unpack();
           int modify(),search();
}s;

void student :: pack()
{   
    char ch;
    cout << "\nInserting New Record............!\n\nEnter USN,name,sem  :";
	cin >> s.id>>s.name>>s.sem;
strcpy(buffer,"-");
strcat(buffer,s.id);
strcat(buffer,"|");
strcat(buffer,s.name);
strcat(buffer,"|");
strcat(buffer,s.sem);
strcat(buffer,"|");
strcat(buffer,"#");    
    fp.open("ttt.txt",ios::out|ios::app);   //if(!fp) cout<<"cant open";
       fp<< buffer;
    fp.close();
    
    fp1.open("ttt.txt",ios::in);
       while(fp1.get(ch))
           cout<<ch;
    fp1.close();
}

void student :: unpack()
{
   char ch;
   fp.open("ttt.txt",ios::in);
   while (fp.get(ch))
   {  
        if ( ch == '|')
            cout<<"\t\t\t";
             else if(ch=='#')
           cout<<"\n"; 
	    else if(ch!='|'&& ch !='-' )
	           cout << ch;
        
   } 
   fp.close();
}

int student :: search() 
{
        int flag=0,i,rrn,rrncount=0;
        cout<<"\nEnter the rrn to be Searched\n";
        cin>>rrn;
        fp.open("ttt.txt", ios::in);
        fp.seekp(0, ios::beg);  /*if(fp.fail()) {cout<<"Error"; return 1;}*/
        while(1)
        {
		       pos=fp.tellg();
		       fp.getline(buffer,51,'#');
               if(fp.eof())
               {
                           cout<<"doesnt exist";
                           break;
               }
               if(rrncount==rrn)
               {
                                if(buffer[0]=='$')
                                {
                                                  cout<<"deleted";
                                                  break;
                                }
                                cout<<rrn<<"found";
                                for(i=0;i<buffer[i];i++)
                                   if(buffer[i]=='|')
                                      cout<<"\t";
                                   else if(buffer[i]=='#')
                                       cout<<"\n";
                                   else
                                     cout<<buffer[i];
                                 flag=1;
                                 break;
               }
               else
                   rrncount++;
             }
    fp.close();
	return flag;
 }
    
int student :: modify() //to mark the record as deleted record
{
		fp.open("ttt.txt", ios::in | ios::out);
        fp.seekp(pos,ios::beg);	
		   fp.put('$');		
        for(int i=0;i<strlen(buffer)-1;i++)
        fp.put('.');
        fp.close();
return 0;
}

int main()
{
   int ch;
   while(1)
   { 
          cout<<"\n 1 PACK() \n 2 UNPACK() \n 3 MODIFY \n 4 SEARCH \n 5 EXIT"<<endl;
          cin>>ch;
          switch(ch)
          {
	           case 1: s.pack(); break;
	           case 2: s.unpack(); break;
               case 3:  if (s.search()==1)
			            {    cout<< "\n  RECORD IS MARKED AS DELETED ";
			                  s.modify(); 
                        }
			            break;
	           case 4: s.search();break;
	           case 5: exit(0);
   }
} return 0;
getch();
}
