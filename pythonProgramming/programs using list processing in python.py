list1=[]
n = int (input ("Enter number of Elements : "))
for i in range (n):
    print ("Enter ",i+1,"th element : ")
    list1.append(int(input()))
print ("list1 = ",list1)
high = list1[0]
loc =0
for i in range (n):
    if list1[i]>high:
        high=list1[i]
        loc=i
print ("\nhighest value member = ",high,"\nlocation = ",loc)