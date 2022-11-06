i = int(input("Enter First Number : "))
j = int(input("Enter Second Number : "))
k = int(input("Enter Third Number : "))
if i>j&i>k:
    print("i is greater than j and k")
elif j>i&j>k:
    print("j is greater than i and k")
else:
    print("k is greater than i and j")