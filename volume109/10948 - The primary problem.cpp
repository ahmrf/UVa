#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>

#define maxN 1000001
#define INF 2000000000

using namespace std;
vector<int>prime;
bool isPrime[maxN];

void Sieve()
{
   memset(isPrime, true, maxN);
   isPrime[0] = isPrime[1] = false;
   for (int i=2, lm=(int)sqrt(maxN); i<=lm; i++)
      if (isPrime[i]) for (int j=i*i; j<maxN; j+=i)
         isPrime[j] = false;
   prime.push_back(2);
   for(int i = 3; i<maxN; i+=2)
      if (isPrime[i]) prime.push_back(i);
}

int main (void)
{
    Sieve();
    int n, s = prime.size();
    while(scanf("%d", &n), n)
    {
        bool flag = true;
        int l = n/2;
        printf("%d:\n", n);
        for(int i=0; i<s && prime[i]<=l; i++)
        {
            if(isPrime[n-prime[i]])
            {
                flag = false;
                printf("%d+%d\n", prime[i], n-prime[i]);
                break;
            }
        }

        if(flag) printf("NO WAY!\n");
    }

    return 0;
}
