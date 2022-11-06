list1=[]
for i in range (0,3):
    print ("Enter First Row's Element # : ",i+1)
    list1.append(input())
list2=[]
for i in range (0,3):
    print("Enter Second Row's Element # : ",i+1)
    list2.append(input())
list3=[]
for i in range (0,3):
    print("Enter third Row's Element # : ",i+1)
    list3.append(input())
list4=[list1,list2,list3]
print("Your 3*3 list is as : ")
print ("\n",list4[0],"\n",list4[1],"\n",list4[2])