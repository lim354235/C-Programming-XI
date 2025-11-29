#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define CITY 6   // 도시 개수

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
    // 구간별 통행요금표 (양쪽 방향 동일하다고 가정)
    int fare[CITY][CITY] = {
        // 서울 수원 천안   대전   대구   부산
        {   0, 1700, 4200,  7500, 15200, 19300 }, // 서울(0)
        { 1700,    0, 3400,  6700, 13100, 17800 }, // 수원(1)
        { 4200, 3400,    0,  4200, 11000, 15600 }, // 천안(2)
        { 7500, 6700, 4200,    0,  7800, 12100 }, // 대전(3)
        {15200,13100,11000, 7800,     0,  4500 }, // 대구(4)
        {19300,17800,15600,12100,  4500,     0 }  // 부산(5)
    };

    int start, end;

    printf("고속도로 통행료 계산 program\n\n");

    // 도시 코드 안내 출력
    printCityMenu();

    // 출발 도시 코드 입력
    printf("\n출발지 도시번호를 입력하시오 => ");
    scanf("%d", &start);

    // 도착 도시 코드 입력
    printf("도착지 도시번호를 입력하시오 => ");
    scanf("%d", &end);

    // 유효성 검사
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

    // 요금 계산
    int cost = getFare(fare, start, end);

    // 결과 출력
    printf("\n%d번 도시에서 %d번 도시까지의 통행요금: %d원\n", start, end, cost);
}

void printCityMenu()
{
    // 도시 번호 안내
    printf("각 도시별 번호\n");
    printf("서울(0) 수원(1) 천안(2) 대전(3) 대구(4) 부산(5)\n");
}

// 출발/도착 도시 번호를 받아 요금표에서 해당 금액을 반환
int getFare(int fare[CITY][CITY], int start, int end)
{
    return fare[start][end];
}
