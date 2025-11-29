#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 함수 원형 선언
void startProgram();
void printByRecurrence(int n);
void printByGeneral(int n);

int main()
{
    startProgram();
    return 0;
}

void startProgram()
{
    int n;

    printf("출력할 항의 개수: ");
    scanf("%d", &n);

    printf("\n점화식\n");
    printByRecurrence(n);

    printf("\n일반항\n");
    printByGeneral(n);
}

// --------------------------
// 점화식 : a1 = 1, aₙ = aₙ₋₁ × 2
// --------------------------
void printByRecurrence(int n)
{
    int a = 1;

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a);
        a = a * 2;   // 공비 2
    }
    printf("\n");
}

// --------------------------
// 일반항 : aₙ = 2^(n-1)
// --------------------------
void printByGeneral(int n)
{
    int a = 1;

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a);
        a = a * 2;   // 2^(n-1) 계산
    }
    printf("\n");
}
