#include "my2048.h"
void startRand(int** matriz)
{
    time_t timenow;
    time(&timenow);
    struct tm *tiempo = localtime(&timenow);

    time_t t;
    time(&t);

    //printf("si: %d\n", (t/2 + tiempo->tm_sec)%4);
    //printf("si: %d\n", (tiempo->tm_min + rand() + tiempo->tm_sec)%4);
    int i = (tiempo->tm_min + rand() + tiempo->tm_sec)%4;
    int j = (t/2 + tiempo->tm_sec)%4;//check
    //int j = (t+tiempo->tm_sec + rand())%4;

    int randm = tiempo->tm_sec%5;
    if(randm < 4)
        matriz[j][i] = 2;
    else
        matriz[j][i] = 4;
    FILE* regist = fopen("C:\\Users\\andre\\OneDrive\\Documents\\UANL\\MATERIAS\\PROGRA\\homeworks\\2048\\2048\\record.txt", "a");
    fprintf(regist, "[%d][%d]\n", j, i);
    fclose(regist);
}
