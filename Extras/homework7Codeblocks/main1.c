#include "mysql.h"
node* save(node* worker, int c, FILE* fRHr);
void genpin(char pin[]);
node* addworker(node* worker, char name[], char pin[], int cal[]);
void caltext(node* worker, int c, char RHFile[]);

int main()
{
    node *worker = NULL;

    char *RHFile = "C:\\Users\\Admin\\Downloads\\progra\\RH.txt";
    FILE *fRHr = fopen(RHFile, "r");
    int c;
    while(fscanf(fRHr, "%d", &c) == 1){}
    printf("we have %d workers\n", c);
    worker = save(worker, c, fRHr);
    fclose(fRHr);

    int g = c;
    int sigue = 1;
    while(sigue)
    {
        char name[MAX];
        char pin[PIN];
        int cal[7];

        printf("add another worker (name): ");
        scanf("%s", name);
        g++;
        genpin(pin);
        gencal(cal);
        worker = addworker(worker, name, pin, cal);

        caltext(worker, g, RHFile);

        printf("\n");
        printf("pincode: %s\n", pin);
    }
    return 0;
}

node* save(node* worker, int c, FILE* fRHr)
{
    if(c > 0)
    {
        worker = (node*)malloc(sizeof(node));
        fscanf(fRHr, "%s %s\n", &worker->name, &worker->pin);
        for(int i = 0; i < 7; i++)
            fscanf(fRHr, "%d", &worker->cal[i]);
        fscanf(fRHr, "\n");
        printf("%s (%s)\n", worker->name, worker->pin);
        worker->child = save(worker->child, c-1, fRHr);
    }
    else
        worker = NULL;
    return worker;
}
node* addworker(node* worker, char name[], char pin[], int cal[])
{
    if(worker == NULL)
    {
        worker = (node*)malloc(sizeof(node));
        strcpy(worker->name, name);
        strcpy(worker->pin, pin);
        worker->child = NULL;
        for(int i = 0; i < 7; i++)
        {
            worker->cal[i] = cal[i];
            printf("%d ", worker->cal[i]);
        }
    }
    else
    {
        worker->child = addworker(worker->child, name, pin, cal);
    }
    return worker;
}

void genpin(char pin[])
{
    for(int i = 0; i < PIN-1; i++)
        pin[i] = rand()%10 + '0';
    pin[PIN] = '\0';
    return pin;
}
void gencal(int cal[])
{
    for(int i = 0; i < 7; i++)
    {
        cal[i] = rand()%29;
        cal[i] = cal[i] > 24 ? 25 : cal[i];
        cal[i] = cal[i] > 17 && cal[i] < 25 ? 17 : cal[i];
    }
    printf("\n");
}

void textworker(node* worker, FILE* fRHw);
void caltext(node* worker, int c, char RHFile[])
{
    FILE *fRHw = fopen(RHFile, "w");
    fprintf(fRHw, "%d", c);
    textworker(worker, fRHw);
    fclose(fRHw);
}
void textworker(node* worker, FILE* fRHw)
{
    if(worker != NULL)
    {
        fprintf(fRHw, "\n%s %s\n", worker->name, worker->pin);
        for(int i = 0; i < 7; i++)
        {
            fprintf(fRHw, "%d ", worker->cal[i]);
        }
        textworker(worker->child, fRHw);
    }
}
