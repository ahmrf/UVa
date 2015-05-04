#include <stdio.h>

#define maxL (5000000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))

int mark[maxL];
int count[5000001];
int dp[5000001] = {};

void sieve()
{
	register int i, j, k;
	int n = 5000000;

	SET(1);
	for(i = 2; i <= n; i++)
	{
		if(!GET(i))
		{
			count[i] = i;
			for(k = n/i, j = i*k; k >= i; k--, j -= i)
			{
				count[j] = i;
				SET(j);
			}
		}
	}
}

void calcu()
{
	int i, j;
	for(i = 2; i <= 5000000; i++)
	{
		j = i;
		while(j % count[i] == 0) j /= count[i];
		count[i] += count[j];
		dp[i] = dp[i-1];
		if(!GET(count[i])) dp[i]++;
	}
}

int main()
{
	int l, u;
	sieve();
	calcu();
	while(scanf("%d %d", &l, &u) == 2)
	{
		printf("%d\n", dp[u] - dp[l-1]);
	}
	return 0;
}