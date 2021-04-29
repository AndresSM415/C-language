#include "structures.h"
void nada(){}
void show(node* pos)
{
    if(pos != NULL)
    {
        for(int i = 0; i < pos->depth; i++)
            printf(" ");
        printf("%s ", pos->value);
        pos->password[0] != '\0' ? printf("(%s)\n", pos->password) : printf("\n");

        pos->leftChild != NULL ? show(pos->leftChild) : nada;
        pos->rightChild != NULL ? show(pos->rightChild) : nada;
    }
}
