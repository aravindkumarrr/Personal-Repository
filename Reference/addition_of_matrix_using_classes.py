class matrix:
    def __init__(self, matrix_name,matrix_rows,matrix_cols):
        self.name=matrix_name
        self.rows=matrix_rows
        self.cols=matrix_cols
        self.mat=self.newmatrix()
        #name of the variables are after the dot.
    
    def newmatrix(self):
        #self.attribute associates to whatever value that has been assigned to that object during initialization
        name=self.name
        rows=self.rows
        cols=self.cols
        mat=[]
        print(f"Enter the elements of matrix {name} (row-wise): ")
        mat=[[int(input(f"Enter the element {i+1} of row {j+1}: ")) for i in range(rows)] for j in range(cols)]
        #Use the arguments to iterate respectively the number of rows(for row-wise input)
        return mat

A=matrix("A",2,2)
B=matrix("B",2,2)

addition=[]
for i in range(A.rows):
    temp=[]
    for j in range(A.cols):
        sum=A.mat[i][j]+B.mat[i][j]
        temp.append(sum)
    addition.append(temp)
print(addition)
