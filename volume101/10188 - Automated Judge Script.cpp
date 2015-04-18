#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, k = 1;
	while(scanf("%d", &n) == 1 && n)
	{
		getchar();
		string x="", y="", p="", q="", s;
		for(int i = 0; i < n; i++)
		{
			getline(cin, s);
			p += s;
			int len = s.length();
			for(int j = 0; j < len; j++)
			{
				if(isdigit(s[j])) x+= s[j];
			}
		}
		scanf("%d", &m);
		getchar();
		for(int i = 0; i < m; i++)
		{
			getline(cin, s);
			q += s;
			int len = s.length();
			for(int j = 0; j < len; j++)
			{
				if(isdigit(s[j])) y+= s[j];
			}
		}
		printf("Run #%d: ",k++);
		if( p == q && n == m ) puts("Accepted");
		else if( x == y ) puts("Presentation Error");
		else puts("Wrong Answer");	
	}
	return 0;
}