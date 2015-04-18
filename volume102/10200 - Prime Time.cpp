#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#define maxN 31623
#define pb push_back

using namespace std;

bool p[maxN];
vector<int>prime;

void Sieve() {
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for (int i=4; i<maxN; i+=2) p[i] = false;
    for (int i=3; i*i<maxN; i+=2)
        if (p[i]) for (int j=i*i; j<maxN; j+=i+i)
            p[j] = false;
    prime.pb(2);
    for (int i=3; i<maxN; i+=2)
        if (p[i]) prime.pb(i);
}


bool isPrime(int num)
{
    if(num < maxN) return p[num];
    int rt = (int) sqrt(num);
    for(int i = 0; i< prime.size() && prime[i] <= rt; i++)
    {
        if(num % prime[i] == 0) return false;
    }
    return true;

}

int main (void)
{
    Sieve();
    bool euler[10000+10];
    memset(euler, false, sizeof(euler));
    for(int i = 0; i <= 10000; i++)
    {
        int num = i*i + i + 41;
        if(isPrime(num))
        {
            euler[i] = true;
        }
    }

    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)
    {
        int c = 0;
        for(int i = a; i <= b; i++)
        {
            if(euler[i]) c++;
        }

        printf("%.2lf\n", ((double)c*100.0)/double(b-a+1) + 1e-9);
    }
    return 0;
}


