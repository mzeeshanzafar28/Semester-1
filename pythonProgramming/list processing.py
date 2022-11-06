list1=[]
n =int (input("Enter number of elements in list : "))
print("Enter elements of list : ")
for i in range (n):
    list1.append(int(input()))
print ("your list is as : ",list1)
high=list1[0]
loc=0
for i in range (n):
    if list1[i] > high:
        high=list1[i]
        loc = i
print ("Highest value = ",high,"with index ",loc)