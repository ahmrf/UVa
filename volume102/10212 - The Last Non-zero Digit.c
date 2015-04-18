#include<stdio.h>

int main (void)
{
    long long N, M, ans;
    while(scanf("%lld%lld", &N, &M)==2)
    {
        if(M==0) printf("1\n");
        else
        {
            long long i, c = N-M+1;
            ans=1;
            for(i=N; i>=c; i--)
            {
                ans *= i;
                while(ans%10==0) ans/=10;
                ans %= 1000000000;
            }
            printf("%lld\n", ans%10);
        }
    }
    return 0;
}
