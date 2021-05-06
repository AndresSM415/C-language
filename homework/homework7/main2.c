#include "mysql.h"
#include <time.h>
node* save(node* worker, int c, FILE* fRHr);
node* enterworker(node* worker, char name[], char pin[], int day, clock_t t_total);
node* workersale(node* worker, int day, clock_t t_total);
void savereport(node* worker);

int main()
{
    node *worker = NULL;

    char *RHFile = "RH.txt";
    FILE *fRHr = fopen(RHFile, "r");
    int c;
    while(fscanf(fRHr, "%d", &c) == 1){}
    printf("we have %d workers\n", c);
    worker = save(worker, c, fRHr);
    fclose(fRHr);

    int sigue = 1;
    while(sigue)
    {
        for(int day = 0; day < 7; day++)
        {
            printf("\n Day %d\n", day+1);
            time_t t_start, t_end;
            double t_total = 0;
            time(&t_start);
            while(t_total <= 24)
            {
                time(&t_end);
                t_total  = difftime(t_end, t_start);
                printf("REGISTER (name) (pin): ");
                char name[MAX];
                char pin[PIN];
                scanf("%s %s", name, pin);
                worker = enterworker(worker, name, pin, day, t_total);
            }
            worker = workersale(worker, day, t_total);
            savereport(worker);


        }
    }

    return 0;
}

node* enterworker(node* worker, char name[], char pin[], int day, clock_t t_total)
{
    if(worker != NULL)
    {
        if(strcmp(worker->name, name) == 0 && strcmp(worker->pin, pin) == 0)
        {
            if(!worker->dentro)
            {
                worker->llega[day] = worker->cal[day] - t_total;
                worker->dentro = 1;
                printf("Welcome: %s.\n", worker->name);
            }
            else
            {
                worker->sale[day] = t_total - worker->cal[day] > 0 ? t_total - worker->cal[day] : 0;
                worker->sale[day] > 8 ? worker->sale[day] = 8 : worker->sale[day];
                worker->dentro = 0;
                printf("Goodbye: %s.\n", worker->name);
            }
        }
        else
            worker->child = enterworker(worker->child, name, pin, day, t_total);

    }
    return worker;
}

node* workersale(node* worker, int day, clock_t t_total)
{
    if(worker != NULL)
    {
        if(worker->dentro)
        {
            worker->sale[day] = t_total - worker->cal[day] > 0 ? t_total - worker->cal[day] : 0;
            worker->sale[day] > 8 ? worker->sale[day] = 8 : worker->sale[day];
            worker->dentro = 0;
            printf("Goodbye: %s.\n", worker->name);
        }
        worker->child = workersale(worker->child, day, t_total);

    }
    return worker;
}
void workrprt(node* worker, FILE* rprt);
void savereport(node* worker)
{
    FILE* rprt = fopen("weeklyreport.txt", "w");
    workrprt(worker, rprt);
    fclose(rprt);
}
void workrprt(node* worker, FILE* rprt)
{
    if(worker != NULL)
    {
        fprintf(rprt, "%s:\n", worker->name);
        for(int i = 0; i < 7; i++)
            fprintf(rprt, "%d:%d ", worker->llega[i], worker->sale[i]);
        fprintf(rprt, "\n");
        workrprt(worker->child, rprt);
    }
}
node* save(node* worker, int c, FILE* fRHr)
{
    if(c > 0)
    {
        worker = (node*)malloc(sizeof(node));
        fscanf(fRHr, "%s %s\n", &worker->name, &worker->pin);
        for(int i = 0; i < 7; i++)
        {
            worker->sale[i] = 0;
            worker->llega[i] = 26;
            fscanf(fRHr, "%d", &worker->cal[i]);
        }
        fscanf(fRHr, "\n");
        worker->dentro = 0;
        printf("%s (%s)\n", worker->name, worker->pin);
        worker->child = save(worker->child, c-1, fRHr);
    }
    else
        worker = NULL;
    return worker;
}
