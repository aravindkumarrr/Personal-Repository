def fac(x): 
    temp=1
    i=1
    while(i<=x):
        temp=temp*i
        i+=1
    return temp

y = int(input("Enter the number: "))

print(fac(y))
