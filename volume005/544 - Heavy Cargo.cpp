#include <bits/stdc++.h>
#define maxn 200020

using namespace std;

map<string, string> parent;
set<string> nodes;

struct edge
{
	string src, dst;
	int cost;

	edge(string _src, string _dst, int _cost)
	{
		src = _src;
		dst = _dst;
		cost = _cost;
	}
};

bool comparator(edge a, edge b)
{
	return a.cost > b.cost;
}

string find_set(string u)
{
	if(parent[u] == u) return u;
	return parent[u] = find_set(parent[u]);
}

int main()
{
	int n, m, cn = 1;
	
	while(true)
	{
		cin >> n >> m;
		if(n == 0 || m == 0) break;
		vector<edge> edges;
		parent.clear();
		nodes.clear();
		string x, y, start, destination;
		int c;
		long long totalcost = 0;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y >> c;
			edges.push_back(edge(x, y, c));
			nodes.insert(x);
			nodes.insert(y);
		}

		cin >> start >> destination;
		
		sort(edges.begin(), edges.end(), comparator);
		int len = edges.size();
		string p , q;

		for(set<string> :: iterator it = nodes.begin(); it!=nodes.end(); it++)
		{
			parent[*it] = *it;
		}
		

		for(int i = 0; i < len; i++)
		{
			p = find_set(edges[i].src);
			q = find_set(edges[i].dst);
			if(p != q)
			{
				parent[p] = q;
				if(find_set(start) == find_set(destination))
				{
					totalcost += edges[i].cost;
					break;	
				}
			}
		}

		printf("Scenario #%d\n%lld tons\n", cn++, totalcost);
		puts("");
	}
	return 0;
}

