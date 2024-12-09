def input_matrix(rows, cols):
    """Function to input a matrix from the user."""
    matrix = []
    print(f"Enter the elements of the matrix ({rows}x{cols}):")
    for i in range(rows):
        row = list(map(int, input(f"Enter row {i + 1}: ").split()))
        if len(row) != cols:
            print(f"Row {i + 1} should have exactly {cols} elements.")
            return None
        matrix.append(row)
    return matrix

def display_matrix(matrix):
    """Function to display a matrix."""
    for row in matrix:
        print(" ".join(map(str, row)))

def add_matrices(matrix1, matrix2):
    """Function to add two matrices."""
    return [[matrix1[i][j] + matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

def subtract_matrices(matrix1, matrix2):
    """Function to subtract two matrices."""
    return [[matrix1[i][j] - matrix2[i][j] for j in range(len(matrix1[0]))] for i in range(len(matrix1))]

def multiply_matrices(matrix1, matrix2):
    """Function to multiply two matrices."""
    result = [[0 for _ in range(len(matrix2[0]))] for _ in range(len(matrix1))]
    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]
    return result

def transpose_matrix(matrix):
    """Function to transpose a matrix."""
    return [[matrix[j][i] for j in range(len(matrix))] for i in range(len(matrix[0]))]

# Main function to perform operations
def main():
    print("Matrix Operations Program")
    print("1. Addition of Two Matrices")
    print("2. Subtraction of Two Matrices")
    print("3. Multiplication of Two Matrices")
    print("4. Transpose of a Matrix")
    
    choice = int(input("Choose an operation (1-4): "))

    if choice == 1 or choice == 2:
        rows = int(input("Enter number of rows: "))
        cols = int(input("Enter number of columns: "))
        print("\nMatrix 1:")
        matrix1 = input_matrix(rows, cols)
        print("\nMatrix 2:")
        matrix2 = input_matrix(rows, cols)

        if matrix1 and matrix2:
            if choice == 1:
                print("\nAddition of the two matrices:")
                result = add_matrices(matrix1, matrix2)
            else:
                print("\nSubtraction of the two matrices:")
                result = subtract_matrices(matrix1, matrix2)
            display_matrix(result)

    elif choice == 3:
        rows1 = int(input("Enter number of rows for Matrix 1: "))
        cols1 = int(input("Enter number of columns for Matrix 1: "))
        print("\nMatrix 1:")
        matrix1 = input_matrix(rows1, cols1)

        rows2 = int(input("Enter number of rows for Matrix 2: "))
        cols2 = int(input("Enter number of columns for Matrix 2: "))
        print("\nMatrix 2:")
        matrix2 = input_matrix(rows2, cols2)

        if matrix1 and matrix2:
            if cols1 == rows2:
                print("\nMultiplication of the two matrices:")
                result = multiply_matrices(matrix1, matrix2)
                display_matrix(result)
            else:
                print("Error: Number of columns in Matrix 1 must equal number of rows in Matrix 2 for multiplication.")

    elif choice == 4:
        rows = int(input("Enter number of rows for the matrix: "))
        cols = int(input("Enter number of columns for the matrix: "))
        print("\nMatrix:")
        matrix = input_matrix(rows, cols)

        if matrix:
            print("\nTranspose of the matrix:")
            result = transpose_matrix(matrix)
            display_matrix(result)

    else:
        print("Invalid choice! Please select an option between 1 and 4.")

# Run the main function
main()
