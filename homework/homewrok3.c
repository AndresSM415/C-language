#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>

extern int queue = 0;//numera la cantidad de parentesis sin cerrar

int isparenthesis(int c);
int ispunctuation(int c);
int isquote(int c);

int main()
{
    bool noparenflag = false, quoteflag = false;//(parentesis abiertos), (comillas abiertas)

    int c;
    while((c = getchar()) != EOF)
    {
        if(isparenthesis(c)){}
        else if(ispunctuation(c))//las puntuaciones se omiten
            continue;
        else if(isquote(c))
            quoteflag = !quoteflag;//si era falso ahora se indica que hay comillas abiertas y viceversa
        else if(isdigit(c) && queue < 1 && !quoteflag)//si es un digito y no hay parentesis abiertos y las comillas no estan abiertas
            noparenflag = true;//indica que se puede proceder a poner X
        else if(noparenflag)// si se ha marcado como verdadero entonces procede a poner la X
        {
            noparenflag = false;
            printf("X");
        }

        if(!noparenflag || quoteflag)//ya se ha guardado una letra cuando se hizo la revision posterior, por lo que se procede a ponerla
            putchar(c);
    }
    if(noparenflag)//en caso que el ultimo digito era un numero, pon la X
        printf("X");
    return 0;
}
int isparenthesis(int c)
{
    bool change = false;
    switch(c)
    {
    case '(': case '{': case '[':
        queue++;
        change = true;
        break;
    case ')': case '}': case ']':
        queue--;
        change = true;
        break;
    }
        queue = queue < 0 ? 0 : queue;
    return change;
}

int ispunctuation(int c)
{
    bool change = false;
    switch (c)
    {
    case ':': case ';': case '.': case ',': case '-': case '?': case '!': case '_':
        change = true;
        break;
    }
    return change;
}

int isquote(int c)
{
    bool change = false;
    switch (c)
    {
    case '"': case '\'':
        change = true;
        break;
    }
    return change;
}
