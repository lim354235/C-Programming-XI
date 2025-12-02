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
    double x;   
    long n;     
    double result;

    printf("임의의 실수 입력 => ");
    scanf("%lf", &x);

    printf("반올림할 자릿수 입력 => ");
    scanf("%ld", &n);

    result = round_at(x, n);

    printf("입력한 실수: %.6f\n", x);
    printf("소수 이하 %ld자리 반올림 결과 : %.6f\n", n, result);
}

double round_at(double x, long n)
{
    double k = pow(10.0, (double)n);

    double shifted = x * k;

    long rounded = (long)(shifted + 0.5);

    return rounded / k;
}
