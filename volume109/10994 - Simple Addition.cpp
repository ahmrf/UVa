#include <stdio.h>

long long S(long long n)
{
	if(n <= 0) return 0;
	long long ret = 0;
	while(n)
	{
		long long i;
		ret += 45*(n/10);
		for(i = n/10*10+1; i <= n; i++)
		{
			ret += (i%10);
		}
		n /= 10;
	}
	return ret;
}

int main()
{
	long long p, q;
	while(scanf("%lld %lld", &p, &q) == 2)
	{
		if(p < 0 && q < 0) return 0;
		printf("%lld\n", S(q) - S(p-1));
	}
	return 0;
}