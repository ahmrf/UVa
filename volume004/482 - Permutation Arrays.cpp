#include <bits/stdc++.h>

using namespace std;

struct content
{
	string s;
	int th;

	content(string _s, int _th)
	{
		s = _s;
		th = _th;
	}
};

bool ifswap(content a, content b)
{
	return a.th < b.th;
}

int main()
{
	int cases;
	cin >> cases;
	string line, ths, values;
	getline(cin, line);
	
	while(cases--)
	{
		getline(cin, line);
		getline(cin, ths);
		getline(cin, values);

		istringstream iss(ths);
		istringstream iss2(values);

		int a;
		string s;
		vector<content> v;
		while(iss >> a && iss2 >> s)
		{
			v.push_back(content(s, a));
		}
		sort(v.begin(), v.end(), ifswap);
		a = v.size();
		for(int i = 0; i < a; i++)
		{
			cout << v[i].s << endl;
		}
		if(cases) puts("");
	}
	return 0;
}