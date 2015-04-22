#include<bits/stdc++.h>
#define maxN 1000001

using namespace std;

bool is_prime[maxN];
vector<int> primes;
int mu[maxN];
int M[maxN];

void sieve()
{
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for(int i=4; i<maxN; i+=2)
        is_prime[i] = false;
    for(int i=3; i*i<maxN; i+=2)
        if(is_prime[i])
            for(int j=i*i; j<maxN; j+= (2*i))
                is_prime[j] = false;
    primes.push_back(2);
    for(int i=3; i<maxN; i+=2)
        if(is_prime[i])
            primes.push_back(i);
}

void factorCount(int N)
{
    int num = N;
    int sqroot = sqrt(num);
    if(sqroot * sqroot == num)
    {
        mu[N] = 0;
        return;
    }

    bool squareFree = true;
    int countFactors = 0;
    for(int i=0; primes[i]<=sqroot; i++)
    {
        if(num%primes[i] == 0)
        {
            num /= primes[i];
            while(num % primes[i] == 0)
            {
                squareFree = false;
                break;
            }
            if(!squareFree)
            {
                mu[N] = 0;
                return;
            }
            countFactors++;
        }
    }
    if(num > 1) countFactors++;
    if(countFactors%2) mu[N] = -1;
    else mu[N] = 1;
    return;
}

int main()
{
    sieve();
    mu[1] = M[1] = 1;
    for(int i=2; i<maxN; i++)
    {
        if(is_prime[i])
            mu[i] = -1;
        else factorCount(i);
        M[i] = M[i-1] + mu[i];
    }

    int N;
    while(scanf("%d", &N), N)
    {
        printf("%8d%8d%8d\n", N, mu[N], M[N]);
    }
    return 0;
}

