#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
void makePascal(int arr[][20], int row);
void printPascal(int arr[][20], int row);

int main()
{
    run();
    return 0;
}

void run()
{
    int row;
    int pascal[20][20] = { 0 };   

   
    printf("출력할 행의 수 입력 => ");
    scanf("%d", &row);

    
    makePascal(pascal, row);

    
    printPascal(pascal, row);
}

void makePascal(int arr[][20], int row)
{
    
    arr[0][0] = 1;

   
    for (int i = 1; i < row; i++)
    {
        arr[i][0] = 1;   

        for (int j = 1; j <= i; j++)
        {
       
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
}

void printPascal(int arr[][20], int row)
{
    for (int i = 0; i < row; i++)
    {
        
        for (int s = 0; s < row - i - 1; s++)
        {
            printf(" ");
        }

       
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
