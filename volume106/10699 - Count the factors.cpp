#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;
#define MAX 1000001
vector<int>primes;

bool p[MAX+2];

void sieveMethod()
{
    p[0] = p[1] = true;

    for(int i = 4; i <= MAX; i += 2)
    {
        p[i] = true;
    }

    int sq = sqrt(MAX);

    for(int i = 3; i <= sq; i+=2)
    {
        if(p[i] == true) continue;
        for(int j = i*i; j <= MAX; j += 2*i)
        {
            p[j] = true;
        }
    }
    primes.push_back(2);
    for(int i = 3; i <= MAX; i+=2)
    {
        if(p[i] == false) primes.push_back(i);
    }

}

int main (void)
{
    sieveMethod();

    int s = primes.size();
    int n, count;
    while(scanf("%d", &n), n)
    {
        int N = n;
        count = 0;
        if(n == 1){
            printf("0\n");
            continue;
        }
        for(int i = 0; i < s; i++)
        {
            if(n%primes[i] == 0)
            {
                count++;
                while(n%primes[i] == 0)
                {
                    n/=primes[i];
                }
            }
            if(n == 1) break;
        }

        printf("%d : %d\n", N, count);
    }
    return 0;

}


