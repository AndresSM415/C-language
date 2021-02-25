#include <stdio.h>
#include <conio.h>

int main()
{
    char *filename = "C:\\Users\\andre\\Downloads\\locura.txt";
    FILE *fptr = fopen(filename, "r");//"w" if you want to edit a file
    int c;

    short nd;

    while((c = getc(fptr)) != EOF)
    {
        if(c == '/')
            nd++;

        else if(nd < 2 || c == '\n')
        {
            if(nd == 1)
                putchar('/');
            putchar(c);
            nd = 0;
        }
    }
    fclose(fptr);
    _getch();
}
