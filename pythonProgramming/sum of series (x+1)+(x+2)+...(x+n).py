x= int(input("Enter the value of x : "))
n= int(input("Enter the value Of n : "))
p=0
sum=0
for i in range (1,n+1):
    sum=sum+(x+(p+1))
    p=p+1
print (sum)