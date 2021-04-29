#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct treenode
{
    char value[MAX];
    char password[MAX];
    unsigned int counter;
    unsigned int depth;
    struct treenode* leftChild;
    struct treenode* rightChild;
} node;

void show(node* );
//int findc(node* , char* );
//int checarama(node*, char*)

#endif // STRUCTURES_H_INCLUDED
