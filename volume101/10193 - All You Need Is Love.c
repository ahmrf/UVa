#include <string.h>
#include <stdio.h>

long long to_decimal(char *bin)
{
	int i = strlen(bin) - 1, j;
	long long ret = 0;
	for(j = 0; bin[j]; j++)
	{
		ret += (1 << i)*(bin[j]-48);
		i--;
	}
	return ret;
}

long long get_gcd(long long a, long long b)
{
	if(a < b) return get_gcd(b, a);
	return (a%b == 0)? b : get_gcd(b, a%b);
}

int main()
{
	char S1[40], S2[40];
	int cases, i;
	scanf("%d", &cases);
	for(i = 1; i <= cases; i++)
	{
		scanf("%s", S1);
		scanf("%s", S2);
		printf("Pair #%d: ", i);
		get_gcd(to_decimal(S1), to_decimal(S2)) == 1? puts("Love is not all you need!") : puts("All you need is love!");
	}
	return 0;
}