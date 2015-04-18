#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, idx;
	while(scanf("%d", &n) == 1 && n)
	{
		getchar();
		string *a = new string[n];
		string *b = new string[n];
		string s;

		for(int i = 0; i < n; i++)
		{
			getline(cin, a[i]);
			getline(cin, b[i]);
		}

		getline(cin, s);

		for(int i = 0; i < n; i++)
		{
			idx = s.find(a[i]);
			while(idx != -1)
			{
				s.erase(idx, a[i].size());
				s.insert(idx, b[i]);
				idx = s.find(a[i]);
			}
		}

		cout << s << endl;
	}
	return 0;
}