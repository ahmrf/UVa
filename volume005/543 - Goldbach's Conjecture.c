#include <stdio.h>
#include <math.h>
#include <string.h>
#define maxn 1000001

int isprime[maxn], primes[78500], nop;

int main()
{
	nop = 0;
	int i, j, sq = sqrt(maxn);
	memset(isprime, 1, sizeof isprime);
	isprime[0] = isprime[1] = 0;
	for(i = 4; i < maxn; i += 2)
	{
		isprime[i] = 0;
	}
	for(i = 3; i < sq; i += 2)
	{
		if(isprime[i])
		{
			for(j = i*i; j < maxn; j += i+i)
			{
				isprime[j] = 0;
			}
		}
	}

	primes[nop++] = 2;
	for(i = 3; i < maxn; i += 2)
	{
		if(isprime[i]) primes[nop++] = i;
	}

	int n;
	while(scanf("%d", &n), n)
	{
		int nai = 1;
		for(i = 0; i < nop; i++)
		{
			if(isprime[n-primes[i]])
			{
				printf("%d = %d + %d\n", n, primes[i], n-primes[i]);
				nai = 0;
				break;
			}
		}
		if(nai) puts("Goldbach's conjecture is wrong.");
	}
	return 0;
}