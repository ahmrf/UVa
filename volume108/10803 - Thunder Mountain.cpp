#include <bits/stdc++.h>

using namespace std;

double dp[210][210];
int inft = 1 << 29;

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
	int n, cn = 1, cases;
	scanf("%d", &cases);
	double x, y, inf = (double)inft;
	while(cases--)
	{
		scanf("%d", &n);
		vector <node> nodes;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &x, &y);
			nodes.push_back(node(x, y));
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				double d = sqrt((nodes[i].x-nodes[j].x)*(nodes[i].x-nodes[j].x)+(nodes[i].y-nodes[j].y)*(nodes[i].y-nodes[j].y));
				if(d <= 10.000)	dp[i][j] = d;
				else dp[i][j] = inf; 
			}
		}
		for(int k = 0; k < n; k++)
		{
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					dp[i][j] = min(dp[i][j], (dp[i][k]+dp[k][j]));
				}
			}
		}

		double ans = 0.000;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				ans = max(ans, dp[i][j]);
			}
		}

		if(ans < inf) printf("Case #%d:\n%.4lf\n\n", cn++, ans);
		else printf("Case #%d:\nSend Kurdy\n\n", cn++);
		
	}

	return 0;
}