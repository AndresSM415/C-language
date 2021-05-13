
void stickmatriz(int** matriz, int j, int i, int dim);
void sumpairs(int** matriz, int j, int i, int dim);
void stickandsum(int** matriz, int j, int i, int dim)
{
    stickmatriz(matriz, j, i, dim);
    sumpairs(matriz, j, i, dim);
    stickmatriz(matriz, j, i, dim);
}

void stickmatriz(int** matriz, int j, int i, int dim)
{
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
    for(int times = 0; times < 3; times++)
        for(j = 0; j < 4; j++)
            for(*iptr = ibegin; *i1 <= *i2; *iptr += iPosNeg)
                if(matriz[*x][*y] == 0)
                {
                    iNext = *i1 != *i2 ? i+iPosNeg : i;
                    matriz[*x][*y] = matriz[*xNxt][*yNxt];
                    matriz[*xNxt][*yNxt] = 0;
                }
}

void sumpairs(int** matriz, int j, int i, int dim)
{
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
            if(*i1 != *i2 && matriz[*x][*y] == matriz[*xNxt][*yNxt])
            {
                matriz[*x][*y] *= 2;
                matriz[*xNxt][*yNxt] = 0;
            }
        }
}
