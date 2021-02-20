#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 50

int main()
{
    int t;
    short val = 0;

    printf("%C\t%C\t\n----------------------\n", val ? 'F' : 'C', !val ? 'F' : 'C');

    for (t = LOWER; t <= UPPER; t = t + STEP)
    {
        printf("%d\t%d\n", t, val ? 5*(t-32)/9 : 9*t/5+32);
    }
}
