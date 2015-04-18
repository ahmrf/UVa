#include<bits/stdc++.h>
#define maxN 250001
using namespace std;

bool is_prime[maxN];
int primes[25010];
long double fibonacci[250010];

void sieve()
{
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for(int i=4; i<maxN; i+=2)
        is_prime[i] = false;
    for(int i=3; i<=500; i+=2)
        if(is_prime[i])
            for(int j=i*i; j<maxN; j+= (2*i))
                is_prime[j] = false;
    int c = 1;
    for(int i=2; i<maxN; i++)
        if(is_prime[i])
            primes[c++] = i;
}


int main()
{
    sieve();
    primes[1] = 3;
    primes[2] = 4;

    memset(fibonacci, 0, sizeof(fibonacci));
    fibonacci[0] = fibonacci[1] = 1;

    int flag = 0;
    for(int i=2; i<maxN; i++)
    {
        if(flag==1)
        {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2] / 10;
            flag = 0;
        }
        else
        {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
            flag = 0;
        }
        if(fibonacci[i]>1e9)
        {
            fibonacci[i]/=10;
            flag = 1;
        }
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",(int)fibonacci[primes[n]-1]);
    }
    return 0;
}

