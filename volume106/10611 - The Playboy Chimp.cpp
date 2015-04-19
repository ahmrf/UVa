#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n, Q, a, q;
	while(scanf("%d", &n) == 1)
	{
		vector<int>h(n);
		vector<int>::iterator idl, idu;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &h[i]);
		}
		scanf("%d", &Q);
		while(Q--)
		{
			scanf("%d", &q);
			idl = lower_bound(h.begin(), h.end(), q);
			idu = upper_bound(h.begin(), h.end(), q);
			(idl-h.begin() == 0)? printf("X ") : printf("%d ", *--idl);
			(idu-h.begin() == n)? printf("X\n") : printf("%d\n", *idu);
		}
	}
	return 0;
}