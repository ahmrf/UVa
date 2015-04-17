#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
#define MAX 3000

bool p[MAX];

void sieveMethod()
{
    p[0] = p[1] = true;

    for(int i = 4; i < MAX; i += 2)
    {
        p[i] = true;
    }

    int sq = sqrt(MAX);

    for(int i = 3; i < sq; i+=2)
    {
        if(p[i] == true) continue;
        for(int j = i+i; j < MAX; j += i)
        {
            p[j] = true;
        }
    }

}

int main(void)
{
    sieveMethod();
    vector<int>primes;
    primes.push_back(1);
    for(int i = 2; i <= 3000; i++)
    {
        if(p[i] == false) primes.push_back(i);
    }
    int len = primes.size();
    int N, C;
    while(scanf("%d%d", &N, &C) == 2)
    {
        int n;
        int c = C;
        for(int i = 0; i < len; i++)
        {
            if(N >= primes[i])
            {
                n = i;
            }

            else break;
        }

        if((c*2)>(n+1))
        {
            printf("%d %d:",N,c);
            for(int j=0;j<=n;j++)
                printf(" %d",primes[j]);
        }

        else
        {
            printf("%d %d:",N,c);
            for(int j = n/2+1-c; j <= n/2+c-1; j++)
                printf(" %d",primes[j]);
            if(n%2 == 1) printf(" %d",primes[n/2+c]);
        }
        printf("\n\n");
    }

}
