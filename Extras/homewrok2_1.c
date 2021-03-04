#include <stdio.h>
#include <math.h>
int main()
{
    int g, entero, iprime, K;

    printf("How many prime numbers you want?: ");
    scanf("%d", &K);
    int prime[K];

    for(int i = 2.0; iprime < K; i++)
    {
        for(g = 2.0; g < i; g++)
            if(i%g == 0)
                break;

        if(g == i)
            prime[iprime++] = i;
    }
    int digits = log(prime[K-1])/log(2)+1;
    printf("digits: %d\n\n", digits);

    for(int iprime = 0; iprime < K; iprime++)
    {
        for(int i = digits; i > 0; i--)
            printf("%d",(prime[iprime] >> i-1) & 1);
        printf(" | %d\n", prime[iprime]);
    }
    return 0;
}
