#Finds number of holes in letters
n=int(input())
for i in range(0,n):
    a=input()
    a=str(a)
    c=0
    for j in range(0,len(a)):
        w=a[j]
        if(w=="A" or w=="D" or w=="O" or w=="P" or w=="Q" or w=="R"):
            c=c+1
        elif(w=='B'):
            c=c+2
        else:
            c=c+0
    print(c)