#include <stdio.h>

void inputMatrix(int matrix[10][10], int row, int col) {
    printf("Enter elements of the matrix (%dx%d):\n", row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int mat1[10][10], int mat2[10][10], int result[10][10], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[10][10], int transposed[10][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int mat1[10][10], mat2[10][10], result[10][10];
    int row1, col1, row2, col2;
    int choice;
    int continueProgram = 1;

    while (continueProgram) {
        printf("\n----- Matrix Operations Menu -----\n");
        printf("1. Addition of two matrices\n");
        printf("2. Subtraction of two matrices\n");
        printf("3. Multiplication of two matrices\n");
        printf("4. Transpose of a matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Addition
                printf("Enter the number of rows and columns of the matrices: ");
                scanf("%d%d", &row1, &col1);
                printf("Enter elements of first matrix:\n");
                inputMatrix(mat1, row1, col1);
                printf("Enter elements of second matrix:\n");
                inputMatrix(mat2, row1, col1);
                addMatrices(mat1, mat2, result, row1, col1);
                printf("Result of addition:\n");
                printMatrix(result, row1, col1);
                break;

            case 2: // Subtraction
                printf("Enter the number of rows and columns of the matrices: ");
                scanf("%d%d", &row1, &col1);
                printf("Enter elements of first matrix:\n");
                inputMatrix(mat1, row1, col1);
                printf("Enter elements of second matrix:\n");
                inputMatrix(mat2, row1, col1);
                subtractMatrices(mat1, mat2, result, row1, col1);
                printf("Result of subtraction:\n");
                printMatrix(result, row1, col1);
                break;

            case 3: // Multiplication
                printf("Enter rows and columns of first matrix: ");
                scanf("%d%d", &row1, &col1);
                printf("Enter rows and columns of second matrix: ");
                scanf("%d%d", &row2, &col2);

                if (col1 != row2) {
                    printf("Matrix multiplication not possible.\n");
                    break;
                }

                printf("Enter elements of first matrix:\n");
                inputMatrix(mat1, row1, col1);
                printf("Enter elements of second matrix:\n");
                inputMatrix(mat2, row2, col2);
                multiplyMatrices(mat1, mat2, result, row1, col1, col2);
                printf("Result of multiplication:\n");
                printMatrix(result, row1, col2);
                break;

            case 4: // Transpose
                printf("Enter rows and columns of the matrix: ");
                scanf("%d%d", &row1, &col1);
                printf("Enter elements of the matrix:\n");
                inputMatrix(mat1, row1, col1);
                transposeMatrix(mat1, result, row1, col1);
                printf("Transpose of the matrix:\n");
                printMatrix(result, col1, row1);
                break;

            case 5:
                continueProgram = 0;
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}
