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
    int pascal[20][20] = { 0 };   // 최대 20행까지 저장 가능

    // 출력할 파스칼 삼각형의 행 개수 입력
    printf("출력할 행의 수 입력 => ");
    scanf("%d", &row);

    // 파스칼 삼각형 생성
    makePascal(pascal, row);

    // 출력
    printPascal(pascal, row);
}

void makePascal(int arr[][20], int row)
{
    // 첫 번째 값을 1로 초기화
    arr[0][0] = 1;

    // 각 행을 1개의 1로 채우고 나머지는 위의 두 수의 합으로 계산
    for (int i = 1; i < row; i++)
    {
        arr[i][0] = 1;   // 각 행의 첫 번째 값은 1

        for (int j = 1; j <= i; j++)
        {
            // 위의 두 값의 합으로 현재 위치 값을 채움
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
}

void printPascal(int arr[][20], int row)
{
    for (int i = 0; i < row; i++)
    {
        // 삼각형 형태를 맞추기 위해 앞에 공백 출력
        for (int s = 0; s < row - i - 1; s++)
        {
            printf(" ");
        }

        // i행의 0~i번째 값 출력
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
