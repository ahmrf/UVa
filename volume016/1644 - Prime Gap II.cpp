#include <stdio.h>

#define maxL (1300000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))

int mark[maxL];

using namespace std;

void sieve(int n)
{
	register int i, j, k;
	SET(1);
	for(i = 2; i < n; i++)
	{
		if(!GET(i))
		{
			for(k = n/i, j = i*k; k >= i; k--, j -= i)
			{
				SET(j);
			}
		}
	}
}

int main()
{
	sieve(1300000);
	int n, ret;
	while(scanf("%d", &n) == 1 && n)
	{
		ret = 0;
		for(int i = n; GET(i); i++, ret++);
		for(int i = n; GET(i) && i > 0; i--, ret++);
		printf("%d\n", ret);
	}
	return 0;
}