#include <stdio.h>
#include <math.h>
int main()
{
    int K = 10;
    float cimal, g;
    int entero, iprime, isprime = 1;
    int prime[K];

    for(float i = 2.0; iprime < K; i++)
    {
        for(g = 2.0; g < i; g++)
        {
            cimal = i/g;
            entero = cimal;
            if(cimal - entero == 0)
                break;
        }
        if(g == i)
            prime[iprime++] = i;
    }
    printf("Primos registrados:\n");
    for(iprime = 0; iprime < K; iprime++)
        printf("%d\n", prime[iprime]);

    int digits = log(prime[K-1])/log(2)+1;
    printf("digitos: %d\n", digits);
    char bit[K][digits];
    char num5[5];
    for(int i = 5; i > 0; i--)
    {
        num5[i] = ((5 >> i-1) & 1);
        printf("%d",num5[i]);
    }
