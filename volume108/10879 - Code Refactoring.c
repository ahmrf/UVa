#include <stdio.h>

int main(int argc, char const *argv[])
{
	int cases, n, count, i, divisor;
	scanf("%d", &cases);
	for(i = 1; i <= cases; i++)
	{
		scanf("%d", &n);
		printf("Case #%d: %d", i, n);
		count = 0;
		for(divisor = 2; count < 2; divisor++)
		{
			if(n%divisor == 0)
			{
				printf(" = %d * %d", divisor, n/divisor);
				count++;
			}
		}
		puts("");
	}
	return 0;
}