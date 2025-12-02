#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 3  

void run();
void printMatrix(int m[SIZE][SIZE], const char* title);
void addMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]);
void subMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]);
void mulMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]);

int main()
{
    run();
    return 0;
}

void run()
{
    int A[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };


    int B[SIZE][SIZE] = {
        {3, 6, 9},
        {2, 5, 8},
        {1, 4, 7}
    };

    int add[SIZE][SIZE];   
    int sub[SIZE][SIZE];   
    int mul[SIZE][SIZE];   

    printMatrix(A, "matrix A");
    printMatrix(B, "matrix B");

    addMatrix(A, B, add);
    subMatrix(A, B, sub);
    mulMatrix(A, B, mul);

    printMatrix(add, "matrix A + matrix B");
    printMatrix(sub, "matrix A - matrix B");
    printMatrix(mul, "matrix A * matrix B");
}

void printMatrix(int m[SIZE][SIZE], const char* title)
{
    printf("\n%s:\n", title);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)         
    {
        for (int j = 0; j < SIZE; j++)     
        {
            result[i][j] = a[i][j] + b[i][j]; 
        }
    }
}

void subMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = a[i][j] - b[i][j]; 
        }
    }
}

void mulMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++)            
    {
        for (int j = 0; j < SIZE; j++)         
        {
            for (int k = 0; k < SIZE; k++)     
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
