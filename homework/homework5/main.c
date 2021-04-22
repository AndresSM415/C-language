#include "minesweeper.h"
int MI = 10;

int main()
{
    while(1)
    {
    char** mapa;
    int** minas;

    minas = (int**)malloc(sizeof(int*)*MI);
    mapa = (int**)malloc(sizeof(int*)*MI);
    for(int j = 0; j < MI; j++)
    {
        minas[j] = (int*)malloc(sizeof(int)*MI);
        mapa[j] = (int*)malloc(sizeof(int)*MI);
        for(int i = 0; i < MI; i++)
        {
            minas[j][i] = 0;
            mapa[j][i] = '#';
        }
    }
    for(int j = 0; j < MI; j++)
    {
        for(int i = 0; i < MI; i++)
        {
            minas[j][i] = 0;
            mapa[j][i] = '#';
        }
    }
    
    printf("*Buscaminas*\nPara enviar una coordenada escribe una letra(columnas) y un numero(filas)\nPara guardar una posicion escribe un '!' antes de la coordenada ej. !e5\ncuantas minas quieres?: \n");
    int c, noMinas = 0;
    while(isdigit(c = getchar()))
        noMinas = noMinas*10 + c - '0';
    for(int i = 0; i <= noMinas; i++)
        minas[rand()%10][rand()%10] = 9;

    cuentaMinas(minas);
    while(1)
    {
    int j, i, estado, coordenadas;
    while((coordenadas =coordenada(&j, &i)) == -1){}
    if((estado = muestraPos(minas, mapa, j, i, coordenadas)) == -1)
    {
        printf("perdiste!\n");
        imprimeMapa(mapa);
        break;
    }
    else if(estado == 1)
    {
        printf("ganaste!\n");
        break;
    }

    imprimeMapa(mapa);
    }
    for(int j = 0; j < MI; j++)
    {
        free(minas[j]);
        free(mapa[j]);
    }
    free(minas);
    free(mapa);
    }
    return 0;
}
