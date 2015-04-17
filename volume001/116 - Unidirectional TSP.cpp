#include <bits/stdc++.h>
#include <climits>

using namespace std;


long long inf = LLONG_MAX;
long long dp[20][120], grid[20][120];
int path[20][120];

int main()
{
	int r, c;
	while(scanf("%d %d", &r, &c) == 2)
	{
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				scanf("%lld", &grid[i][j]);
				if(j == c-1)
				{
					dp[i][j] = grid[i][j];
				}
			}
		}

		long long minimum;
		int idx, cidx;

		for(int j = c-2; j >= 0; j--)
		{
			for(int i = 0; i < r; i++)
			{
				minimum = inf;

				for(int k = -1; k <= 1; k++)
				{
					idx = (i+k+r)%r;
					if(dp[idx][j+1] < minimum || (dp[idx][j+1] == minimum && idx < path[i][j]))
					{
						minimum = dp[idx][j+1];
						path[i][j] = idx;
					}
				}

				dp[i][j] = grid[i][j] + minimum;
			}
		}

		minimum = inf;
		for(int i = 0; i < r; i++)
		{
			if(dp[i][0] < minimum)
			{
				minimum = dp[i][0];
				idx = i;
			}
		}

		printf("%d", idx+1);
		for(int i = 0; i < c-1; i++)
		{
			idx = path[idx][i];
			printf(" %d", idx+1);
		}

		printf("\n%lld\n", minimum);
	}
	return 0;
}