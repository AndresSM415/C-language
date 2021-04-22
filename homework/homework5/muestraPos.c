extern int MI;
int muestraPos(int** minas, char ** mapa, int j, int i, int flag)
{
    int noMine = MI*MI - MI;
    if(flag == 1 && mapa[j][i] != '0' + minas[j][i])
    {
        mapa[j][i] = mapa[j][i] == '#' ? '!' : '#';
    }
    else if(flag == 0)
    {
        switch (minas[j][i])
        {
        case 0:
            mapa[j][i] = ' ';
            revela(minas, mapa, j, i);
            break;
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
            mapa[j][i] = '0' + minas[j][i];
            break;
        case 9:
            mapa[j][i] = 'X';
            return -1;
            break;
        default:
            break;
        }
        noMine--;
    }
    if(noMine == 0)
        return 1;
    return 0;
}

void revela(int** minas, char** mapa, int j, int i)
{
    int i2 = i-1 >= 0 ? i-1 : i;
    if(minas[j][i2] == 0 && (mapa[j][i2] == '#' || mapa[j][i2] == '!'))
    {
        mapa[j][i2] = ' ';
        revela(minas, mapa, j, i2);
    }
    else if(mapa[j][i2] == '#' || mapa[j][i2] == '!')
        mapa[j][i2] = minas[j][i2] + '0';

    i2 = i+1 < MI ? i+1 : i;
    if(minas[j][i2] == 0 && (mapa[j][i2] == '#' || mapa[j][i2] == '!'))
    {
        mapa[j][i2] = ' ';
        revela(minas, mapa, j, i2);
    }
    else if(mapa[j][i2] == '#' || mapa[j][i2] == '!')
        mapa[j][i2] = minas[j][i2] + '0';

    int j2 = j-1 >= 0 ? j-1 : j;
    if(minas[j2][i] == 0 && (mapa[j2][i] == '#' || mapa[j2][i] == '!'))
    {
        mapa[j2][i] = ' ';
        revela(minas, mapa, j2, i);
    }
    else if(mapa[j2][i] == '#' || mapa[j2][i] == '!')
        mapa[j2][i] = minas[j2][i] + '0';

    j2 = j+1 < MI ? j+1 : j;
    if(minas[j2][i] == 0 && (mapa[j2][i] == '#' || mapa[j2][i] == '!'))
    {
        mapa[j2][i] = ' ';
        revela(minas, mapa, j2, i);
    }
    else if(mapa[j2][i] == '#' || mapa[j2][i] == '!')
        mapa[j2][i] = minas[j2][i] + '0';

    j2 = j-1 >= 0 ? j-1 : j;
    i2 = i-1 >= 0 ? i-1 : i;
    if(mapa[j2][i2] == '#' || mapa[j2][i2] == '!')
        mapa[j2][i2] = minas[j2][i2] + '0';

    j2 = j-1 >= 0 ? j-1 : j;
    i2 = i+1 < MI ? i+1 : i;
    if(mapa[j2][i2] == '#' || mapa[j2][i2] == '!')
        mapa[j2][i2] = minas[j2][i2] + '0';

    j2 = j+1 < MI ? j+1 : j;
    i2 = i-1 >= 0 ? i-1 : i;
    if(mapa[j2][i2] == '#' || mapa[j2][i2] == '!')
        mapa[j2][i2] = minas[j2][i2] + '0';

    j2 = j+1 < MI ? j+1 : j;
    i2 = i+1 < MI ? i+1 : i;
    if(mapa[j2][i2] == '#' || mapa[j2][i2] == '!')
        mapa[j2][i2] = minas[j2][i2] + '0';
}
