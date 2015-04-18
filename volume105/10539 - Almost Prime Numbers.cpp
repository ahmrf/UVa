#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>

#define maxN 1000001
#define INF 2000000000

using namespace std;

vector<long long>ap;
bool isPrime[maxN];

void Sieve()
{
   memset(isPrime, true, sizeof(isPrime));
   isPrime[0] = isPrime[1] = false;
   for (int i=2, lm=(int)sqrt(maxN); i<=lm; i++)
      if (isPrime[i]) for (int j=i*i; j<maxN; j+=i)
         isPrime[j] = false;


}


int main (void)
{
    Sieve();
    long long int i, j;
    for(i=2;i<=1000000;i++)
        if(isPrime[i])
            for(j=i*i;j<=1000000000000;j*=i)
                ap.push_back(j);
    sort(ap.begin(), ap.end());
    long long int l, u;
    int cases, lamba = ap.size();

    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lld%lld", &l, &u);
        int c = 0;
        for(int k=0; k<lamba && ap[k]<=u; k++)
        {
            if(ap[k]<=u && ap[k]>=l) c++;
        }

        printf("%d\n", c);
    }
}

