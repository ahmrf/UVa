#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
#define maxN 1000001


using namespace std;

bool isprime[maxN];

void sieve ()
{
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for(int i = 4; i<maxN; i+=2) isprime[i] = false;
    int sqroot = sqrt(maxN);
    for(int i = 3; i < sqroot; i+=2)
        if(isprime[i])
            for(int j = i*i; j<maxN; j+= (2*i))
                isprime[j] = false;


}

int main (void)
{
    sieve();
    int L, U, cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d%d", &L, &U);
        vector<int>P;
        for(int i=L; i<=U; i++)
        {
            if(isprime[i]) P.push_back(i);
        }

        if(P.size() < 2) printf("No jumping champion\n");
        else
        {

            int diff, maxF = 0, last = P.size();
            map<int, int> df;
            for(int i = 1; i < last; i++)
            {
                diff = P[i]-P[i-1];
                df[diff]++;
            }
            vector<int>store;
            for(std::map<int, int> :: const_iterator it = df.begin(); it != df.end(); it++)
            {
                if(it->second > maxF)
                {
                    maxF = it->second;
                    store.clear();
                    store.push_back(it->first);
                }
                else if(it->second == maxF)
                {
                    store.push_back(it->first);
                }

            }
            if(store.size() > 1) printf("No jumping champion\n");
            else printf("The jumping champion is %d\n", store[0]);

        }
    }
    return 0;
}
