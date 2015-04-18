#include<stdio.h>

int main (void)
{
    long long int a;
    while(scanf("%lld", &a) && !(a < 0))
    {
        printf("%lld\n", (a*(a+1)/2)+1);
    }
    return 0;
}
