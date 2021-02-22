#include <stdio.h>
#include <conio.h>
#define NCHAR 100

int c, i = 0;
int nc = 0; //new comand
int ip, g, state;// i position, counter of character into the comand, state of comand found
int ln[NCHAR];//line



void println();
int newCommand(int iP, int i);
int main()
{
//  int head[4] = {'<','h','1','>'};
//  int fhead[5] = {'<','/','h','1','>'};
    int head[2][5] ={//[row][column]
                        {'<','h','1','>'},
                        {'<','/','h','1','>'}
                    };

    char *filename = "C:\\Users\\andre\\Downloads\\locura.txt";
    FILE *fptr = fopen(filename, "r");//"w" if you want to edit a file

    while((c = getc(fptr)) != EOF)
    {
        ln[i] = c;
        if(c == '<')
            nc++;
        else if(c == '>')
        {
            for(g = 0; (g <= ip) && (ln[i-ip+g] == head[0][g]); g++){}//una vez grabado el comando, se procede a identificar si este es uno que nos interesa
            if(g == ip + 1)
                state = 1;

            for(g = 0; (g <= ip) && (ln[i-ip+g] == head[1][g]); g++){}
            if(g == ip + 1)
                state = 0;
            nc = 0;
            i = i-ip-1;//reposiciona el indice para reescribir sobre el inicio del comando
            ip = 0;
        }

        if(state == 1 && (c == ' ' || c == '\t'))
            ln[i] = '_';

        if(nc == 1 )//si se ha abierto un comando guarda el numero de caracteres que tiene
            ip++;

        i++;
        if(c == '\n')
        {
            println();
            i = 0;
        }
    }
    fclose(fptr);
    _getch();

    println();
}
void println()
{
    for(int e = 0; i-e > 0; e++)//escribe el texto ya modificado
        printf("%c", ln[e]);
}
