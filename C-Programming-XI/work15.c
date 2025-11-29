#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
double toCentimeter(double value, int unit);
void convertAll(double cm, double result[]);
void printMenu();
void printResult(double result[]);

int main()
{
    run();
    return 0;
}

void run()
{
    double value;
    int unit;
    double cm;
    double result[10];   // 10개 단위 변환 결과

    printf("도량형 환산 프로그램\n\n");

    printf("환산값을 입력 : ");
    scanf("%lf", &value);

    printMenu();

    printf("단위번호 선택 : ");
    scanf("%d", &unit);

    cm = toCentimeter(value, unit);
    convertAll(cm, result);

    printf("\n단위변환 결과\n\n");
    printResult(result);
}

/* 단위별 메뉴 출력 */
void printMenu()
{
    printf("단위번호\n");
    printf("0:센티미터    1:미터      2:킬로미터\n");
    printf("3:인치        4:피트      5:야드\n");
    printf("6:마일        7:자        8:간\n");
}

/* 선택된 단위를 센티미터로 환산 */
double toCentimeter(double value, int unit)
{
    double cm = 0;

    switch (unit)
    {
    case 0: cm = value; break;                 // cm
    case 1: cm = value * 100; break;           // m
    case 2: cm = value * 100000; break;        // km
    case 3: cm = value * 2.54; break;          // inch
    case 4: cm = value * 30.48; break;         // ft
    case 5: cm = value * 91.44; break;         // yard
    case 6: cm = value * 160934; break;        // mile
    case 7: cm = value * 30.303; break;        // 자
    case 8: cm = value * 181.818; break;       // 간
    default: cm = 0;
    }

    return cm;
}

/* cm 기반으로 10개 단위를 모두 계산 */
void convertAll(double cm, double result[])
{
    result[0] = cm;                   // 센티미터
    result[1] = cm / 100.0;           // 미터
    result[2] = cm / 100000.0;        // 킬로미터
    result[3] = cm / 2.54;            // 인치
    result[4] = cm / 30.48;           // 피트
    result[5] = cm / 91.44;           // 야드
    result[6] = cm / 160934.0;        // 마일
    result[7] = cm / 30.303;          // 자
    result[8] = cm / 181.818;         // 간
    result[9] = cm / 392727.0;        // 리
}

/* 결과 출력 */
void printResult(double result[])
{
    printf("센티미터 : %10.3f\n", result[0]);
    printf("미터     : %10.3f\n", result[1]);
    printf("킬로미터 : %10.6f\n", result[2]);
    printf("인치     : %10.3f\n", result[3]);
    printf("피트     : %10.3f\n", result[4]);
    printf("야드     : %10.3f\n", result[5]);
    printf("마일     : %10.6f\n", result[6]);
    printf("자(척)   : %10.3f\n", result[7]);
    printf("간       : %10.3f\n", result[8]);
    printf("리       : %10.6f\n", result[9]);
}
