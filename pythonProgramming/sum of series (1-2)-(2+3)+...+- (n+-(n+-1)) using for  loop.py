i=1
sum=0
n = int(input("Enter the value of n : "))
sign=1
sign2=-1
for i in range (1,n+1):
    sum =sum+sign*(i+sign2*(i+1))
    i=i+1
    sign=sign*(-1)
    sign2=sign2*(-1)
print ("sum = ",sum)