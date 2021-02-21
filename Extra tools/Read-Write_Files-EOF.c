#include <stdio.h>
#include <conio.h>
int main()
{
    char *filename = "C:\\Users\\andre\\Downloads\\locura.txt";
    FILE *fptr = fopen(filename, "r");//"w" if you want to edit a file
    int ch;

    while((ch = getc(fptr)) != EOF)
    {
        putchar(ch);//printf("%c", ch);
    }

    fclose(fptr);

    _getch();
    return 0;
}
