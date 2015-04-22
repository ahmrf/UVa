#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x1, y1, x2, y2, W, H, N;
	while(scanf("%d %d %d", &W, &H, &N) == 3 && W)
	{
		bool grid[W+1][H+1];
		memset(grid, true, sizeof(grid));
		int fs = 0;
		while(N--)
		{
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if(x1 > x2) swap(x1, x2);
			if(y1 > y2) swap(y1, y2);
			for(int i = x1; i <= x2; i++)
			{
				for(int j = y1; j <= y2; j++)
				{
					grid[i][j] = false;
				}
			}
			
		}
		for(int i = 1; i <= W; i++)
		{
			for(int j = 1; j <= H; j++)
			{
				fs += (grid[i][j] == true);
			}
		}
	
		if(fs == 0) puts("There is no empty spots.");
		else if(fs == 1) puts("There is one empty spot.");
		else printf("There are %d empty spots.\n", fs);
	} 
	return 0;
}