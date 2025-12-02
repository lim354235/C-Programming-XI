#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>


void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    int targetMoney;    
    int pricePerLiter;   
    double liter = 0.0; 
    int money = 0;      
    int x = 5, y = 8;   

    printf("주유기 숫자표시 프로그램\n");
    printf("주유할 금액을 입력: ");
    scanf("%d", &targetMoney);
    printf("1리터당 금액을 입력: ");
    scanf("%d", &pricePerLiter);

    system("cls"); 

    
    gotoxy(5, 3);  printf("주유기 숫자표시 프로그램");
    gotoxy(5, 4);  printf("주유할 금액 입력: %d", targetMoney);
    gotoxy(5, 5);  printf("1리터당 금액 입력: %d", pricePerLiter);

   
    while (money <= targetMoney) {

        
        gotoxy(x, y);
        printf("%07d원/liter", money);

        gotoxy(x, y + 1);
        printf("%08.2fL :Liter", liter);

        
        money += pricePerLiter / 10;   
        liter += 0.1;                  

        Sleep(100);   
    }

    gotoxy(5, y + 4);
    printf("주유가 끝났습니다.\n");

    return 0;
}
