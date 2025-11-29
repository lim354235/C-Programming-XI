#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 3  // 3x3 행렬 크기

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
    // 행렬 A 초기화
    int A[SIZE][SIZE] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // 행렬 B 초기화
    int B[SIZE][SIZE] = {
        {3, 6, 9},
        {2, 5, 8},
        {1, 4, 7}
    };

    // 결과를 저장할 행렬들
    int add[SIZE][SIZE];   // A + B
    int sub[SIZE][SIZE];   // A - B
    int mul[SIZE][SIZE];   // A * B

    // A, B 출력
    printMatrix(A, "matrix A");
    printMatrix(B, "matrix B");

    // A + B, A - B, A * B 계산
    addMatrix(A, B, add);
    subMatrix(A, B, sub);
    mulMatrix(A, B, mul);

    // 결과 출력
    printMatrix(add, "matrix A + matrix B");
    printMatrix(sub, "matrix A - matrix B");
    printMatrix(mul, "matrix A * matrix B");
}

void printMatrix(int m[SIZE][SIZE], const char* title)
{
    // 행렬 제목 출력
    printf("\n%s:\n", title);

    // 행렬의 각 원소를 행 단위로 출력
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }
}

// 행렬 덧셈: result = a + b
void addMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)          // 각 행에 대해
    {
        for (int j = 0; j < SIZE; j++)      // 각 열에 대해
        {
            result[i][j] = a[i][j] + b[i][j];  // 같은 위치 원소끼리 더함
        }
    }
}

// 행렬 뺄셈: result = a - b
void subMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = a[i][j] - b[i][j];  // 같은 위치 원소끼리 뺌
        }
    }
}

// 행렬 곱셈: result = a * b
void mulMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE])
{
    // 먼저 결과 행렬을 0으로 초기화
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            result[i][j] = 0;
        }
    }

    // 행렬 곱셈 계산
    for (int i = 0; i < SIZE; i++)              // A의 i번째 행
    {
        for (int j = 0; j < SIZE; j++)          // B의 j번째 열
        {
            for (int k = 0; k < SIZE; k++)      // A의 열, B의 행을 따라 곱셈·덧셈
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
