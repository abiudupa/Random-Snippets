//Round robin and srtf to calculte average turnaround time
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct proc
{
       int id,at,bt,wt,tat,rem,finish;
       float ratio;
}p[10];
struct proc temp;
void rr(int,int,int[],int[]);
void srtf(int);
int no;
int main()
{
    int n,tq,bt[10],st[10],i,ch;
    for(;;)
    {
    printf("\nenter your choice\n1.rr\n2.srtf\n3.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
              case 1:
                   printf("\nenter n,tq : ");
                   scanf("%d%d",&n,&tq);
                   printf("\nenter bt :");
                   for(i=0;i<n;i++)
                   {
                                   scanf("%d",&bt[i]);
                                   st[i]=bt[i];
                   }
                   rr(n,tq,bt,st);
                   break;
              case 2:
                   printf("\nenter n : ");
                   scanf("%d",&n);
                   srtf(n);
                   break;
              case 3:
                   exit(0);
    }
    }
    getch();
}

void rr(int n,int tq,int bt[],int st[])
{
     int i,count,stat=0,swt=0,tat[10],wt[10],t,sq=0;
     float atat,awt;
     while(1)
     {
             for(i=0,count=0;i<n;i++)
             {
                                     t=tq;
                                     if(st[i]==0)
                                     {
                                                 count++;
                                                 continue;
                                     }
                                     if(st[i]>tq)
                                        st[i]=st[i]-tq;
                                     else 
                                        {
                                                    t=st[i];
                                                    st[i]=0;
                                        }
                                        sq=sq+t;
                                        tat[i]=sq;
             }
             if(count==n)
               break;
     }
     for(i=0;i<n;i++)
     {
                     wt[i]=tat[i]-bt[i]; 
                     stat=stat+tat[i];
                     swt=swt+wt[i];
     }
     atat=(float)stat/n;
     awt=(float)swt/n;
     printf("\np bt tat wt ");
     for(i=0;i<n;i++)
     printf("\n%d %d  %d   %d",i,bt[i],tat[i],wt[i]);
     printf("\natat=%f\nawt=%f\n",atat,awt);
}          

int cp(int s)
{
    int i;
    for(i=1;i<=s;i++)
    {
                     if(p[i].rem!=0)
                        return 1;
    }
    return 0;
}

int np()
{
    int i,l,min=100;
    for(i=1;i<=no;i++)
    {
                      if(p[i].rem!=0&&p[i].rem<min)
                      {
                                     min=p[i].rem;
                                     l=i;
                      }
    }
    return l;
}

void srtf(int n)
{
     int i,j,k,time=0;
     float awt=0,atat=0;
     for(i=1;i<=n;i++)
     {
                      p[i].id=i;
                      printf("\n enter at :");
                      scanf("%d",&(p[i].at));
                      printf("enter at :");
                      scanf("%d",&(p[i].bt));
                      p[i].rem=p[i].bt;
     }
     for(i=1;i<=n;i++)
     {
                      for(j=i+1;j<=n;j++)
                      {
                                         if(p[i].at>p[j].at)
                                         {
                                                            temp=p[i];
                                                            p[i]=p[j];
                                                            p[j]=temp;
                                         }
                      }
     }
     no=0;
     j=1;
     while(cp(n)==1)
     {
                    if(p[no+1].at==time)
                    {
                                        no++;
                                        if(p[j].rem==0)
                                        
                                                       p[j].finish=time;
                                                       j=np();
                                        
                    }
                    if(p[j].rem!=0)
                    {
                                   p[j].rem--;
                                   for(i=1;i<=no;i++)
                                   {
                                                     if(i!=j && p[i].rem!=0)
                                                     {
                                                             p[i].wt++;
                                                     }
                                   }
                    }
                    else
                    {
                        p[j].finish=time;
                        j=np();
                        time--;
                        k=j;
                    }
                    time++;
     }
     p[k].finish=time;
      printf("\npid at bt tat wt ft tat/bt\n");
     for(i=1;i<=n;i++)
     {
                      p[i].tat=p[i].wt+p[i].bt;
                      atat=atat+p[i].tat;
                      awt=awt+p[i].wt;
                      p[i].ratio=(float)p[i].tat/(float)p[i].bt;
                     
                      printf("\n%d  %d  %d  %d   %d  %d  %f",p[i].id,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].finish,p[i].ratio);
     }
     awt=awt/n;
     atat=atat/n;
     printf("\nawt=%f\natat=%f",awt,atat);
}

