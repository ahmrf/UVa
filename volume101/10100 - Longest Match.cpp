#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a, b;
	int c = 1;
	while(getline(cin, a))
	{
		getline(cin, b);
		string s;
		vector<string> x, y;

		int m = 0, n = 0, len = a.length();
		for(int i = 0; i < len; i++)
		{
			if(!(a[i]<='z'&&a[i]>='a') && !(a[i]>='A'&&a[i]<='Z') && !(a[i]>='0'&&a[i]<='9'))
			{
				a[i] = ' ';
			}
		}
		len = b.length();
		for(int i = 0; i < len; i++)
		{
			if(!(b[i]<='z'&&b[i]>='a') && !(b[i]>='A'&&b[i]<='Z') && !(b[i]>='0'&&b[i]<='9'))
			{
				b[i] = ' ';
			}
		}
		istringstream iss(a);
		while(iss >> s)
			x.push_back(s);
		istringstream iss2(b);
		while(iss2 >> s)
			y.push_back(s);
		m = x.size(), n = y.size();
		int L[m+1][n+1];

	    for (int i = 0; i <= m; i++)
	    {
	        for (int j = 0; j <= n; j++)
	        {
	            if (i == 0 || j == 0) L[i][j] = 0;

	            else if (x[i-1] == y[j-1]) L[i][j] = L[i-1][j-1] + 1;

	            else L[i][j] = max(L[i-1][j], L[i][j-1]);
	        }
	    }

	    printf("%2d. ", c++);
	    if(m == 0 || n == 0 || L[m][n] == 0) puts("Blank!");
	    else printf("Length of longest match: %d\n", L[m][n]);
	    
	    
	}
	return 0;
}