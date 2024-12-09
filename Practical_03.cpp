#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
void matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result) {
    int rows = A.size();
    int cols = A[0].size();
    result.resize(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result) {
    int rows = A.size();
    int cols = A[0].size();
    result.resize(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices
bool matrixMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    if (colsA != rowsB) {
        cout << "Matrix multiplication not possible! Number of columns in A must equal number of rows in B." << endl;
        return false;
    }

    result.resize(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return true;
}

// Function to transpose a matrix
void transposeMatrix(const vector<vector<int>>& A, vector<vector<int>>& result) {
    int rows = A.size();
    int cols = A[0].size();
    result.resize(cols, vector<int>(rows, 0));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Input for first matrix
    cout << "Enter the number of rows and columns for Matrix A: ";
    cin >> rowsA >> colsA;
    vector<vector<int>> A(rowsA, vector<int>(colsA));
    cout << "Enter elements for Matrix A:" << endl;
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            cin >> A[i][j];
        }
    }

    // Input for second matrix
    cout << "Enter the number of rows and columns for Matrix B: ";
    cin >> rowsB >> colsB;
    vector<vector<int>> B(rowsB, vector<int>(colsB));
    cout << "Enter elements for Matrix B:" << endl;
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            cin >> B[i][j];
        }
    }

    int choice;
    bool continueProgram = true;

    while (continueProgram) {
        cout << "\n------ MENU ------" << endl;
        cout << "1. Add two matrices" << endl;
        cout << "2. Subtract two matrices" << endl;
        cout << "3. Multiply two matrices" << endl;
        cout << "4. Transpose a matrix" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        vector<vector<int>> result;

        switch (choice) {
            case 1:
                if (rowsA == rowsB && colsA == colsB) {
                    matrixAddition(A, B, result);
                    cout << "Matrix A + Matrix B:" << endl;
                    displayMatrix(result);
                } else {
                    cout << "Matrix addition not possible! Dimensions must match." << endl;
                }
                break;

            case 2:
                if (rowsA == rowsB && colsA == colsB) {
                    matrixSubtraction(A, B, result);
                    cout << "Matrix A - Matrix B:" << endl;
                    displayMatrix(result);
                } else {
                    cout << "Matrix subtraction not possible! Dimensions must match." << endl;
                }
                break;

            case 3:
                if (matrixMultiplication(A, B, result)) {
                    cout << "Matrix A * Matrix B:" << endl;
                    displayMatrix(result);
                }
                break;

            case 4:
                cout << "Transpose of Matrix A:" << endl;
                transposeMatrix(A, result);
                displayMatrix(result);
                break;

            case 5:
                continueProgram = false;
                cout << "Thanks for using this program!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }

    return 0;
}
