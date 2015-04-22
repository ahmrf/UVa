#include<stdio.h>
#include<math.h>


int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int ifPair(long long a, long long b, long long n)
{
    return ((a*b)/gcd(a,b)) == n ? 1:0;
}

int main (void)
{
    int n, factors[10000];
    while(scanf("%d", &n), n)
    {
        int count = 0, k = 0, i, j, sq = sqrt(n);
        for(i=1; i<=sq; i++)
        {
            if(n%i == 0)
            {
                factors[k] = i;
                k++;
                if(i != n/i)
                {
                    factors[k] = n/i;
                    k++;
                }
            }
        }

        for(i=0; i<k; i++)
        {
            for(j=i; j<k; j++)
            {
                count+= ifPair(factors[i], factors[j], n);
            }
        }


        printf("%d %d\n", n, count);
    }
    return 0;
}
