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
    printTime(minutes);   // 시간+분 형식으로 출력

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

    // 남은 시간이 5분 이상이면 반값 추가, 5분 미만이면 추가 요금 없음
    if (remain >= 5)
        fee += unitFee / 2;

    return fee;
}

// 부가세 계산 (10% 부과, 10원 미만 절사)
int calcVat(int baseFee)
{
    int vat = baseFee * 10 / 100;
    vat = (vat / 10) * 10;
    return vat;
}

// 최종 지불 금액 계산 (100원 미만 절사)
int calcPayment(int baseFee, int vat)
{
    int total = baseFee + vat;  // 부가세 포함 금액

    // 100원 미만 절사 (일·십 원 자리 버림)
    total = (total / 100) * 100;
    return total;
}

// 사용 시간(분)을 "시간 + 분" 형식으로 출력
void printTime(int minutes)
{
    int hour = minutes / 60;
    int min = minutes % 60;

    printf("%d분 (%d시간 %d분)\n", minutes, hour, min);
}
