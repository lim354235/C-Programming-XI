#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void run();
int checkMatch(char prev[], char now[]);
void printPrompt();

int main()
{
    run();
    return 0;
}

void run()
{
    char prev[50];
    char now[50];

    printPrompt();
    scanf("%s", prev);

    if (prev[0] == '0')
        return;

    // 0입력시 종료
    while (1)
    {
        printPrompt();
        scanf("%s", now);

        if (now[0] == '0')
            break;

        if (!checkMatch(prev, now))
        {
            printf("다시 입력하세요\n");
            printPrompt();
            scanf("%s", now);

            if (now[0] == '0')
                break;

            printPrompt();
            printf("\n");
            break;
        }

        strcpy(prev, now);
    }
}

/* 끝말잇기 규칙 검사 */
int checkMatch(char prev[], char now[])
{
    int last = strlen(prev) - 1;
    return (prev[last] == now[0]);
}

/* 출력 예시와 완전히 동일한 입력 안내 문구 */
void printPrompt()
{
    printf("단어를 입력하고 Enter> ");
}
