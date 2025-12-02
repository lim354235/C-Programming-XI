#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define CITY 6   

void run();
void printCityMenu();
int getFare(int fare[CITY][CITY], int start, int end);

int main()
{
    run(); 
    return 0;
}

void run()
{
    
    int fare[CITY][CITY] = {
        {   0, 1700, 4200,  7500, 15200, 19300 }, 
        { 1700,    0, 3400,  6700, 13100, 17800 }, 
        { 4200, 3400,    0,  4200, 11000, 15600 }, 
        { 7500, 6700, 4200,    0,  7800, 12100 },
        {15200,13100,11000, 7800,     0,  4500 },
        {19300,17800,15600,12100,  4500,     0 } 
    };

    int start, end;

    printf("고속도로 통행료 계산 program\n\n");

    
    printCityMenu();

   
    printf("\n출발지 도시번호를 입력하시오 => ");
    scanf("%d", &start);

    
    printf("도착지 도시번호를 입력하시오 => ");
    scanf("%d", &end);

   
    if (start < 0 || start >= CITY || end < 0 || end >= CITY)
    {
        printf("\n도시 번호를 잘못 입력했습니다.\n");
        return;
    }

    if (start == end)
    {
        printf("\n같은 도시를 선택했습니다. 통행요금은 0원입니다.\n");
        return;
    }

   
    int cost = getFare(fare, start, end);

    
    printf("\n%d번 도시에서 %d번 도시까지의 통행요금: %d원\n", start, end, cost);
}

void printCityMenu()
{
    
    printf("각 도시별 번호\n");
    printf("서울(0) 수원(1) 천안(2) 대전(3) 대구(4) 부산(5)\n");
}

int getFare(int fare[CITY][CITY], int start, int end)
{
    return fare[start][end];
}
