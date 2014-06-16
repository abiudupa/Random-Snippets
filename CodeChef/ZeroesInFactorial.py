#Number of zeroes in factorial of a number
n=input()
n=int(n)
a=0
for i in range(0,n):
    b=int(input())
	s=0
    for j in range(1,15):
        s=s+int(a/(5**j))
    print(s)
        