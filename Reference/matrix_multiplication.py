# Input dimensions of the matrices
rows_A = int(input("Enter the number of rows of Matrix A: "))
cols_A = int(input("Enter the number of columns of Matrix A: "))

rows_B = int(input("Enter the number of rows of Matrix B: "))
cols_B = int(input("Enter the number of columns of Matrix B: "))

# Validate if multiplication is possible
if cols_A != rows_B:
    print("Matrix multiplication not possible. Columns of A must equal rows of B.")
    exit()

# Input Matrix A
print("Matrix A: ")
A = [[int(input(f"Enter element at row {i+1}, column {j+1}: ")) for j in range(cols_A)] for i in range(rows_A)]

# Input Matrix B
print("Matrix B: ")
B = [[int(input(f"Enter element at row {i+1}, column {j+1}: ")) for j in range(cols_B)] for i in range(rows_B)]

# Initialize result matrix
result = [[0 for x in range(cols_B)] for y in range(rows_A)]

# Matrix multiplication logic
for i in range(rows_A):  # Loop through rows of A
    for j in range(cols_B):  # Loop through columns of B
        for k in range(cols_A):  # Loop through columns of A / rows of B
            result[i][j] += A[i][k] * B[k][j]

# Print Resultant Matrix
print("Resultant Matrix after multiplication:")
# To print row-wise: 
# for row in result:
#     print(row)

# To print as a list:
print(result)

