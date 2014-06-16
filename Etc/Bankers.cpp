//Implementation of Bankers algorithm
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int m,n,i,j,max[10][10],alloc[10][10],need[10][10],v[10],avail[10],p[10],finish[10],count=0,flag,sum,d=0;
void readtable(int t[10][10])
{
     for(i=0;i<m;i++)
         for(j=0;j<n;j++)
             scanf("%d",&t[i][j]);
}
void input()
{
     printf("enter p,r :");
        scanf("%d%d",&m,&n);
     printf("\nenter max table :\n");
        readtable(max);
     printf("\nenter alloc table :\n");
        readtable(alloc);
     printf("\nenter max unit of each res :");
        for(j=0;j<n;j++)
            scanf("%d",&v[j]);
}
void calc()
{
   for(i=0;i<m;i++)
      finish[i]=0;
   for(i=0;i<m;i++)
     for(j=0;j<n;j++)
       need[i][j]=max[i][j]-alloc[i][j];
   for(j=0;j<n;j++)
   {
                   sum=0;
                   for(i=0;i<m;i++)
                      sum=sum+alloc[i][j];  
                   avail[j]=v[j]-sum;
   }             
}
void select()
{
     while(count<m)      
     {
                         for(i=0;i<m;i++)
                         {
                                         if(finish[i]==0)
                                         {
                                                         for(j=0;j<n;j++)
                                                         {
                                                                         if(need[i][j]<=avail[j])
                                                                            flag=1;
                                                                         else
                                                                         {
                                                                             flag=0;
                                                                             break;
                                                                         }
                                                         }
                                                         if(flag==1)
                                                         {
                                                                    finish[i]=1;
                                                                    p[count]=i;
                                                                    count++;
                                                                    for(j=0;j<n;j++)
                                                                        avail[j]=avail[j]+alloc[i][j];
                                                         }
                                         }
                         }
                         d++;
                         if(d>2*m)
                           break;
     }
}
int main()
{
     input();
     calc();
     select();
     if(count<m)
       printf("\ndeadlock");
     else
     {
           printf("\nsafe seq");
           for(i=0;i<m;i++)
              printf("\np%d\n",p[i]);
     }
     getch();
}
     
