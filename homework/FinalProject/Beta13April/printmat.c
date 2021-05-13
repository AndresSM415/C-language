void printmat(int** matriz)
{
    for(int j = 0; j < 4; j++)
    {
        for(int i = 0; i < 4; i++)
            printf("%d ", matriz[j][i]);
        printf("\n");
    }
}
