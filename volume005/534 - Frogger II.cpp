#include <bits/stdc++.h>

using namespace std;

double dp[210][210];

struct node
{
	double x, y;
	node(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};


int main()
{
	int n, cn = 1;
	double x, y;
	while(scanf("%d", &n) == 1 && n)
	{
		vector <node> nodes;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &x, &y);
			nodes.push_back(node(x, y));
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				dp[i][j] = dp[j][i] = sqrt((nodes[i].x-nodes[j].x)*(nodes[i].x-nodes[j].x)+(nodes[i].y-nodes[j].y)*(nodes[i].y-nodes[j].y));
			}
		}
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					dp[i][j] = min(dp[i][j], max(dp[i][k],dp[k][j]));
				}
			}
		}

		printf("Scenario #%d\nFrog Distance = %.3lf\n", cn++, dp[0][1]);
		puts("");
	}

	return 0;
}