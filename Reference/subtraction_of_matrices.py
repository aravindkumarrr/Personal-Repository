rows=int(input("Enter the number of rows of the matrices: "))
cols=int(int(input("Enter the number of columns of the matrices: ")))
subtraction=[]
print("Enter the elements of matrix A: ")
A=[[int(input("Enter the elements: "))for i in range(rows)] for j in range(cols)]
print("Enter the elements of matrix B: ")
B=[[int(input("Enter the elements: "))for i in range(rows)] for j in range(cols)]

for i in range(rows):
    temp=[] 
    for j in range(cols):
        subt=A[i][j]-B[i][j]
        temp.append(subt)
    subtraction.append(temp)

print("The result of subtraction of matrices A-B is: ")
print(subtraction)
