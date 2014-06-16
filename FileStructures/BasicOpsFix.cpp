//Basic operations on file with fixed length records
#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
char buffer[50]; int pos;
 class student
 {  private : char id[11],name[37],sem[2];
   
    public: void pack(),unpack();
           int modify(),search();
 }s;

void student :: pack()
{   
    char ch;int i;
    cout << "\nInserting New Record............!\n\nEnter USN,name,sem  :";
	cin >> s.id>>s.name>>s.sem;
strcpy(buffer,"-");
strcat(buffer,s.id);
strcat(buffer,"|");
strcat(buffer,s.name);
strcat(buffer,"|");
strcat(buffer,s.sem);
strcat(buffer,"|");
    for(i=strlen(buffer);i<49;i++)
	    buffer[i]='-';
        buffer[i]='#';  
    fstream fp;
    fp.open("t.txt",ios::out|ios::app);   //if(!fp) cout<<"cant open";
       fp<< buffer << "\n";
    fp.close();
    fstream fp1;
    fp1.open("t.txt",ios::in);
       while(fp1.get(ch))
           cout<<ch;
    fp1.close();
}

void student :: unpack()
{
   char ch;
   fstream fp2;
   fp2.open("t.txt",ios::in);
   while (fp2.get(ch))
   {  
        if ( ch == '|')
            cout<<"\t\t\t";
	    else
            if(ch!='|'&& ch !='-' )
	           cout << ch; 
   } 
   fp2.close();
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
	    fstream fp4;
        fp4.open("t.txt", ios::in);
        fp4.seekp(0, ios::beg);  /*if(fp.fail()) {cout<<"Error"; return 1;}*/
        while(!fp4.eof())
        {
		       pos=fp4.tellg();
		       loop: fp4.getline(buffer,51,'#');
                     if(buffer[0]=='$') 
		             {  pos +=  strlen(buffer)+1;
                        goto loop; 
                     } 
               for(i=0;buffer[i]!='|'; i++)
                   tempid[i]=buffer[i];
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
    fp4.close();
	return flag;
 }
    
int student :: modify() //to mark the record as deleted record
{
		fstream fp3;
        fp3.open("t.txt", ios::in | ios::out);
        fp3.seekp(pos,ios::beg);	
		   fp3.put('$');		//mark it deleted
        fp3.close();
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
	           case 4: s.search(); break;
	           case 5: exit(0);
   }
} return 0;
getch();
}
