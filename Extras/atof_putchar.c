#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    double number = 0, decim;
    int c, sign, eFlag = 0, decimFlag = 0;

    decim = sign = 1;
    while(!isdigit(c = getchar()) && c != EOF)//te comes todo lo que no sea digitos antes de generar tu numero
    {
        if(c == '.')
        {
            decim = sign == 1 ? 10 : -10;
            decimFlag = 1;
        }
        else
            decimFlag = 0;

        sign = c == '-' ? -1 : 1;//checas si lo que te comiste no es un signo negativo.
    }
    if(c != EOF)
    {
        number = c - '0';

        while(decimFlag == 0 && isdigit(c = getchar()) && c != EOF)
            number = number*10 + c - '0';

        if(c == '.' || decimFlag == 1)
            while(isdigit(c = getchar()) && c != EOF)
            {
                number = number*10 + c - '0';
                decim *= 10;
            }
        number = sign*number/decim;
        printf("number: %f", number);
    }

    return 0;
}
