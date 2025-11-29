#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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

    printf("출력할 항의 개수 n을 입력하세요: ");
    scanf("%d", &n);

    printf("\n점화식\n");
    printByRecurrence(n);

    printf("\n일반항\n");
    printByGeneral(n);
}

// --------------------------
// 점화식: a1=1, a_n = a_(n-1) + 2
// --------------------------
void printByRecurrence(int n)
{
    int a = 1;

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a);
        a += 2;
    }
    printf("\n");
}

// --------------------------
// 일반항: a_n = 2n - 1
// --------------------------
void printByGeneral(int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", 2 * i - 1);
    }
    printf("\n");
}
