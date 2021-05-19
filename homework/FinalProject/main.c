//2048 game.
//You need 5 files: main.c, my2048.h, stickandsum.c, startRand.c, and printmat.c. Then execute and enjoy.
//To play select one WASD key to stack tiles. W: top, A: left, S: bottom, D: right.
#include "my2048.h"
char* fileAddress = "record.txt";

void newRecord(int**);
int matrizRoom(int**);
int main()
{
    printf("2048 game. \nTo play select one WASD key to stack tiles. \nW: top, A: left, S: bottom, D: right.\n");
    int record = 0;
    FILE* recFile;
    if(!(recFile = fopen(fileAddress, "r")))//If File doesn´t exist, create one.
    {
        recFile = fopen(fileAddress, "w");
        fprintf(recFile, "%d", 0);
    }
    else
        fscanf(recFile, "%d", &record);//Save current record.

    fclose(recFile);

    int** matriz;
    matriz = (int**)malloc(sizeof(int*)*4);//Create matrix space.
    for(int j = 0; j < 4; j++)
    {
        matriz[j] = (int*)malloc(sizeof(int)*4);
        for(int i = 0; i < 4; i++)
            matriz[j][i] = 0;
    }
    startRand(matriz);//Generate a random location to place a 2.
    printMat(matriz, record);//Print matrix.

    while(matrizRoom(matriz))//If you haven´t lose yet.
    {
        if(moveMatriz(matriz))//Stack and add matrix.
            startRand(matriz);
        printMat(matriz, record);
    }

    printf("You've lose.");
    newRecord(matriz);//Register score if it´s bigger than current record.
    for(int i = 0; i < 4; i++)//Free matrix.
        free(matriz[i]);
    free(matriz);
    return 0;
}
void newRecord(int** matriz)//If points gotten in all tiles are bigger than the current record, then save it.
{
    int totalPts = 0;
    for(int j = 0; j < 4; j++)
        for(int i = 0; i < 4; i++)
            totalPts += matriz[j][i];//Sum all tiles.

    int record;
    FILE* recFileR = fopen(fileAddress, "r");//Read current record.
    fscanf(recFileR, "%d", &record);
    fclose(recFileR);

    if(totalPts > record)
    {
        recFileR = fopen(fileAddress, "w");
        fprintf(recFileR, "%d", totalPts);
        fclose(recFileR);
    }
}
int matrizRoom(int** matriz)//If there are valid moves in matrix.
{
    for(int j = 0; j < 4; j++)
        for(int i = 0; i < 4; i++)
            if(matriz[j][i] == 0 || (i < 3 && matriz[j][i] == matriz[j][i+1]) || (j < 3 && matriz[j][i] == matriz[j+1][i]))//If there´s at least a 0 tile or two neighbor tiles with same value.
                return 1;
    return 0;
}
