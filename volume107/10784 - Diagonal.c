#include<stdio.h>
#include<math.h>

int main (void)
{
    long long int n;
    int cases = 1;
    while(scanf("%lld", &n) == 1 && n)
    {
        double y = (3.000000+ sqrt(9.00000+8.0000000*n))/2.000000;
        long long int ans = y;
        if(ans != y) ans++;
        printf("Case %d: %lld\n", cases++, ans);
    }
    return 0;
}
