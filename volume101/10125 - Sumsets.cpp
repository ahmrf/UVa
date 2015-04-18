#include <bits/stdc++.h>

using namespace std;

bool isvalid(int a, int b, int c, int d)
{
	if(a == b || a == c || a == d) return false;
	if(b == c || b == d) return false;
	if(c == d) return false;
	return true;
}

int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		int d, m = n;
		set<int> s;
		vector <int> v;
		vector <pair <int, int> > vp;
		bool found = false;
		for(int i = 0; i < n; i++)
		{
			int a;
			scanf("%d", &a);
		
			s.insert(a);
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		int len = v.size();
		for(int i = 0; i < len-1; i++)
		{
			for(int j = i+1; j < len; j++)
			{
				if(v[i] != v[j])
					vp.push_back(make_pair(v[i], v[j]));
			}
		}
		int len2 = vp.size();
		for(int i = len-1; i >= 0; i--)
		{
			for(int j = 0; j < len2; j++)
			{
				int c = v[i]-vp[j].first - vp[j].second;
				if(isvalid(v[i], vp[j].first, vp[j].second, c) && s.find(c) != s.end())
				{
					printf("%d\n", v[i]);
					found = true;
					break;
				}
			}
			if(found) break;
		}
		if(!found) puts("no solution");
	}
	return 0;
}