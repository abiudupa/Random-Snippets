//Basic operations on file with variable length record
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
        char key[10], tempid[10], key_copy[10];
        int flag=0,i;
        cout<<"\nEnter the USN to be Searched\n";
        cin>>key;
	strcpy(key_copy, key);
	strcpy(tempid,"-");
	strcat(tempid, key);
	strcpy(key, tempid);
        fp.open("ttt.txt", ios::in);
        fp.seekp(0, ios::beg);  /*if(fp.fail()) {cout<<"Error"; return 1;}*/
        while(!fp.eof())
        {
		       pos=fp.tellg();
		       cout<<"\npos :"<<pos;
		       loop: fp.getline(buffer,51,'#');
                     if(buffer[0]=='$') 
		             {  pos +=  strlen(buffer)+1;
                        goto loop; 
                     }
               for(i=0;buffer[i]!='|'; i++)
                   tempid[i]=buffer[i];
               cout<<"\n"<<key<<"\n"<<tempid;
               tempid[i]='\0';  
               if(strcmp(key,tempid)==0)
               {
                  flag=1; break;
               }
         }
    if(flag==1) 
		cout<<"\n RECORD WITH ID " << key_copy << " IS FOUND \n"; 
	else
		cout<<"\n Ooooops SORRY......  RECORD WITH ID " << key_copy << " DOES NOT EXIST\n";
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
	           case 1: s.pack();
		               break;
	           case 2: s.unpack();
		               break;
               case 3:  if (s.search()==1)
			            {    cout<< "\n  RECORD IS MARKED AS DELETED ";
			                  s.modify(); 
                        }
			            break;
	           case 4: s.search();
		               break;
	           case 5: exit(0);
   }
} return 0;
getch();
}
