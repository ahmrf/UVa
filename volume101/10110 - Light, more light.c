#include<stdio.h>
#include<math.h>
int main (void)
{
    long long N, sq;
    while(scanf("%lld", &N), N)
    {
        sq = sqrt(N);
        printf((sq*sq == N)? "yes\n" : "no\n");
    }
    return 0;
}
