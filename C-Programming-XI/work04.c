#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void run();
int gcd(int x, int y);
int lcm(int x, int y, int g);

int main()
{
    run(); 
    return 0;
}

void run()
{
    int x, y;

   
    printf("입력할 두 정수 => ");
    scanf("%d %d", &x, &y);

    int g = gcd(x, y);

    int l = lcm(x, y, g);

   
    printf("최대공약수 = %d\n", g);
    printf("최소공배수 = %d\n", l);
}

int gcd(int x, int y)
{
    int r;

    while (y != 0)
    {
        r = x % y;  
        x = y;       
        y = r;       
    }

    return x;  
}

int lcm(int x, int y, int g)
{
    return x * y / g;
}
