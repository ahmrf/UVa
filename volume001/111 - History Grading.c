#include <stdio.h>

int main()
{
	int x[25], y[25], rank, n, i, j, terminate = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &rank);
		x[rank] = i;
	}
	while(1)
	{
		for(i = 1; i <= n; i++)
		{
			if(scanf("%d", &rank) != 1)
			{
				terminate = 1;
				break;
			}
			y[rank] = i;
		}
		if(terminate) break;
		int lcs[25][25] = {};
		for(i = 2; i <= n+1; i++)
		{
			for(j = 2; j <= n+1; j++)
			{
				if(x[i-1] == y[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
				else
				{
					lcs[i][j] = lcs[i-1][j] > lcs[i][j-1]? lcs[i-1][j] : lcs[i][j-1]; 
				}
			}
		}
		printf("%d\n", lcs[n+1][n+1]);
	}
	return 0;
}