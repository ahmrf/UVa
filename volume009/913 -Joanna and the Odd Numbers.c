#include<stdio.h>

int main (void)
{
    long long int N;
    while(scanf("%lld", &N) != EOF)
    {
        long long int n = (N+1)/2;
        long long int value = 2*n*n - 4*n + 3;
        long long lastValue = value + (N - 1) * 2;
        printf("%lld\n", 3*lastValue - 6);
    }
    return 0;
}

