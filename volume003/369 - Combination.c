#include <stdio.h>

long long nCr(long long n, long long r)
{
	if(r == 0) return 1;
	if(r > n - r) r = n - r;
	long long ret = 1, i;
	for(i = 1; i <= r; i++, n--)
	{
		ret *= n;
		ret /= i;
	}
	return ret;
}

int main()
{
	long long n, r;
	while(scanf("%lld %lld", &n, &r) == 2)
	{
		if(n == 0 && r == 0) return 0;
		printf("%lld things taken %lld at a time is %lld exactly.\n", n, r, nCr(n, r));
	}
	return 0;
}