#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a, b;
	while(getline(cin, a))
	{
		getline(cin, b);
		vector<int> c;
		istringstream iss(a);
		int n, value;
		bool space = false;
		while(iss >> value)
		{
			c.push_back(value);
		}
		n = c.size();
		istringstream iss2(b);
		while(iss2 >> value)
		{
			int ret = 0;
			for(int i = 0, j = n-1; i < n; i++, j--)
			{
				ret += c[i]*(int)pow(value, j);
			}
			if(space) printf(" ");
			printf("%d", ret);
			space = true;
		}
		puts("");
	}
	return 0;
}