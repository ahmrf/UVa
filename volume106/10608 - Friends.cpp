#include <stdio.h>
#include <algorithm>

using namespace std;

int p[30001], f[30001];
int ret;

int find_parent(int x)
{
	if(x != p[x])
	{
		p[x] = find_parent(p[x]);
	}
	return p[x];
}

void link(int x, int y)
{
	if(f[x] > f[y])
	{
		f[x] += f[y], p[y] = x;
		ret = max(ret, f[x]);
	} 
	else
	{
		f[y] += f[x], p[x] = y;
		ret = max(ret, f[y]);
	}
}

void _union(int x, int y)
{
	x = find_parent(x), y = find_parent(y);
	if(x != y)
	{
		link(x, y);
	}
}

int main()
{
	int n, m, cases, x, y;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d %d", &n, &m);
		for(int i = 0; i <= n; i++)
		{
			p[i] = i, f[i] = 1;
		}
		ret = 0;
		while(m--)
		{
			scanf("%d %d", &x, &y);
			_union(x, y);
		}

		printf("%d\n", ret);
	}
	return 0;
}