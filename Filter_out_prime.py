a=int(input("Enter lower limit: "))
b=int(input("Enter upper limit: "))
for i in range(a,b):
    temp=i//2
    for j in range(2,temp+1):
        if i%j==0:
            print(i)
            break
