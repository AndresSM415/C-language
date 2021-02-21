#include <stdio.h>
#include <conio.h>
#define NCHAR 100

int c, i = 0;
int nc = 0; //new comand
int ip, g, state;
int ln[NCHAR];
int title[3] = {'<','t','>'};

int main()
{
    char *filename = "C:\\Users\\andre\\Downloads\\locura.txt";
    FILE *fptr = fopen(filename, "r");//"w" if you want to edit a file

    while((c = getc(fptr)) != EOF)
    {
        ln[i] = c;
        if(c == '<')
            nc++;
        else if(c == '>')
        {
            for(g = 0; g <= ip; g++)
            {
                printf("\n ln:%d, g:%d", i-ip+g, g);
                if(ln[i-ip+g] == title[g])
                    state = 1;
                else
                    state = 0;
            }
            if(state == 1)
                printf("si se pudo");
            else
                printf("no checa");
            nc = 0;
            i = i-ip-1;
            ip = 0;


        }
        if(nc == 1 )
            ip++;

        i++;
    }
    printf("\n");
    for(int e = 0; i-e > 0; e++)
    {
        printf("%c", ln[e]);
    }
    fclose(fptr);
    _getch();
}
