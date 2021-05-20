#include "my2048.h"
int truemove;
void stickAndSum(int**, int, int, int);
int moveMatriz(int** matriz)//Stack and sum matrix. In case of no actual change of matrix, warn to avoid generating random number. 
{
    truemove = 0;
    char c;
    while(isspace(c = getchar())){}

    switch(tolower(c))
    {
    case 'w':
        stickAndSum(matriz, 0, 0, 1);
        break;
    case 'a':
        stickAndSum(matriz, 0, 0, 0);
        break;
    case 's':
        stickAndSum(matriz, 4, 0, 1);
        break;
    case 'd':
        stickAndSum(matriz, 0, 4, 0);
        break;
    default:
        break;
    }
    return truemove;//1 if there was actually a change, 0 if not.
}

void stickMatriz(int**, int, int, int);
void sumPairs(int**, int, int, int);
//[j] 0 if stacking to top, left, or right; 1 to bottom.
//[i] 0 if stacking to top, left, or bottom; 1 to left.
//[dim] 0 if stacking horizontally; 1 vertically.
void stickAndSum(int** matriz, int j, int i, int dim)//First stack all matrix´s values, then add neighbors, and finally stack them again.
{
    stickMatriz(matriz, j, i, dim);
    sumPairs(matriz, j, i, dim);
    stickMatriz(matriz, j, i, dim);
}

void stickMatriz(int** matriz, int j, int i, int dim)//Stack matrix in any direction with pointers.
{
    //In case of stacking to left or top.
    int iNext;//Next matrix value to stack.
    int *xNxt = &j, *yNxt = &iNext;//Next matrix coordinates.
    int iLim = 3;//Final index value.
    int *iptr = &i, iPosNeg = 1;//index going forward. *iptr += iPosNeg means i++.
    int *i1 = &i, *i2 = &iLim;//You are moving index from 0 to 3. *i1 <= *i2 means i <= 3.
    int *x = &j, *y = &i;//You are moving index in the column.

    if(i == 4 || j == 4)//In case of stacking to bottom or left.
    {
        i = 3;//Start position in the final side.
        iLim = 0;//Limit 0.
        iPosNeg = -1;//Going backwards. *iptr += iPosNeg means i--.
        i1 = &iLim;
        i2 = &i;//You are starting in index 3. *i1 <= *i2 means 0 <= i.
    }
    if(dim)//If stacking vertically.
    {
        xNxt = &iNext;//The lines are changing with index.
        yNxt = &j;
        x = &i;
        y = &j;
    }
    int ibegin = i;
    for(int times = 0; times < 3; times++)
        for(j = 0; j < 4; j++)
            for(*iptr = ibegin; *i1 <= *i2; *iptr += iPosNeg)//A lot of pointers, I know.
                if(matriz[*x][*y] == 0)//If your current tile, has a 0, you can make a move.
                {
                    iNext = *i1 != *i2 ? i+iPosNeg : i;//Checking if you are not in the final tile.
                    if(matriz[*xNxt][*yNxt] != 0)//Checking if the movement actually will change the matrix.
                        truemove = 1;//Warn matrix actually moved.
                    matriz[*x][*y] = matriz[*xNxt][*yNxt];//Replace current position value, with the next one.
                    matriz[*xNxt][*yNxt] = 0;//Making next tile 0.
                }
}

void sumPairs(int** matriz, int j, int i, int dim)//Sum tiles´ neighbors.
{
    //All explained in the function above.
    int iNext;
    int *yNxt = &iNext, *xNxt = &j;
    int iLim = 3;
    int *iptr = &i, iPosNeg = 1;
    int *i1 = &i, *i2 = &iLim;
    int *x = &j, *y = &i;

    if(i == 4 || j == 4)
    {
        i = 3;
        iLim = 0;
        iPosNeg = -1;
        i1 = &iLim;
        i2 = &i;
    }
    if(dim)
    {
        xNxt = &iNext;
        yNxt = &j;
        x = &i;
        y = &j;
    }
    int ibegin = i;
    for(j = 0; j < 4; j++)
        for(*iptr = ibegin; *i1 <= *i2 ; *iptr += iPosNeg)
        {
            iNext = *i1 != *i2 ? i+iPosNeg : i;
            if(*i1 != *i2 && matriz[*x][*y] == matriz[*xNxt][*yNxt] && matriz[*x][*y] != 0)//If you are not in the final tile and the current tile is equal to the next one, but they aren´t 0, then:
            {
                truemove = 1;//Warn matrix actually moved.
                matriz[*x][*y] *= 2;//sum tiles in the current position.
                matriz[*xNxt][*yNxt] = 0;//Delete next tile´s value.
            }
        }
}
