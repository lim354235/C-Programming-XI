#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
double getStandardWeight(double height);
double getBMI(double weight, double height);
double getFatPercent(double weight, double standard);
void printResult(double height, double weight, double standard, double bmi, double fat);

int main()
{
    run();  
    return 0;
}

void run()
{
    double height, weight;

    
    printf("신장(cm)을 입력하세요 => ");
    scanf("%lf", &height);

    printf("체중(kg)을 입력하세요 => ");
    scanf("%lf", &weight);

    
    double standard = getStandardWeight(height);

   
    double bmi = getBMI(weight, height);

    
    double fat = getFatPercent(weight, standard);

    
    printResult(height, weight, standard, bmi, fat);
}


double getStandardWeight(double height)
{
    return (height - 100.0) * 0.9;
}


double getBMI(double weight, double height)
{
    double h = height / 100.0;      
    return weight / (h * h);
}


double getFatPercent(double weight, double standard)
{
    return ((weight - standard) / standard) * 100.0;
}

void printResult(double height, double weight, double standard, double bmi, double fat)
{
    printf("\n판정 결과\n\n");

    
    printf("신장: %.1f cm\n", height);
    printf("체중: %.1f kg\n\n", weight);

   
    printf("표준체중(kg): %.1f\n", standard);
    printf("신체질량지수(BMI): %.1f\n", bmi);
    printf("비만도(%%): %.1f\n", fat);

   
    printf("\n신체질량지수 판정: ");
    if (bmi < 20)
        printf("저체중\n");
    else if (bmi <= 24)
        printf("정상 체중\n");
    else if (bmi <= 30)
        printf("과체중\n");
    else
        printf("병적 비만\n");

    
    printf("비만도 판정: ");
    if (fat < 10)
        printf("정상 체중\n");
    else if (fat <= 19)
        printf("과체중\n");
    else
        printf("비만\n");
}
