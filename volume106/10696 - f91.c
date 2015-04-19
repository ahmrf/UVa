#include<stdio.h>


int main (void)
{
    int N;
    while(scanf("%d",&N))
    {
        if(N == 0) break;

        if(N <= 100) printf("f91(%d) = 91\n", N);
        else printf("f91(%d) = %d\n", N, N-10);
    }
    return 0;
}
