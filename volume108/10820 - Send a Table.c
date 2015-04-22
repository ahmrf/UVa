#include <stdio.h>
#include <math.h>

#define maxn 250

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,
				59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,
				131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,
				211,223,227,229,233,239,241};
int _size = 53;

int phi(int n)
{
	int sq = sqrt(n), ret = n, i;
	for(i = 0; i < _size && primes[i] <= sq; i++)
	{
		if(n%primes[i] == 0)
		{
			ret -= (ret/primes[i]);
			while(n%primes[i] == 0)
			{
				n /= primes[i];
			}
		}
	}
	if(n > 1) ret -= (ret/n);
	return ret;
}

int main()
{
	int noc[50001], i;
	noc[1] = 1;
	for(i = 2; i <= 50000; i++)
	{
		noc[i] = noc[i-1] + 2*phi(i);
	}
	int n;
	while(scanf("%d", &n) == 1 && n)
	{
		printf("%d\n", noc[n]);
	}
	return 0;
}