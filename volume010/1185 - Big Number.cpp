#include<cstdio>
#include<cmath>

double aha[10000001];

int main (void)
{
    int N, i;
    double hehe = 0;
    for(i=1; i<10000001; i++)
    {
        hehe += log(i);
        aha[i] = hehe;
    }

    int cases;
    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d", &N);
        double ans = aha[N];

        ans/=log(10);ans+=1.0;
        ans=floor(ans);
        printf("%.0lf\n", ans);
    }
    return 0;
}
