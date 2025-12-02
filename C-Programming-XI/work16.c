#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 

#define PI 3.14159265358979323846 
double line_length();
double deg2rad(double deg);

int main() {

    line_length();
    return 0;
}


double line_length() {
    double A, B, c;

    printf("a의 각도(A)를 입력하세요: ");
    scanf("%lf", &A);
    printf("b의 각도(B)를 입력하세요: ");
    scanf("%lf", &B);
    printf("선분 ab(=c)의 길이를 입력하세요: ");
    scanf("%lf", &c);

    double C = 180.0 - (A + B);  

    double a = c * sin(deg2rad(A)) / sin(deg2rad(C));   

    printf("선분 a(BC)의 길이: %lf\n", a);

    return a;
}

double deg2rad(double deg) {
    return deg * PI / 180.0;  
}