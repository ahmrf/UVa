#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	return a > b? a : b;
}

int main()
{
	char x[200], y[200];
	int k = 1;
	while(gets(x))
	{
		if(!strcmp(x, "#")) return 0;
		gets(y);
	
		int n = strlen(x), m = strlen(y), i, j;
		int L[200][200] = {};

		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				if(x[i-1] == y[j-1])
				{
					L[i][j] = L[i-1][j-1]+1;
				}
				else
				{
					L[i][j] = max(L[i-1][j], L[i][j-1]);
				}
			}
		}
	
		printf("Case #%d: you can visit at most %d cities.\n", k++, L[n][m]);
	}
	return 0;
}