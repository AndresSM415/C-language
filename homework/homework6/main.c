#include "structures.h"

node* insert(char* value, char* pass, node* pos, int d);
node* erasec(node*, char*, char*);
int findc(node* pos, char* value);

int main()
{
    printf("para agregar un usuario pon un '+' seguido por el nombre y con un espacio despues, pones la contraseña.\n Para eliminar un usuario pones un '-' seguido por el nombre y la contraseña de la manera mencionada anteriormente.\n Ej. \"+ juan 123\"");
    char account[MAX];
    node* n = NULL;
    node* tree = NULL;
    char c;
    while(1){
        switch(c = getword(account, MAX))
        {
        case '-':
            c = getword(account, MAX);
            char pass[MAX];
            c = getword(pass, MAX);
            erasec(tree, account, pass);
            show(tree);
            break;
        case '+':
            c = getword(account, MAX);
            if(!findc(tree, account))//1 si existe, 0 si no
            {
                char pass[MAX];
                c = getword(pass, MAX);

                n = insert(account, pass, tree, 0);
                if(tree == NULL)
                    tree = n;

            }
            else
            {
                printf("%s ya existe\n", account);
                while(getchar() != '\n'){}
            }
            show(tree);
            printf("\n\n\t");
            break;
        }
    }
    return 0;
}

int checarama(node* pos, char* value);
node* copynode(node* pos, node* child);
node* insert(char* value, char* pass, node* pos, int d)
{
    node* temp;
    if(pos == NULL)
    {
        pos = (node*)malloc(sizeof(node));
        strcpy(pos->value, value);
        strcpy(pos->password, pass);
        pos->counter = 1;
        pos->depth = d;
        pos->leftChild = NULL;
        pos->rightChild = NULL;
    }
    else
    {
        if(strcmp(pos->value, value) == 0 && strlen(pos->password) > 0)
            (pos->counter)++;
        else if(strcmp(pos->value, value) == 0 && strlen(pos->password) == 0)
        {
            if(checarama(pos->leftChild, value))
                pos->leftChild = insert(value, pass, pos->leftChild, d);
            else if(checarama(pos->rightChild, value))
                pos->rightChild = insert(value, pass, pos->rightChild, d);
        }
        else if(strcmp(pos->value, value) > 0)//tu valor es mas chico y se va ala izquierda
        {
            if(strlen(pos->password) > 0)
            {
                pos->rightChild = copynode(pos, pos->rightChild);
                pos->password[0] = '\0';
            }
            temp = insert(value, pass, pos->leftChild, d+1);
            if(pos->leftChild == NULL)
                pos->leftChild = temp;
        }
        else if(strcmp(pos->value, value) <= 0)
        {
            if(strlen(pos->password) > 0)
            {
                pos->leftChild = copynode(pos, pos->leftChild);
                pos->password[0] = '\0';
            }
            temp = insert(value, pass, pos->rightChild, d+1);//tu valor es mas grande
            if(pos->rightChild == NULL)
                pos->rightChild = temp;
        }
    }
    return pos;
}
int checarama(node* pos, char* value)
{
    if(strcmp(pos->value, value) == 0)
        return 1;
    else
        return 0;
}
node* copynode(node* pos, node* child)
{
    child = (node*)malloc(sizeof(node));
    strcpy(child->value, pos->value);
    strcpy(child->password, pos->password);
    child->counter = pos->counter;
    child->depth = pos->depth + 1;
    child->leftChild = NULL;
    child->rightChild = NULL;
    return child;
}

void erase(node* tree)
{
    if(tree != NULL)
    {
        erase(tree->leftChild);
        erase(tree->rightChild);
        free(tree);
    }
}

node* erasec(node* pos, char* value, char* pass)
{
    node* temp;


    if(strcmp(pos->value, value) == 0 && strcmp(pos->password, pass) == 0)
        pos->password[0] = '\0';
    else if(strcmp(pos->value, value) == 0 && strlen(pos->password) == 0)
    {
        if(checarama(pos->leftChild, value))
            pos->leftChild = erasec(pos->leftChild, value, pass);
        else if(checarama(pos->rightChild, value))
            pos->rightChild = erasec(pos->rightChild, value, pass);
    }
    else if(strcmp(pos->value, value) > 0 && !(pos->leftChild == NULL && pos->rightChild == NULL))//tu valor es mas chico y se va ala izquierda
    {
        temp = erasec(pos->leftChild, value, pass);
        if(pos->leftChild == NULL)
            pos->leftChild = temp;
    }
    else if(strcmp(pos->value, value) <= 0 && !(pos->leftChild == NULL && pos->rightChild == NULL))
    {
        temp = erasec(pos->rightChild, value, pass);//tu valor es mas grande
        if(pos->rightChild == NULL)
            pos->rightChild = temp;
    }
    else
        printf("Datos incorrectos\n");
    return pos;
}
int findc(node* pos, char* value)
{
    int exists = 0;
    node* temp;
    {
        if(pos == NULL)
            exists = 0;
        else if(strcmp(pos->value, value) == 0 && strlen(pos->password) > 0)
            exists = 1;
        else if(strcmp(pos->value, value) == 0 && strlen(pos->password) == 0 )
        {
            if(checarama(pos->leftChild, value))
                exists = findc(pos->leftChild, value);
            else if(checarama(pos->rightChild, value))
                exists = findc(pos->rightChild, value);
        }
        else if(strcmp(pos->value, value) > 0)//tu valor es mas chico y se va ala izquierda
        {
            exists = findc(pos->leftChild, value);
        }
        else if(strcmp(pos->value, value) <= 0)
        {
            exists = findc(pos->rightChild, value);//tu valor es mas grande
        }
    }
    return exists;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalnum(c))
    {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch()))
        {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
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
