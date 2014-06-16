//Compute fibonacci using multi threads
#include<stdio.h>
#include<conio.h>
#include<omp.h>
#include<stdlib.h>

int temp;

int fib(int n)
{
    int x,y;
    if(n<2)
       return n;
    else
    {
        x=fib(n-1);
        y=fib(n-2);
        return (x+y);
    }
}

int rno()
{
    temp=rand();
    temp=temp%5;
    return temp;
}

int main()
{
    int tid,i=0,j,n,t,f[25]={0};
    printf("enter n : ");
    scanf("%d",&n);
    omp_set_num_threads(2);
    #pragma omp parallel
    {
            printf("no of threads:%d",omp_get_num_threads());
            #pragma omp for private(tid,t,f);
           
            for(j=1;j<=n;j++)
            {
                            printf("\n%d\n",j);
                             t=rno();
                             #pragma omp critical
                             {
                                     for(i=1;i<=t;i++)
                                      f[i]=fib(i);
                                     printf("\nthe no value is %d",t);
                                     for(i=1;i<=t;i++)
                                      printf("\t%d",f[i]);
                             }
            }
    }
getch();
} 
