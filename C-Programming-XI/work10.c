#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
int calcMinutes(int sh, int sm, int eh, int em);
int calcBaseFee(int minutes, int unitFee);
int calcVat(int baseFee);
int calcPayment(int baseFee, int vat);
void printTime(int minutes);

int main()
{
    run();
    return 0;
}

void run()
{
    int sh, sm;
    int eh, em;
    int unitFee;
    int minutes;
    int baseFee;
    int vat;
    int payment;

    printf("당구 사용 요금 계산 program\n\n");

    printf("시작 시간(시 분)을 입력하시오 => ");
    scanf("%d %d", &sh, &sm);

    printf("종료 시간(시 분)을 입력하시오 => ");
    scanf("%d %d", &eh, &em);

    printf("10분당 이용 요금(원)을 입력하시오 => ");
    scanf("%d", &unitFee);

    minutes = calcMinutes(sh, sm, eh, em);
    baseFee = calcBaseFee(minutes, unitFee);
    vat = calcVat(baseFee);
    payment = calcPayment(baseFee, vat);

    printf("\n전체 사용 시간: ");
    printTime(minutes);   

    printf("이용 금액(부가세 제외): %d원\n", baseFee);
    printf("부가가치세(10원 미만 절사): %d원\n", vat);
    printf("지불할 금액(100원 미만 절사): %d원\n", payment);
}

int calcMinutes(int sh, int sm, int eh, int em)
{
    int start = sh * 60 + sm;
    int end = eh * 60 + em;
    return end - start;
}

int calcBaseFee(int minutes, int unitFee)
{
    int block = minutes / 10;
    int remain = minutes % 10;

    int fee = block * unitFee;

   
    if (remain >= 5)
        fee += unitFee / 2;

    return fee;
}

int calcVat(int baseFee)
{
    int vat = baseFee * 10 / 100;
    vat = (vat / 10) * 10;
    return vat;
}

int calcPayment(int baseFee, int vat)
{
    int total = baseFee + vat;  

    
    total = (total / 100) * 100;
    return total;
}

void printTime(int minutes)
{
    int hour = minutes / 60;
    int min = minutes % 60;

    printf("%d분 (%d시간 %d분)\n", minutes, hour, min);
}
