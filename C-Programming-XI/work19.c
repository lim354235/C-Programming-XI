#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

// 커서 이동 함수
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    int targetMoney;     // 최종 주유 금액
    int pricePerLiter;   // 1리터당 가격
    double liter = 0.0;  // 현재 리터
    int money = 0;       // 현재 금액
    int x = 5, y = 8;    // 출력 시작 좌표

    printf("주유기 숫자표시 프로그램\n");
    printf("주유할 금액을 입력: ");
    scanf("%d", &targetMoney);
    printf("1리터당 금액을 입력: ");
    scanf("%d", &pricePerLiter);

    system("cls");  // 화면 지우기

    // 타이틀 출력
    gotoxy(5, 3);  printf("주유기 숫자표시 프로그램");
    gotoxy(5, 4);  printf("주유할 금액 입력: %d", targetMoney);
    gotoxy(5, 5);  printf("1리터당 금액 입력: %d", pricePerLiter);

    // 증가 출력
    while (money <= targetMoney) {

        // 출력 위치 고정
        gotoxy(x, y);
        printf("%07d원/liter", money);

        gotoxy(x, y + 1);
        printf("%08.2fL :Liter", liter);

        // 값 증가
        money += pricePerLiter / 10;   // 금액 증가 속도 조절
        liter += 0.1;                  // 리터 증가 속도 조절

        Sleep(100);   // 변화 속도 조절
    }

    gotoxy(5, y + 4);
    printf("주유가 끝났습니다.\n");

    return 0;
}
