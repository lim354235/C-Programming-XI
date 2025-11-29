#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void run();
double round_at(double x, long n);

int main()
{
    run(); 
    return 0;
}

void run()
{
    double x;   // 입력 실수
    long n;     // 반올림할 소수 이하 자리수
    double result;

    // 실수 입력
    printf("임의의 실수 입력 => ");
    scanf("%lf", &x);

    // 반올림할 자릿수 입력 (소수점 이하 자리 수)
    printf("반올림할 자릿수 입력 => ");
    scanf("%ld", &n);

    // n번째 소수 이하 자리에서 반올림 수행
    result = round_at(x, n);

    // 결과 출력
    printf("입력한 실수: %.6f\n", x);
    printf("소수 이하 %ld자리 반올림 결과 : %.6f\n", n, result);
}

double round_at(double x, long n)
{
    // 10^n 값을 계산 (소수점 n자리만큼 왼쪽으로 당길 배수)
    double k = pow(10.0, (double)n);

    // 소수점 아래 n자리까지를 정수부로 가져오기 위해 x * k
    double shifted = x * k;

    // 0.5를 더한 뒤 long으로 형변환하여 반올림 처리
    long rounded = (long)(shifted + 0.5);

    // 다시 10^n으로 나누어 소수점 위치를 원래대로 돌림
    return rounded / k;
}
