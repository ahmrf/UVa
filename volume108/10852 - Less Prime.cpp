#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>
#define maxN 20000
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

int main (void)
{
    Sieve();
    int s = prime.size();
    int cases, num;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &num);
        for(int i = 0; i < s && prime[i] <= num; i++)
        {
            if(prime[i] <= num && 2*prime[i] > num)
            {
                printf("%d\n", prime[i]);
                break;
            }
        }
    }
    return 0;
}


