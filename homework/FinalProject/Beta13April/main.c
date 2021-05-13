#include "my2048.h"

void movematriz(int** matriz);
int main()
{
    int** matriz;
    matriz = (int**)malloc(sizeof(int*)*4);
    for(int j = 0; j < 4; j++)
    {
        matriz[j] = (int*)malloc(sizeof(int)*4);
        for(int i = 0; i < 4; i++)
            matriz[j][i] = 0;
    }
    startRand(matriz);
    matriz[0][2] = 2;
    matriz[1][0] = 2;
    matriz[2][1] = 2;
    matriz[2][3] = 2;
    matriz[3][1] = 4;
    matriz[3][2] = 4;
    matriz[3][3] = 8;
   /* matriz[][] = {
                {0,0,2,0},
                {2,0,0,0},
                {0,2,0,2},
                {0,4,0,8}
             };*/
    printmat(matriz);

    while(1)
    {
        movematriz(matriz);
        printmat(matriz);
    }

    for(int i = 0; i < 4; i++)
        free(matriz[i]);
    free(matriz);
    return 0;
}

void movematriz(int** matriz)
{
    char c;
    while(isspace(c = getchar())){}

    switch(tolower(c))
    {
    case 'w':
        stickandsum(matriz, 0, 0, 1);
        break;
    case 'a':
        stickandsum(matriz, 0, 0, 0);
        break;
    case 's':
        stickandsum(matriz, 4, 0, 1);
        break;
    case 'd':
        stickandsum(matriz, 0, 4, 0);
        break;
    default:
        break;
    }
}
