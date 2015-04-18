#include <bits/stdc++.h>
#define maxN 10001

using namespace std;

bool isprime[maxN];
int primes[1230];
int len;
int dP[6000000] = {0};

void sieve()
{
	memset(isprime, true, sizeof(isprime));
	isprime[0] = isprime[1] = false;
	for(int i = 4; i < maxN; i += 2)
	{
		isprime[i] = false;
	}
	int s = sqrt(maxN);
	for(int i = 3; i < s; i += 2)
	{
		if(isprime[i])
		{
			for(int j = i*i; j < maxN; j+= 2*i)
			{
				isprime[j] = false;
			}
		}
	}
	len = -1;
	primes[++len] = 0;
	primes[++len] = 2;
	int t = 2;
	for(int i = 3; i < maxN; i += 2)
	{
		if(isprime[i])
		{
			primes[++len] = i;
			primes[len] += primes[len-1];
		}
	}
}

int main()
{
	sieve();
	for(int i = 1; i <= len; i++)
	{
		for(int j = 0; j < i; j++)
		{
			dP[primes[i] - primes[j]]++;
		}
	}

	int n;
	while(scanf("%d", &n) == 1 && n)
	{
		printf("%d\n", dP[n]);
	}
	return 0;
}