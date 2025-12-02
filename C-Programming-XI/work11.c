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
    int grade;      
    int spouse;     
    int child;      

    while (1)
    {
        printf("봉급계산 program\n");
        printf("호봉수, 배우자 유무(1,0), 부양가족 수를 입력하세요\n");
        printf("호봉이 0이면 종료됩니다.\n");
        printf("자료입력 => ");

        scanf("%d", &grade);

        if (grade == 0)   
            break;

        scanf("%d %d", &spouse, &child);

        
        int basicPay = calcBasicPay(grade);

        
        int baseDeduction = calcBaseDeduction(spouse, child);

       
        int taxStandard = calcTaxStandard(basicPay, baseDeduction);

        
        int tax = calcTax(taxStandard);

        
        int salary = calcSalary(basicPay, tax);

       
        printResult(grade, basicPay, baseDeduction, taxStandard, tax, salary);

        printf("\n");
    }
}


int calcBasicPay(int grade)
{
    return 800000 + (grade - 1) * 42000;
}


int calcBaseDeduction(int spouse, int child)
{
    return 1000000 + spouse * 20000 + child * 10000;
}


int calcTaxStandard(int basicPay, int baseDeduction)
{
    int result = basicPay - baseDeduction;

   
    if (result < 0)
        result = 0;

    return result;
}


int calcTax(int taxStandard)
{
    int tax = 0;

    if (taxStandard < 1000000)      
    {
        tax = taxStandard * 5 / 100 - 3000;
    }
    else if (taxStandard < 2000000) 
    {
        tax = taxStandard * 15 / 100 - 5000;
    }
    else if (taxStandard < 3000000)  
    {
        tax = taxStandard * 20 / 100 - 10000;
    }
    else                             
    {
        tax = taxStandard * 30 / 100 - 20000;
    }

    
    if (tax < 10)
        tax = 0;

    return tax;
}


int calcSalary(int basicPay, int tax)
{
    return basicPay - tax;
}

void printResult(int grade, int basicPay, int baseDeduction, int taxStd, int tax, int salary)
{
    printf("\n호봉: %d\n", grade);
    printf("본봉: %d원\n", basicPay);
    printf("기초 공제액: %d원\n", baseDeduction);
    printf("과세 표준액: %d원\n", taxStd);
    printf("세금: %d원\n", tax);
    printf("지급액: %d원\n", salary);
}
