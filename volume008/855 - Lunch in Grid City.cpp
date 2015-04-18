#include <bits/stdc++.h>

using namespace std;

int main()
{
	int S, A, F, cases, s[50010], a[50010], x;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d %d %d", &S, &A, &F);
		for(int i = 0; i < F; i++)
		{
			scanf("%d %d", &s[i], &a[i]);
		}
		sort(s, s+F), sort(a, a+F);
		F--;
		x = F/2;
		printf("(Street: %d, Avenue: %d)\n", s[x], a[x]);
	}
	return 0;
}