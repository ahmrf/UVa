#include<stdio.h>

int main(void)
{
    long long N, a, t, max;
    while(scanf("%lld", &N), N)
    {
        t = max = 0;
        while(N--)
        {
            scanf("%lld", &a);
            t += a;
            if(t < 0) t = 0;
            if(t > max) max = t;
        }

        if(max) printf("The maximum winning streak is %lld.\n", max);
        else printf("Losing streak.\n");
    }
    return 0;
}

