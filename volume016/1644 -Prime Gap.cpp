#include<cstdio>
#include<cmath>
#include<vector>
#define maxN 1300000

using namespace std;

bool P[maxN];
int G[maxN];
vector<int>primes;

void sieve()
{
    int sq = sqrt(maxN);
    P[0] = P[1] = true;
    for(int i = 4; i<maxN; i+=2)
        P[i] = true;
    for(int i = 3; i<sq; i+=2)
        if(!P[i])
            for(int j = i*i; j<maxN; j+= 2*i)
                P[j] = true;

    G[0] = G[1] = 0;
    primes.push_back(2);
    for(int i = 3; i<maxN; i+=2)
        if(!P[i])
            primes.push_back(i);

    int k = 0;
    for(int i = 2; i<maxN; i++)
    {
        if(!P[i]) G[i] = 0;
        else
        {
            if(i > primes[k+1]) k++;
            G[i] = primes[k+1]-primes[k];
        }

    }

}

int main()
{
    sieve();
    int n;
    while(scanf("%d", &n), n)
        printf("%d\n", G[n]);

    return 0;
}
