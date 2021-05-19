#include "my2048.h"
void printMat(int** matriz, int record)//Print Matrix
{
    int maxtile = 0, totalPts = 0;
    for(int j = 0; j < 4; j++)
        for(int i = 0; i < 4; i++)
        {
            maxtile = matriz[j][i] > maxtile ? matriz[j][i] : maxtile;//Save the highest tile.
            totalPts += matriz[j][i];
        }

    if(maxtile == 2048)
        printf("\nYou've won!!!! Now continue with infinite mode.\n");
    else
        printf("\n");

    int digits;
    for(digits = 0; maxtile > 0; maxtile = maxtile/10, digits++){}//Check how many digits the highest value has.



    printf("\t\t\t\t\tHIGHEST SCORE: %d\n", record);
    printf("\t\t\t\t\t        SCORE: %d\n", totalPts);
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 4; i++)
            matriz[j][i] != 0 ? printf("%-*d ", digits, matriz[j][i]) : printf("%-*s ", digits, " ");//Print symmetrically in function of the highest value´s digits.
        printf("\n");
    }
    printf("\n");
}
