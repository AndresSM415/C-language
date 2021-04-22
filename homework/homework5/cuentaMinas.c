extern int MI;
void cuentaMinas(int** minas)
{
    void minasvecinas(int** minas, int j, int i);
    for(int j = 0; j < MI; j++)
        for(int i = 0; i < MI; i++)
            if(minas[j][i] == 9)
                minasvecinas(minas, j, i);
}

void minasvecinas(int** minas, int j, int i)
{
    int jend = j+1 < MI ? j + 1 : j;
    j = j > 0 ? j - 1 : j;

    int iend = i+1 < MI ? i + 1 : i;
    i = i > 0 ? i - 1 : i;
    int que = i;
    for(; j <= jend; j++)
    {
        for(que = i; que <= iend; que++)
            if(minas[j][que] < 9)
                minas[j][que]++;
    }
}
