#include <stdio.h>
#include <string.h>
#include <math.h>

int max(int a, int b)
{
	return a>b? a : b;
}

int main()
{
	char number[100];
	while(scanf("%s", number) == 1)
	{
		if(strcmp(number, "0") == 0) break;
		int i, len = strlen(number), base = 0;
		for(i = 0; i < len; i++)
		{
			number[i] -= 48;
			base = max(base, number[i]);
		}
		long long int N, sq;
		for(base++; ; base++)
		{
			N = 0;
			for(i = 0; i < len; i++)
			{
				N = N*base + number[i];
			}
			sq = (long long int)sqrt(N);
			if(sq*sq == N)
			{
				printf("%d\n", base);
				break;
			}
		}
	}
	return 0;
}