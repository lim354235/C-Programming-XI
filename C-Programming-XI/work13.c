#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
int getBasicFee(int usage);
int getUsageFee(int usage);
int calcVat(int elec);
int calcFund(int elec);
void printResult(int usage, int basic, int usageFee, int elec, int vat, int fund, int total);

int main()
{
    run();   
    return 0;
}

void run()
{
    int usage;

    printf("전기요금 청구서 출력 program\n\n");
    printf("전력사용량(kW/h)을 입력하고 Enter> ");
    scanf("%d", &usage);

    int basic = getBasicFee(usage);

    int usageFee = getUsageFee(usage);

    int elec = basic + usageFee;

    int vat = calcVat(elec);

    int fund = calcFund(elec);

    int total = elec + vat + fund;

    printResult(usage, basic, usageFee, elec, vat, fund, total);
}

int getBasicFee(int u)
{
    if (u <= 100) return 390;
    else if (u <= 200) return 870;
    else if (u <= 300) return 1560;
    else if (u <= 400) return 2620;
    else if (u <= 500) return 3790;
    else return 12350;
}

int getUsageFee(int u)
{
    double fee = 0;

    if (u > 100) { fee += 100 * 57.9; }
    else { return (int)(u * 57.9); }

    if (u > 200) { fee += 100 * 120.2; }
    else { fee += (u - 100) * 120.2; return (int)fee; }

    if (u > 300) { fee += 100 * 179.4; }
    else { fee += (u - 200) * 179.4; return (int)fee; }

    if (u > 400) { fee += 100 * 267.9; }
    else { fee += (u - 300) * 267.9; return (int)fee; }

    if (u > 500) { fee += 100 * 360.6; }
    else { fee += (u - 400) * 360.6; return (int)fee; }

    fee += (u - 500) * 677.3;

    return (int)fee;
}

int calcVat(int elec)
{
    int vat = (int)(elec * 0.10);
    return (vat / 10) * 10;
}

int calcFund(int elec)
{
    int fund = (int)(elec * 0.037);
    return (fund / 10) * 10;
}

void printResult(int usage, int basic, int usageFee, int elec, int vat, int fund, int total)
{
    printf("\n기본요금      :   %d원\n", basic);
    printf("사용요금      :   %d원\n", usageFee);
    printf("전력요금      :   %d원\n", elec);
    printf("전력기금      :   %d원\n", fund);
    printf("부가가치세    :   %d원\n", vat);
    printf("청구요금      :   %d원\n", total);
}
