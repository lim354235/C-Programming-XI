#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
double calcAvg(double total, int family);
int calcWaterHigh(double avg);
int calcWaterLow(double avg);
int calcBurden(double avg, int family);

int main()
{
    run();
    return 0;
}

void run()
{
    double totalUse;    // 총 사용량(m³)
    int family;         // 세대수
    double avg;         // 세대당 평균 사용량
    int highFee;        // 상수도 요금
    int lowFee;         // 하수도 요금
    int burden;         // 물이용부담금
    int total;          // 최종 청구요금

    printf("수도요금 청구서 출력 program\n\n");

    printf("수도사용량(m3)을 입력하시오 Enter> ");
    scanf("%lf", &totalUse);

    printf("세대수를 입력하시오 Enter> ");
    scanf("%d", &family);

    avg = calcAvg(totalUse, family);
    highFee = calcWaterHigh(avg) * family;
    lowFee = calcWaterLow(avg) * family;
    burden = calcBurden(avg, family);
    total = highFee + lowFee + burden;

    printf("\n수도요금  청구서\n\n");
    printf("총사용량   : %.1f㎥\n", totalUse);
    printf("세대수     : %d세대\n", family);
    printf("평균사용량 : %.1f㎥\n\n", avg);

    printf("상수도 요금 : %d원\n", highFee);
    printf("하수도 요금 : %d원\n", lowFee);
    printf("물이용부담금 : %d원\n\n", burden);

    printf("청구요금   : %d원\n", total);
}

/* 세대당 평균 사용량 계산 */
double calcAvg(double total, int family)
{
    return total / family;
}

/* 상수도 요금 계산 (누진 구간 적용) */
int calcWaterHigh(double avg)
{
    int fee = 0;

    if (avg <= 10)
        fee = avg * 190;
    else if (avg <= 30)
        fee = 10 * 190 + (avg - 10) * 320;
    else if (avg <= 50)
        fee = 10 * 190 + 20 * 320 + (avg - 30) * 510;
    else
        fee = 10 * 190 + 20 * 320 + 20 * 510 + (avg - 50) * 570;

    return fee;
}

/* 하수도 요금 계산 */
int calcWaterLow(double avg)
{
    int fee = 0;

    if (avg <= 30)
        fee = avg * 160;
    else if (avg <= 50)
        fee = 30 * 160 + (avg - 30) * 380;
    else
        fee = 30 * 160 + 20 * 380 + (avg - 50) * 580;

    return fee;
}

/* 물이용부담금 (1m³당 130원) */
int calcBurden(double avg, int family)
{
    int fee = avg * 130 * family;
    return fee;
}
