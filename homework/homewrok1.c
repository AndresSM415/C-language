#include <stdio.h>
#include <conio.h>
#define NCHAR 130
#define COMMANDTYPES 4

int c, i = 0;
int nc = 0; //new command
int state = COMMANDTYPES;
int ln[NCHAR];//line
int incommand[COMMANDTYPES][33] = {//[row][column]
                        {'<','h','1','>'},
                        {'<','s','t','r','o','n','g','>'},
                        {'<','p','>'},
                        {'<','s','c','r','i','p','t',' ','t','y','p','e','=','"','t','e','x','t','/','j','a','v','a','s','c','r','i','p','t','"','>'},
                      };
int outcommand[COMMANDTYPES][10] = {//[row][column]
                        {'<','/','h','1','>'},
                        {'<','/','s','t','r','o','n','g','>'},
                        {'<','/','p','>'},
                        {'/','s','c','r','i','p','t','>'},
                       };
int queue[5];
int iqueue = 0;//index queue
int ip, g;// i position, counter of character into the command, state of command found

void println();
int newCommand();

int main()
{
    char *filename = "C:\\Users\\andre\\Downloads\\locura.txt";
    FILE *fptr = fopen(filename, "r");//"w" if you want to edit a file
    //I got the code to open a file in this video: https://www.youtube.com/watch?v=G5A04QCi7e4&ab_channel=MinhajAnsari
    while((c = getc(fptr)) != EOF)
    {
        ln[i] = c;
        if(c == '<')
            nc++;
        else if(c == '>')
        {
            state = newCommand();
            if(state != COMMANDTYPES)
            {
                queue[iqueue] = state;
                iqueue++;
            }
            else
            {
                state = oldCommand();
                if(state != COMMANDTYPES)
                {
                    iqueue--;
                    queue[iqueue] = COMMANDTYPES;
                }
            }
            nc = 0;
            i = i- ip - 1;//reposiciona el indice para reescribir sobre el inicio del comando
            ip = 0;
        }
        else if((queue[iqueue-1] == 0 || queue[iqueue-1] == 1) && iqueue > 0 && (c == ' ' || c == '\t'))// comandos <h1> y strong
            ln[i] = '_';
        else if(queue[iqueue-1] == 3 && iqueue > 0)
        {
            while((c = getc(fptr)) != EOF){
                if(c == '<')
                {
                    for(g = 0; (g < 8) && ((c = getc(fptr)) == outcommand[3][g]); g++){
                    }
                    if(g == 8)
                    {
                        iqueue--;
                        queue[iqueue] = COMMANDTYPES;
                        break;
                    }
                }
            }
        }
        if(nc == 1)//si se ha abierto un comando guarda el numero de caracteres que tiene
        {
            ip++;
            ln[i] = tolower(c);

        }
        else if(c == '\n')
        {
            println();
            i = 0;
        }
        i++;
    }
    println();

    fclose(fptr);
    _getch();
    return 0;
}

int newCommand()
{
    state = COMMANDTYPES;
    for(int commandType = 0; commandType < COMMANDTYPES; commandType++)
    {
        for(g = 0; (g <= ip) && (ln[i-ip+g] == incommand[commandType][g]); g++){}//una vez grabado el comando, se procede a identificar si este es uno que nos interesa
        if(g == ip + 1)
        {
            state = commandType;
            break;
        }
    }
    return state;
}

int oldCommand()
{
    state = COMMANDTYPES;
    for(int commandType = 0; commandType < COMMANDTYPES; commandType++)
    {
        for(g = 0; (g <= ip) && (ln[i-ip+g] == outcommand[commandType][g]); g++){}//una vez grabado el comando, se procede a identificar si este es uno que nos interesa
        if(g == ip + 1)
        {
            state = commandType;
            break;
        }
    }
    return state;
}
void println()
{
    for(int e = 0; i-e > 0; e++)//escribe el texto ya modificado
        printf("%c", ln[e]);
}
