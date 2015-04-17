#include<stdio.h>
#include<math.h>

int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}


int main (void)
{
    int a[100], n, i, j, total, count;
    while(scanf("%d", &n), n)
    {
        total = n*(n-1)/2;
        count = 0;
        for(i = 0; i < n; i++) scanf("%d", &a[i]);
        for(i = 0; i < n-1; i++)
        {
            for(j = i+1; j < n; j++)
            {
                if(gcd(a[i], a[j]) == 1) count++;
            }
        }

        if(count) printf("%.6lf\n", sqrt((double)total*6.0/(double)count));
        else printf("No estimate for this data set.\n");
    }
    return 0;
}
