extern int MI;
int coordenada(int *j, int *i)
{
    int flag = 0;
    *j = 0;
    int c;
    printf("selecciona comando: ");
    while((c = getchar()) != '\n')
        if(isalpha(c) && (tolower(c) >= 'a' && tolower(c) <= 'a' + MI))
            *i = tolower(c) - 'a';
        else if(isdigit(c))
        {
            *j = *j*10 + c - '0';
            flag = *j > MI ? -1 : flag;
        }
        else if(c == '!')
            flag = 1;
        else
        {
            printf("intenta de nuevo.\n");
            flag = -1;
        }
    *j = *j - 1;
    return flag;
}
