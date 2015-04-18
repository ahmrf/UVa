#include<stdio.h>
int main (void)
{
    long long int i, fibonacci[51];
    fibonacci[0] = 1;
    fibonacci[1] = 1;
    fibonacci[2] = 2;
    for(i=3; i<51; i++)
    {
        fibonacci[i] = fibonacci[i-1]+fibonacci[i-2];
    }
    int N;
    while(scanf("%d", &N), N)
    {
        printf("%lld\n", fibonacci[N]);
    }
    return 0;
}
