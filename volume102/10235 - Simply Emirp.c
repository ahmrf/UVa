#include <stdio.h>
#include <math.h>

int reverse(int N)
{
    int r = 0;
    while(N)
    {
        r = r*10 + N%10;
        N /= 10;
    }
    return r;
}

int isprime(int N)
{
    if(N == 2) return 1;
    if(N%2 == 0 || N == 1) return 0;
    int sq = sqrt(N), i;
    for(i = 3; i <= sq; i+=2)
    {
        if(N%i == 0) return 0;
    }
    return 1;
}

int main()
{
    int N;
    while(scanf("%d", &N) != EOF)
    {
        if(isprime(N))
        {
            int r = reverse(N);
            if(r == N) printf("%d is prime.\n", N);
            else if(isprime(r)) printf("%d is emirp.\n", N);
            else printf("%d is prime.\n", N);
        }
        else printf("%d is not prime.\n", N);
    }
    return 0;
}