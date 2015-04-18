#include<bits/stdc++.h>
#define maxN 47000

using namespace std;

bool P[maxN];
bool range[1000001];
vector<int> primes;
void sieve()
{
    memset(P, true, sizeof P);
    P[0] = P[1] = false;
    for(int i=4; i<maxN; i+=2) P[i] = false;
    for(int i=3; i*i<maxN; i+=2)
        if(P[i])
            for(int j=i*i; j<maxN; j+=2*i)
                P[j] = false;

    for(int i=2; i<maxN; i++)
        if(P[i])
            primes.push_back(i);
}

bool is_prime(int N)
{
    if(N < maxN) return P[N];
    for(int i=0; i<primes.size(); i++)
    {
        if(N%primes[i] == 0) return false;
    }
    return true;
}

int main()
{
    sieve();
    int L, U;
    while(scanf("%d%d", &L, &U) == 2)
    {
        memset(range, false, sizeof range);
        for(int i=L; i<=U; i++)
        {
            if(is_prime(i))
                range[i-L] = true;
        }
        int a = -1, b = -1, max = 0, min = 2e9, maxA, maxB, minA, minB;
        for (int i = 0; i <= U - L; i++)
        {
            if (range[i])
            {
                a = i;
                if (b != -1)
                {
                    if (a - b > max) max = a - b, maxA = b, maxB = a;
                    if (a - b < min) min = a - b, minA = b, minB = a;
                }
                b = a;
            }
        }
        if (!max) puts("There are no adjacent primes.");
        else printf("%d,%d are closest, %d,%d are most distant.\n", minA+L, minB +L, maxA+L, maxB+L);
    }
    return 0;
}

