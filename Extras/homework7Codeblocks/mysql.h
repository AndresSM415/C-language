#ifndef MYSQL_H_INCLUDED
#define MYSQL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100
#define PIN 5
typedef struct treenode
{
    char name[MAX];
    char pin[PIN];
    int cal[7];
    int llega[7];
    int sale[7];
    int dentro;
    struct treenode* child;
} node;


#endif // MYSQL_H_INCLUDED
