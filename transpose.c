#include <stdio.h>

// Function to print a matrix
void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[][100], int rows, int cols) {
    int transposedMatrix[100][100];
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    
    // Copy the transposed matrix back to the original matrix
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            matrix[i][j] = transposedMatrix[i][j];
        }
    }
}

int main() {
    int rows, cols;
    
    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);
    
    int matrix[100][100];
    
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("Original Matrix:\n");
    printMatrix(matrix, rows, cols);
    
    // Transpose the matrix
    transposeMatrix(matrix, rows, cols);
    
    printf("Transposed Matrix:\n");
    printMatrix(matrix, cols, rows);

    return 0;
}
