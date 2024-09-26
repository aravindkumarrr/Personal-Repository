rows=int(input("Enter the number of rows of the matrix: "))
cols=int(input("Enter the number of columns of the matrix: "))
matrix=[[int(input("Enter the element: "))for x in range(rows)] for y in range(cols)]
transpose=[]
for i in range(rows):
    var=0
    temp=[]
    for j in range(cols):
        var=matrix[j][i]
        temp.append(var)
    transpose.append(temp)
print(transpose)
