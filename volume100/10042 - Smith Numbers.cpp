#include <bits/stdc++.h>
#define maxN 100001

using namespace std;

bool isprime[maxN];
int primes[9592];
int len;

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
	primes[++len] = 2;
	for(int i = 3; i < maxN; i += 2)
	{
		if(isprime[i])
		{
			primes[++len] = i;
		}
	}
}

bool itsprime(unsigned long long N)
{
	if(N < maxN) return isprime[N];
	int s = sqrt(N);
	for(int i = 0; i <= len && primes[i] <= s; i++)
	{
		if(N % primes[i] == 0) return false;
	}
	return true;
}

int sumdigits(unsigned long long N)
{
	int sum = 0;
	while(N)
	{
		sum += N%10;
		N /= 10;
	}
	return sum;
}

unsigned long long smith(int N)
{
	unsigned long long smith = N + 1;
	while(true)
	{
		if(!itsprime(smith))
		{
			int sumoffactors = 0;
			unsigned long long int s = sqrt(smith), n = smith;

			for(int i = 0; i <= len && primes[i] <= s; i++)
			{
				while(n%primes[i] == 0)
				{
					sumoffactors += sumdigits(primes[i]);
					n /= primes[i];
				}
			}
			if(n > 1) sumoffactors += sumdigits(n);
			if(sumoffactors == sumdigits(smith))
			{
				return smith;
			}
		}
		smith++;
	}
}

int main()
{
	sieve();
	int cases, N;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d", &N);
		printf("%llu\n", smith(N));
	}
	return 0;
}