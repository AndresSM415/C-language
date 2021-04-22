#ifndef MINESWEEPER_H_INCLUDED
#define MINESWEEPER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

extern int MI; //MINA
int muestraPos(int**, char **, int, int, int);
void cuentaMinas(int**);
int coordenada(int *, int *);
void imprimeMapa(char**);
#endif // MINESWEEPER_H_INCLUDED
