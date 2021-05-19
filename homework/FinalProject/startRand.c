#include "my2048.h"
void startRand(int** matriz)//Generate random location in free tiles to place a 2 by saving all free tile´s addresses and selecting randomly one of them.
{
    time_t timenow;
    time(&timenow);
    struct tm *tiempo = localtime(&timenow);

    int *room[16], r = 0;//Save tiles´ addresses.
    int i, j;
    for(j = 0; j<4; j++)
        for(i = 0; i<4; i++)
            if(matriz[j][i] == 0)
                room[r++] = &matriz[j][i];//Save in a queue all free tiles´ addresses.
    r = tiempo->tm_sec%r;//Select the random address.
    *room[r] = 2;//Place the 2 in it.
}
