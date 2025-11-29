#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
int getTaxRate(int cc);
double getDiscountRate(int years);
int calcCarTax(int cc, int taxRate, double discount);
void printResult(int cc, int years, int taxRate, double discount, int finalTax);

int main()
{
    run();  
    return 0;
}

void run()
{
    int cc;     // 자동차 배기량
    int years;  // 구입 후 경과년도

    int taxRate;       // cc당 세율
    double discount;   // 경과년도 할인율
    int carTax;        // 최종 세금

    printf("승용차 세금 계산 program\n\n");

    // 사용자 입력
    printf("승용차의 배기량(cc)을 입력하시오 => ");
    scanf("%d", &cc);

    printf("구입 후 경과년수를 입력하시오 => ");
    scanf("%d", &years);

    // 배기량 세율 계산
    taxRate = getTaxRate(cc);

    // 경과년도 할인율 계산
    discount = getDiscountRate(years);

    // 최종 세금 계산
    carTax = calcCarTax(cc, taxRate, discount);

    // 결과 출력
    printResult(cc, years, taxRate, discount, carTax);
}

// 배기량에 따라 세율을 반환하는 함수
int getTaxRate(int cc)
{
    if (cc <= 800)
        return 104;
    else if (cc <= 1000)
        return 130;
    else if (cc <= 1600)
        return 182;
    else if (cc <= 2000)
        return 260;
    else if (cc <= 2500)
        return 286;
    else
        return 286;
}

// 경과년수에 따라 할인율을 반환하는 함수
double getDiscountRate(int years)
{
    if (years < 3) return 1.00;    // 100%
    else if (years == 3) return 1.00;
    else if (years == 4) return 0.90;
    else if (years == 5) return 0.85;
    else if (years == 6) return 0.80;
    else if (years == 7) return 0.75;
    else if (years == 8) return 0.70;
    else if (years == 9) return 0.65;
    else if (years == 10) return 0.60;
    else if (years == 11) return 0.55;
    else return 0.50;             // 12년 이상
}

// 최종 자동차세 계산 함수
int calcCarTax(int cc, int taxRate, double discount)
{
    // cc × 세율 × 할인율
    double tax = cc * taxRate * discount;

    return (int)tax;   // 원 단위 절사
}

// 결과 출력 함수
void printResult(int cc, int years, int taxRate, double discount, int finalTax)
{
    printf("\n배기량  : %d cc\n", cc);
    printf("경과년도: %d 년\n", years);
    printf("세율    : %d 원/cc\n", taxRate);

    printf("할인율  : %.0f %%\n", discount * 100);
    printf("최종 세금: %d 원\n", finalTax);
}
