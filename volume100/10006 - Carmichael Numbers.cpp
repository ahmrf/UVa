#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#define maxN 65001
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
}


long long Mod(long long x, int n, int M)
{
    if(n == 0) return 1;
    else if(n%2 == 0)
    {
        long long y = Mod(x, n/2, M);
        return (y*y) % M;
    }

    else return ((x%M) * Mod(x, n-1, M)) % M;
}

bool isCarmichael(long long int num)
{
    if(p[num]) return false;
    for(int i = 2; i < num; i++)
    {
        if(Mod(i, num, num) != i) return false;
    }
    return true;
}


int main (void)
{
    Sieve();
    int num;
    while(scanf("%d", &num), num)
    {
        if(isCarmichael(num)) printf("The number %d is a Carmichael number.\n", num);
        else printf("%d is normal.\n", num);
    }
    return 0;
}
