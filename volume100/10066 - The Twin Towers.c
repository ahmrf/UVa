#include <stdio.h>

int max(int a, int b)
{
	return a > b? a : b;
}

int main()
{
	int n, m, t = 1;
	int x[200], y[200];
	while(scanf("%d %d", &n, &m) == 2 && n && m)
	{
		int i, j;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &x[i]);
		}
		for(i = 0; i < m; i++)
		{
			scanf("%d", &y[i]);
		}
		int dp[201][201] = {};
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				if(x[i-1]==y[j-1])
				{
					dp[i][j] = dp[i-1][j-1]+1;
				}
				else
				{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", t++, dp[n][m]);

	}
	return 0;
}