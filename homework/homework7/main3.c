#include "mysql.h"
node* saveRH(node* worker, int c, FILE* fRHr);
node* saverprt(node* worker, int c, FILE* rprt);
node* reporta(node* worker);
int main()
{
    printf("This is the Report of the Week\n");
    printf("A day is represented by 24 seconds.\n");
    printf("L = late; E = early; A = absent; N/A = free day.\n");
    node *worker = NULL;

    char *RHFile = "RH.txt";
    FILE *fRHr = fopen(RHFile, "r");
    int c;
    while(fscanf(fRHr, "%d", &c) == 1){}
    printf("We have %d workers\n", c);
    worker = saveRH(worker, c, fRHr);
    fclose(fRHr);

    FILE* rprt = fopen("weeklyreport.txt", "r");
    worker = saverprt(worker, c, rprt);
    fclose(rprt);

    worker = reporta(worker);

    return 0;
}

node* reporta(node* worker)
{
    if(worker != NULL)
    {
        printf("\n\n%s:\n", worker->name);
        printf("\tlun\tmar\tmie\tjue\tvie\tsab\tdom\n");
        printf("sched:  ");
        for(int i = 0; i < 7; i++)
        {
            if(worker->cal[i] == 25)
                printf("N/A\t");
            else
                printf("%.2d\t", worker->cal[i]);
        }
        printf("\nattndc: ");
        for(int i = 0; i < 7; i++)
        {
            if(worker->cal[i] == 25)
                printf("N/A\t");
            else if(worker->llega[i] <= 0)
            {
                printf("E:%.2d\t", worker->cal[i] + worker->llega[i]);
            }
            else if(worker->llega[i] > 0 && worker->llega[i] <= 24)
                printf("L:%.2d\t", worker->cal[i] + worker->llega[i]);
            else if(worker->llega[i] == 26)
                printf(" A\t");
        }
        printf("\nHours:  ");
        int thours = 0;
        for(int i = 0; i < 7; i++)
        {
            thours += worker->sale[i];
            printf("% d \t", worker->sale[i]);
        }
        printf("\n\tTotal Hours: %d", thours);
        worker->child = reporta(worker->child);

    }
    return worker;
}

node* saveRH(node* worker, int c, FILE* fRHr)
{
    if(c > 0)
    {
        worker = (node*)malloc(sizeof(node));
        fscanf(fRHr, "%s %s\n", &worker->name, &worker->pin);
        for(int i = 0; i < 7; i++)
        {
            fscanf(fRHr, "%d", &worker->cal[i]);
        }
        fscanf(fRHr, "\n");
        worker->child = saveRH(worker->child, c-1, fRHr);
    }
    else
        worker = NULL;
    return worker;
}

node* saverprt(node* worker, int c, FILE* rprt)
{
    if(c > 0)
    {
        char temp[MAX];
        fscanf(rprt, "%s:\n", temp);
        for(int i = 0; i < 7; i++)
        {
            fscanf(rprt, "%d:%d\n", &worker->llega[i], &worker->sale[i]);
        }
        worker->child = saverprt(worker->child, c-1, rprt);
    }
    return worker;
}
