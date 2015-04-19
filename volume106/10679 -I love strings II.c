#include <stdio.h>
#include <string.h>

int main()
{
	char text[100010], pattern[1010];
	int query, cases, i, j, match;

	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%s", text);
		scanf("%d", &query);
		while(query--)
		{
			match = 1, i = 0;
			scanf("%s", pattern);
			for(j = 0; pattern[j]; j++)
			{
				if(text[i] == pattern[j]) i++;
				else 
				{
					match = 0;
					break;
				}
			}
			match? puts("y"):puts("n");
		}
	}
	return 0;
}