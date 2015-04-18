#include<bits/stdc++.h>
using namespace std;

int main()
{
	char str[20000];
	int i, len, number;
	char ch;

	while (cin >> ch)
    {
		number = 0;
		number += ch - 48;
		while (cin >> ch)
		{
			if (ch == '#') break;
			number *= 2;
			number += ch - 48;
			number = number % 131071;
		}

		(number)? puts("NO") : puts("YES");
	}
	return 0;
}
