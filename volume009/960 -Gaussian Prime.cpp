#include<bits/stdc++.h>
#define maxN 10001

using namespace std;

bool P[maxN];

void sieve()
{
    P[0] = P[1] = true;
    for(int i=4; i<maxN; i+=2) P[i] = true;
    for(int i=3; i*i<maxN; i+=2)
        if(!P[i])
            for(int j=i*i; j<maxN; j+=2*i)
                P[j] = true;
}

bool notprime(int num)
{
    if(num < maxN) return P[num];
    if(num % 2 == 0) return true;
    for(int i=3; i<num; i++)
    {
        if(num%i == 0) return true;
    }
    return false;
}

int main()
{
    sieve();
    int cases, a, b;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d%d", &a, &b);
        if(a && b)
        {
            if(!notprime(a*a + b*b)) puts("P");
            else puts("C");
        }
        else if(a && !b)
        {
            if(!P[a] && a%4==3) puts("P");
            else puts("C");
        }
        else
        {
            if(!P[b] && b%4==3) puts("P");
            else puts("C");
        }
    }
    return 0;
}

