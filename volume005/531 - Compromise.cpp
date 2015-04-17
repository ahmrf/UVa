#include <bits/stdc++.h>

using namespace std;
char x[200][50], y[200][50];


bool flag;

void print(char s[200][200], int i, int j)
{
	if(i == 0 || j == 0) return;
	if(s[i][j] == ' ')
	{
		print(s,i-1, j-1);
		if(flag) printf(" ");
		flag = true;
		printf("%s", x[i]);
	}
	else if(s[i][j] == 'u') print(s,i-1, j);
	else if(s[i][j] == 'l') print(s,i, j-1);
}

int main()
{
	while(true)
	{
		flag = false;
		int n = 0, m = 0;
		while(true)
		{
			if(scanf("%s", x[++n]) == EOF) return 0;
			if(!strcmp(x[n], "#")) break;
		}
		while(scanf("%s", y[++m]) != EOF)
		{
			if(!strcmp(y[m], "#")) break;
		}

		int lcs[n+1][m+1] = {};
		char s[200][200];

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(!strcmp(x[i], y[j]))
				{
					lcs[i][j] = lcs[i-1][j-1]+1;
					s[i][j] = ' ';
				}
				else if(lcs[i-1][j] >= lcs[i][j-1])
				{
					lcs[i][j] = lcs[i-1][j];
					s[i][j] = 'u';
				}
				else
				{
					lcs[i][j] = lcs[i][j-1];
					s[i][j] = 'l';
				}
			}
		}

		print(s,n-1, m-1);
		puts("");

	}
	return 0;
}