#include<stdio.h>

int main (void)
{
    unsigned long long fib[60];
    int cases, i, n;;
    fib[0] = 1;
    fib[1] = 2;
    for(i = 2; i < 52; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    scanf("%d", &cases);
    for(i = 1; i <= cases; i++)
    {
        scanf("%d", &n);
        printf("Scenario #%d:\n%llu\n\n", i, fib[n]);
    }

    return 0;
}
