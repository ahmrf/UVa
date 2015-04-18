#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		string s;
		int value;
		long long sum = 0;
		map<string, int> table;
		while(n--)
		{
			cin >> s >> value;
			table[s] = value;
		}

		while(m--)
		{
			sum = 0;
			while(cin >> s)
			{
				if(s == ".") break;
				sum += table[s];
			}
			printf("%lld\n", sum);
		}

	}
	return 0;
}