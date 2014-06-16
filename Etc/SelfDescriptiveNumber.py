import sys
import math
def sum(n):
   r = 0
   while n:
       r, n = r + n % 10, n / 10
   return r
def round1(x):
     return int(math.ceil(x / 100000000.0)) * 100000000
def round2(x):
     return int(math.ceil(x / 10000000.0)) * 10000000
def round3(x):
     return int(math.ceil(x / 1000000.0)) * 1000000
def round4(x):
     return int(math.ceil(x / 100000.0)) * 100000
def round5(x):
     return int(math.ceil(x / 10000.0)) * 10000
def round6(x):
     return int(math.ceil(x / 1000.0)) * 1000

i=1000000000
while(i<9999999999):
    a=[0,0,0,0,0,0,0,0,0,0]
    y=[]
    m=''    
    if(sum(i)==10):
       b=str(i)
       for j in range(0,10):
           for k in range(0,10):
               if(b[j]==str(k)):
                  a[k]=a[k]+1
       for j in range(0,10):
           m=str(m)+str(a[j])
       if(b==m):
           print(m)
           y.append(m)
    if(sum(i)>10):
            f=0
            m=str(i)
            if(m[1]>'3'):
                f=1
                i=int(m)
                i=round1(i)
            if(m[2]>'2'):
                f=1
                i=int(m)
                i=round2(i)
            if(m[3]>'1'):
                f=1
                i=int(m)
                i=round3(i)
            if(m[4]>'1'):
                f=1
                i=int(m)
                i=round4(i)
            if(m[5]>'1'):
                f=1
                i=int(m)
                i=round5(i)
            if(m[6]>'1'):
                f=1
                i=int(m)
                i=round6(i)   
            if(f==0):
                i=int(m)
    i=i+1    
