#include <stdio.h>

int main()
{
	int a, x0r, n;
	while(scanf("%d", &n) == 1 && n)
	{
		scanf("%d", &x0r);
		n--;
		while(n--)
		{
			scanf("%d", &a);
			x0r ^= a;
		}

		x0r? puts("Yes") : puts("No");
	}
	return 0;
}