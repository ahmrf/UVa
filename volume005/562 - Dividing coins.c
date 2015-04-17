#include <stdio.h>

int dp[110][50010];

int max(int a, int b)
{
	return a > b? a : b;
}

int main()
{
	int cases, n, i, j, sum, W, w[110];
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d", &n);
		sum = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d", &w[i]);
			sum += w[i];
		}
		W = sum/2;
		for(i = 0; i <= n; i++)
		{
			for(j = 0; j <= W; j++)
			{
				if(i == 0 || j == 0)
				{
					dp[i][j] = 0;
				}
				else if(w[i-1] <= j)
				{
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]]+w[i-1]);
				}
				else dp[i][j] = dp[i-1][j];
			}
		}

		printf("%d\n", sum - 2*dp[n][W]);
	}
	return 0;
}




