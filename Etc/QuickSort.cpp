//QuickSort algorithm
#include<stdio.h>
#include<conio.h>

int split(int a[],int l,int h)
{
    int i,p,q,t;
    p=l+1;
    q=h;
    i=a[l];
    while(q>=p)
    {
               while(a[p]<i)
                p++;
               while(a[p]>i)
                q--;
               if(q>p)
               {
                      t=a[p];
                      a[p]=a[q];
                      a[q]=t;
               }
     }
     t=a[l];
     a[l]=a[q];
     a[q]=t;
     return q;
}
void quick(int a[],int l,int h)
{
     int i;
     if(h>l)
     {
            i=split(a,l,h);
            quick(a,l,i-1);
            quick(a,i+1,h);
     }
}
int main()
{
    int a[10],n,i;
    scanf("%d",&n);
    printf("\ne :");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quick(a,0,n-1);
    for(i=0;i<n;i++)
    printf("\n%d",a[i]);
    getch();
}
