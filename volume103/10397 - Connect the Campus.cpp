#include <bits/stdc++.h>
#define maxn 752

using namespace std;

int parent[maxn];

struct node
{
	int x, y;
	node(int _x, int _y)
	{
		x = _x;
		y = _y;
	}
};

struct edge
{
	int src, dst;
	double cost;

	edge(int _src, int _dst, double _cost)
	{
		src = _src;
		dst = _dst;
		cost = _cost;
	}
};

bool comparator(edge a, edge b)
{
	return a.cost < b.cost;
}

int find_set(int u)
{
	if(parent[u] == u) return u;
	return parent[u] = find_set(parent[u]);
}

double weight(node a, node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	int n;
	while(scanf("%d", &n) == 1)
	{
		int x, y, m;
		vector<node> nodes;
		vector<edge> edges;
		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &x, &y);
			nodes.push_back(node(x, y));
			parent[i] = i;
		}
		scanf("%d", &m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			parent[find_set(--x)] = find_set(--y);
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = i+1; j < n; j++)
			{
				if(find_set(i) != find_set(j))
				{
					edges.push_back(edge(i, j, weight(nodes[i], nodes[j])));
				}
			}
		}

		sort(edges.begin(), edges.end(), comparator);
		int len = edges.size();
		double cable = 0;

		for(int i = 0; i < len; i++)
		{
			x = find_set(edges[i].src);
			y = find_set(edges[i].dst);
			if(x != y)
			{
				parent[x] = y;
				cable += edges[i].cost;
			}
		}

		printf("%.2lf\n", cable);
	}
	return 0;
}

