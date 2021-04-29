#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
void clearval();
/* reverse Polish calculator */
double alpha[26];
int ialpha;

int main()
{
    int varflag = 0, varalpha;
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case 'sin':
            push(sin(pop()));
            break;
        case 'cos':
            push(cos(pop()));
            break;
        case 'tan':
            push(tan(pop()));
            break;
        case 'root':
            push(sqrt(pop()));
            break;
        case 'A':
            push(alpha[ialpha]);
            break;
        case 'log':
            push(log(pop()));
            break;
        case 'exp':
            push(exp(pop()));
            break;
        case 'pow':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '=': case ':':
            varflag++;
            varalpha = ialpha;
            break;
        case '\n':
            if(varflag == 1)
            {
                printf("are you sure you want to change variable %c? press 1 or 0:\n", varalpha + 'a');
                if(getchar() == '1')
                    varflag++;
                else
                {
                    clearval();
                    printf("action canceled.\n");
                }
                getchar();
            }
            if(varflag == 2)
                printf("\t%c = %.8g\n", varalpha + 'a', alpha[25] = alpha[varalpha] = pop());
            else if(varflag == 0)
                printf("\t%c = %.8g\n", 'z', alpha[25] = pop());
            varflag = 0;
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}
void clearval()
{
    for(; sp > 0; sp--)
        val[sp] = 0.0;
}
/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>
int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i = 0, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        char functions[100][100] ={ {"sin>"},
                                    {"cos>"},
                                    {"tan>"},
                                  };
        if(c == '+' || c == '-')
        {
            ungetch(c);
            if(isdigit(s[++i] = c = getchar()))
                getch();
            else
            {
                s[i] = getch();
                ungetch(c);
                return s[i];
            }
        }
        else if(isalpha(c = tolower(c)))
        {
            ungetch(c);
            if(c == 's')
            {
                if((s[++i] = c = getchar()) == 'i')
                {
                    getch();
                    if((s[++i] = c = getchar()) == 'n')
                        return 'sin';
                    else
                        printf("couldn´t understand");
                }
                else if(c == 'q')
                {
                    getch();
                    if((s[++i] = c = getchar()) == 'r')
                    {
                        if((s[++i] = c = getchar()) == 't')
                            return 'root';
                    }
                    else
                        printf("couldn´t understand");
                }
                else
                {
                    getch();
                    ungetch(s[i--]);
                    ialpha = s[i] - 'a';
                    return 'A';
                }
            }
            if(c == 'c')
            {
                if((s[++i] = c = getchar()) == 'o')
                {
                    getch();
                    if((s[++i] = c = getchar()) == 's')
                        return 'cos';
                    else
                        printf("couldn´t understand");
                }
                else
                {
                    getch();
                    ungetch(c);
                    ialpha = s[--i] - 'a';
                    return 'A';
                }
            }
            if(c == 't')
            {
                if((s[++i] = c = getchar()) == 'a')
                {
                    getch();
                    if((s[++i] = c = getchar()) == 'n')
                        return 'tan';
                    else
                        printf("couldn´t understand");
                }
                else
                {
                    getch();
                    ungetch(c);
                    ialpha = s[--i] - 'a';
                    return 'A';
                }
            }
            if(c == 'l')
            {
                if((s[++i] = c = getchar()) == 'o')
                {
                    getch();
                    if((s[++i] = c = getchar()) == 'g')
                        return 'log';
                    else
                        printf("couldn´t understand");
                }
                else
                {
                    getch();
                    ungetch(c);
                    ialpha = s[--i] - 'a';
                    return 'A';
                }
            }
            if(c == 'e')
            {
                if((s[++i] = c = getchar()) == 'x')
                {
                    getch();
                    if((s[++i] = c = getchar()) == 'p')
                        return 'exp';
                    else
                        printf("couldn´t understand");
                }
                else
                {
                    getch();
                    ungetch(c);
                    ialpha = s[--i] - 'a';
                    return 'A';
                }
            }
            if(c == 'p')
            {
                if((s[++i] = c = getchar()) == 'o')
                {
                    getch();
                    if((s[++i] = c = getchar()) == 'w')
                        return 'pow';
                    else
                        printf("couldn´t understand");
                }
                else
                {
                    getch();
                    ungetch(c);
                    ialpha = s[--i] - 'a';
                    return 'A';
                }
            }
            else
                getch();
                ialpha = c - 'a';
                return 'A';
        }
        /*else if(c == 's')
        {
            ungetch(c);
            if((s[++i] = c = getchar()) == 'i')
            {
                getch();
                if((s[++i] = c = getchar()) == 'n')
                    return 'sin';
                else
                    printf("couldnt understand");
            }
        }
        /*for(int yfunc = 0; ifunc < 3; ifunc++)
        {
            if(c == functions[yfunc][0])
            {
                for(int xfunc = 1; xfunc < 100; xfunc++)
                    if((c = getchar()) == functions[yfunc][xfunc])
                if
            }

        }*/
        else
            return c; /* not a number */

    }
    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
