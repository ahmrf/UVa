#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	while(cin >> s)
	{
		set <string> st;
		st.insert(s);
		while(cin >> s)
		{
			if(s == "XXXXXX") break;
			st.insert(s);
		}
		while(cin >> s)
		{
			if(s == "XXXXXX") break;
			bool nai = true;
			sort(s.begin(), s.end());
			do 
			{
				if(st.find(s) != st.end())
				{
					nai = false;
					cout << s << endl;
				}
			} while(next_permutation(s.begin(), s.end()));
			if(nai) puts("NOT A VALID WORD");
			puts("******");
		}
	}
	return 0;
}