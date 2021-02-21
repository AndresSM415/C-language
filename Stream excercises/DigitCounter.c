
#include <stdio.h>
#include <ctype.h>

#define IN 1
#define OUT 0

int main()
{
    char *filename = "C:\\Users\\andre\\Downloads\\locura.txt";
    FILE *fptr = fopen(filename, "r");
    int ch;

    int i, w = 0, o = 0;

    int d[10];
    for(i = 0; i < 10; i++)
    {
        d[i] = 0;
    }

    while((ch = getc(fptr)) != EOF)
    {
        if(ch >= '0' && ch <= '9')
        {
            d[ch-'0'] += 1;
        }
        else if(isspace(ch))
        {
            w++;
        }
        else
        {
            o++;
        }
    }

    printf("\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d of %d\n", d[i], i);
    }
    printf("%d spaces and %d other characters\n", w, o);

    fclose(fptr);
    _getch();
    return 0;
}
