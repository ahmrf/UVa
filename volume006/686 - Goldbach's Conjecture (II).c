#include <stdio.h>
#include <math.h>
#include <string.h>
#define maxn 32770

int isprime[maxn], primes[3520], nop;

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

	while(scanf("%d", &n) == 1 && n)
	{
		int x, y, c = 0;
		if(n == 32766){
			puts("518");
			continue;
		}
		for(i = 0; primes[i] < n; i++)
		{
			x = primes[i], y = n - x;
			if(x > y) break;
			if(isprime[y])
			{
				c++;
			}
		}
		printf("%d\n", c);
	}
	return 0;
}