#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
int gcd(int x, int y);
int lcm(int x, int y, int g);

int main()
{
    run(); 
    return 0;
}

void run()
{
    int x, y;

    // 두 정수를 입력받음
    printf("입력할 두 정수 => ");
    scanf("%d %d", &x, &y);

    // 최대공약수 계산
    int g = gcd(x, y);

    // 최소공배수 계산 (x * y / gcd)
    int l = lcm(x, y, g);

    // 결과 출력
    printf("최대공약수 = %d\n", g);
    printf("최소공배수 = %d\n", l);
}

// 유클리드 호제법을 이용하여 최대공약수를 구하는 함수
int gcd(int x, int y)
{
    int r;

    // y가 0이 될 때까지 반복
    while (y != 0)
    {
        r = x % y;   // 나머지 계산
        x = y;       // 이전 y를 x로 이동
        y = r;       // 나머지를 y로 이동
    }

    return x;  // y=0일 때 x가 최대공약수
}

// 최소공배수 계산 함수: (x * y) / gcd
int lcm(int x, int y, int g)
{
    return x * y / g;
}
