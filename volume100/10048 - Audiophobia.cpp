#include <bits/stdc++.h>
#define inf 1 << 29

using namespace std;

int main()
{
	int n, m, q, cn = 1;
	bool line = false;
	while(scanf("%d %d %d", &n, &m, &q) == 3 && n)
	{
		int dp[110][110] = {};
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i != j)
				{
					dp[i][j] = inf;
				}
			}
		}
		int u, v, w;
		while(m--)
		{
			scanf("%d %d %d", &u, &v, &w);
			dp[u][v] = dp[v][u] = w;
		}
		for(int k = 1; k <= n; k++)
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= n; j++)
				{
					dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
				}
			}
		}
		if(line) puts("");
		line = true;
		printf("Case #%d\n", cn++);
		while(q--)
		{
			scanf("%d %d", &u, &v);
			if(dp[u][v] == inf) puts("no path");
			else printf("%d\n", dp[u][v]);
		}
	}
	return 0;
}