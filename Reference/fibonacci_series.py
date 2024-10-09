n=int(input("Enter the number of terms: "))
a = 0
b = 1
next = b  
count = 1

while count <= n:
    print(next, end=" ")
    count += 1
    a=b
    b=next
    next = a + b
print()
