#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
void printSequence(int n);

int main()
{
    run();
    return 0;
}

void run()
{
    int n;
    printf("출력할 항의 개수 입력 => ");
    scanf("%d", &n);

    printSequence(n);
}

void printSequence(int n)
{
    int a = 1;
    printf("%d ", a);

    for (int i = 2; i <= n; i++)
    {
        a = a + i;
        printf("%d ", a);
    }

    printf("\n");
}
