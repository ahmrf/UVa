#include <stdio.h>
#include <string.h>

int main()
{
	char card[4], ans[4];
	int cases, c, i;
	scanf("%d", &cases);
	for(c = 1; c <= cases; c++)
	{
		for(i = 1; i<=52; i++)
		{
			scanf("%s", card);
			if(i == 33) strcpy(ans, card);
		}
		printf("Case %d: %s\n", c, ans);
	}
	return 0;
}