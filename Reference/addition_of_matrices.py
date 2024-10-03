rows=int(input("Enter the number of rows of the matrices: "))
cols=int(input("Enter the number of columns of the matrices: "))
print("Enter the elements of matrix A: ")
addition=[]
A=[[int(input("Enter the elements: ")) for i in range(rows)] for j in range(cols)]
print("Enter the elements of matrix B: ")
B=[[int(input("Enter the elements: ")) for i in range(rows)] for j in range(cols)]

for i in range(rows):
    temp=[]
    for j in range(cols):
        sum=A[i][j]+B[i][j]
        temp.append(sum)
    addition.append(temp)

print("Addition of the two matrices is: ", addition)
