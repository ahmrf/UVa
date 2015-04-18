#include <stdio.h>
#include <math.h>

int isprime(int n)
{
	if(n == 2) return 1;
	if(n == 0 || n % 2 == 0 || n == 1) return 0;
	int sq = sqrt(n), i;
	for(i = 3; i <= sq; i += 2)
	{
		if(n%i == 0) return 0;
	}
	return 1;
}

int main()
{
	int cases, p, n;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d,",&p);
		if(isprime(p))
		{
			n = pow(2,p) - 1;
			isprime(n)? puts("Yes") : puts("No");
		}
		else puts("No");
	}
	return 0;
}