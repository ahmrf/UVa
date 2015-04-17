#include <bits/stdc++.h>

using namespace std;

bool is_prefix(char s[], char t[])
{
	int i;
	for(i = 0; s[i] && t[i]; i++)
	{
		if(s[i] != t[i]) return false;
	}
	return true;
}

char st[1000][1000];

int main()
{
	int n = 0, i, c = 1;
	while(scanf("%s", st[n++]) == 1)
	{
		while(scanf("%s", st[n++]) == 1)
		{
			if(st[n-1][0] == '9') break;
		}
		n--;
		qsort(st, n, 1000, (int (*)(const void *, const void *)) strcmp);
		bool decodable = true; 
		for(i = 0; i < n-1; i++)
		{
			if(is_prefix(st[i], st[i+1]))
			{
				decodable = false;
				printf("Set %d is not immediately decodable\n", c++);
				break;
			}
		}
		if(decodable) printf("Set %d is immediately decodable\n", c++);
		n = 0;
	}
	return 0;
}