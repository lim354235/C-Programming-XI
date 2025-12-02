#include <stdio.h>
#include <math.h>
#define pi 3.141592

int d();

int main()
{
    d();
    return 0;
}

int d()
{
    int angle;
    double rad, s, c;
    int posS, posC;
    int i;

    for (angle = 0; angle <= 360; angle += 15) {

        rad = angle * pi / 180.0;
        s = sin(rad);
        c = cos(rad);

        posS = ((s + 1) * 25);
        posC = ((c + 1) * 25);

        for (i = 0; i < 51; i++) {
            if (i == posS && i == posC)
                printf("B");
            else if (i == posS)
                printf("S");
            else if (i == posC)
                printf("C");
            else
                printf(" ");   
        }

        printf("  %3d¡Æ\n", angle);
    }

    return 0;
}
