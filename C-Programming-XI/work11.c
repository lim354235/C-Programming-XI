#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
int calcBasicPay(int grade);
int calcBaseDeduction(int spouse, int child);
int calcTaxStandard(int basicPay, int baseDeduction);
int calcTax(int taxStandard);
int calcSalary(int basicPay, int tax);
void printResult(int grade, int basicPay, int baseDeduction, int taxStd, int tax, int salary);

int main()
{
    run();    
    return 0;
}

void run()
{
    int grade;      // 호봉
    int spouse;     // 배우자 유무 (1=있음, 0=없음)
    int child;      // 부양가족 수

    while (1)
    {
        printf("봉급계산 program\n");
        printf("호봉수, 배우자 유무(1,0), 부양가족 수를 입력하세요\n");
        printf("호봉이 0이면 종료됩니다.\n");
        printf("자료입력 => ");

        scanf("%d", &grade);

        if (grade == 0)   // 종료 조건
            break;

        scanf("%d %d", &spouse, &child);

        // 본봉 계산
        int basicPay = calcBasicPay(grade);

        // 기초 공제액 계산
        int baseDeduction = calcBaseDeduction(spouse, child);

        // 과세 표준액 계산
        int taxStandard = calcTaxStandard(basicPay, baseDeduction);

        // 세금 계산
        int tax = calcTax(taxStandard);

        // 최종 지급액 계산
        int salary = calcSalary(basicPay, tax);

        // 결과 출력
        printResult(grade, basicPay, baseDeduction, taxStandard, tax, salary);

        printf("\n");
    }
}

// 본봉 계산: 800,000 + (호봉 - 1) * 42,000
int calcBasicPay(int grade)
{
    return 800000 + (grade - 1) * 42000;
}

// 기초 공제액 계산
int calcBaseDeduction(int spouse, int child)
{
    return 1000000 + spouse * 20000 + child * 10000;
}

// 과세 표준액 계산: 본봉 - 기초 공제액
int calcTaxStandard(int basicPay, int baseDeduction)
{
    int result = basicPay - baseDeduction;

    // 음수가 나오면 과세하지 않음 → 표준액 0 처리
    if (result < 0)
        result = 0;

    return result;
}

// 세금 계산 (표 기준 적용)
int calcTax(int taxStandard)
{
    int tax = 0;

    if (taxStandard < 1000000)       // 100만원 미만
    {
        tax = taxStandard * 5 / 100 - 3000;
    }
    else if (taxStandard < 2000000)  // 100만~200만 미만
    {
        tax = taxStandard * 15 / 100 - 5000;
    }
    else if (taxStandard < 3000000)  // 200만~300만 미만
    {
        tax = taxStandard * 20 / 100 - 10000;
    }
    else                              // 300만 이상
    {
        tax = taxStandard * 30 / 100 - 20000;
    }

    // 세금이 10원 미만이면 절사
    if (tax < 10)
        tax = 0;

    return tax;
}

// 실제 지급액 = 본봉 - 세금
int calcSalary(int basicPay, int tax)
{
    return basicPay - tax;
}

// 결과 출력
void printResult(int grade, int basicPay, int baseDeduction, int taxStd, int tax, int salary)
{
    printf("\n호봉: %d\n", grade);
    printf("본봉: %d원\n", basicPay);
    printf("기초 공제액: %d원\n", baseDeduction);
    printf("과세 표준액: %d원\n", taxStd);
    printf("세금: %d원\n", tax);
    printf("지급액: %d원\n", salary);
}
