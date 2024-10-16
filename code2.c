/*
* Name: Megan Svoren
* Class: EECS 348
* Lab Time: Wednesday at 1:00pm
* Lab Number: Lab05
* Purpose: Creates two matrices and creates functions to add matrices, multiply matrices, and transpose matrices.
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

// Adds the inputted matrices together
int **add_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
    int **sums_matrix;

    // Allocates space for the matrix and adds each entry together
    sums_matrix = malloc(sizeof(int *) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        sums_matrix[i] = malloc(sizeof(int) * SIZE);
        for (int j = 0; j < SIZE; j++)
        {
            sums_matrix[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return sums_matrix;
}

// Multiplies the inputted matrices together using proper matrix multiplication
int **multiply_matrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE])
{
    // Allocates space for the matrix and initializes all entries of the result matrix to 0
    int **multiplied_matrices;
    multiplied_matrices = malloc(sizeof(int *) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        multiplied_matrices[i] = malloc(sizeof(int) * SIZE);
        for (int j = 0; j < SIZE; j++)
        {
            multiplied_matrices[i][j] = 0;
        }
    }

    // Multiplies the matrices
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                multiplied_matrices[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return multiplied_matrices;
}

// Transposes the inputted matrix (swaps the rows and columns)
int **transpose_matrix(int matrix[SIZE][SIZE])
{
    int **transposed_matrix;

    // Allocates space for the matrix and transposes it
    transposed_matrix = malloc(sizeof(int *) * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        transposed_matrix[i] = malloc(sizeof(int) * SIZE);
        for (int j = 0; j < SIZE; j++)
        {
            transposed_matrix[i][j] = matrix[j][i];
        }
    }

    return transposed_matrix;

}

// Takes an array in and prints it in a user-friendly format
void print_matrix(int **matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function. Creates two matrices, then adds them, multiplies them, and transposes each one and prints out the result of each operation
int main()
{
    int m1[SIZE][SIZE] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
    {25, 24, 23, 22, 21},
    {20, 19, 18, 17, 16},
    {15, 14, 13, 12, 11},
    {10, 9, 8, 7, 6},
    {5, 4, 3, 2, 1}
    };

    
    // Adds the matrices
    int **summed_matrices;
    summed_matrices = add_matrices(m1, m2);
    printf("\nMatrices m1 and m2 summed:\n");
    print_matrix(summed_matrices);
    
    // Frees memory from summed matrices
    for (int i = 0; i < SIZE; i++)
    {
        free(summed_matrices[i]);
    }
    free(summed_matrices);


    
    // Multiplies the matrices
    int **multiplied_matrices;
    multiplied_matrices = multiply_matrices(m1, m2);
    printf("\nMatrices m1 and m2 multiplied:\n");
    print_matrix(multiplied_matrices);
    
    // Frees memory from multiplied matrices
    for (int i = 0; i < SIZE; i++)
    {
        free(multiplied_matrices[i]);
    }
    free(multiplied_matrices);



    // Transposes m1
    int **transposed_matrix1;
    transposed_matrix1 = transpose_matrix(m1);
    printf("\nMatrix m1 transposed:\n");
    print_matrix(transposed_matrix1);

    // Frees memory from transposed matrix m1
    for (int i = 0; i < SIZE; i++)
    {
        free(transposed_matrix1[i]);
    }
    free(transposed_matrix1);



    // Transposes m2
    int **transposed_matrix2;
    transposed_matrix2 = transpose_matrix(m2);
    printf("\nMatrix m2 transposed:\n");
    print_matrix(transposed_matrix2);

    // Frees memory from transposed matrix m2
    for (int i = 0; i < SIZE; i++)
    {
        free(transposed_matrix2[i]);
    }
    free(transposed_matrix2);
    

    

    return 0;
}