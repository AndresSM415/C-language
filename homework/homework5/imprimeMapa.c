extern int MI;
void imprimeMapa(char** mapa)
{
    printf("A B C D E F G H I J\n");
    for(int j = 0; j < MI; j++)
    {
        for(int i = 0; i < MI; i++)
            printf("%c ", mapa[j][i] == '0' ? mapa[j][i] = ' ' : mapa[j][i]);
        printf("%d\n", j+1);
    }
}
