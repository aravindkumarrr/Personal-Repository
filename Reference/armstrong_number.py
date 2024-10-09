n=input("Enter the number to be checked: ")
num=n
num=int(num)
leng=len(n)

sum = 0
temp = num

while temp > 0:
 digit = temp % 10
 sum += digit ** leng
 temp //= 10

if num == sum:
 print(num,"is an Armstrong number")
else:
 print(num,"is not an Armstrong number")
