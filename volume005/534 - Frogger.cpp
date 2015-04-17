#include <bits/stdc++.h>
#define maxn 752

using namespace std;

int parent[maxn];

struct node
{
	double x, y;
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
	int n, cases;
	
	for(int cn = 1; scanf("%d", &n)==1 && n ; cn++)
	{
		double x, y;
		vector<node> nodes;
		vector<edge> edges;
		for(int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &x, &y);
			nodes.push_back(node(x, y));
			parent[i] = i;
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
		int len = edges.size(), p , q;
		double cable = 0;

		for(int i = 0; i < len; i++)
		{
			p = find_set(edges[i].src);
			q = find_set(edges[i].dst);
			if(p != q)
			{
				parent[p] = q;
				if(find_set(0) == find_set(1))
				{
					cable += edges[i].cost;
					break;	
				}
				
			}
		}

		printf("Scenario #%d\nFrog Distance = %.3lf\n", cn, cable);
		puts("");
	}
	return 0;
}

