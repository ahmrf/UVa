#include <bits/stdc++.h>

using namespace std;

char grid[55][55];
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int n, m;

void find_location(char word[], int &sx, int &sy)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(tolower(word[0]) == tolower(grid[i][j]))
			{
				for(int k = 0; k < 8; k++)
				{
					int idx = 1;
					for(int x = i + dx[k], y = j + dy[k]; ; x += dx[k], y += dy[k], idx++)
					{
						if(word[idx] == '\0' || tolower(word[idx]) != tolower(grid[x][y])) break;
					}
					if(word[idx] == '\0')
					{
						sx = i, sy = j;
						return;
					}
				}
			}
		}
	}
}

int main()
{
	int cases, w, x, y;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d %d", &n, &m);
		getchar();
		for(int i = 0; i < n; i++)
		{
			gets(grid[i]);
		}

		char word[55];
		scanf("%d", &w);
		getchar();
		while(w--)
		{
			gets(word);
			find_location(word, x, y);
			printf("%d %d\n", ++x, ++y);
		}
		if(cases) puts("");
	}
	return 0;
}