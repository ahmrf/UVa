#include <stdio.h>
#include <string.h>
int dg[100100];
int min(int a, int b)
{
	return a < b? a : b;
}
int main()
{
	int i, j, sum;
	char s[20];
	memset(dg, 0x3f3f3f3f, sizeof dg);
	for(i = 1; i < 100100; i++)
	{
		sprintf(s, "%d", i);
		sum = i;
		for(j = 0; s[j]; j++)
			sum += s[j]-'0';
		dg[sum] = min(i, dg[sum]);
	}

	int cases, n;
	scanf("%d", &cases);
	while(cases--)
	{
		scanf("%d", &n);
		printf("%d\n", dg[n]==0x3f3f3f3f? 0:dg[n]);
	}
	return 0;
	
}