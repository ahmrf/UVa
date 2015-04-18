#include <stdio.h>
#include <string.h>

int main()
{
	char s[1001], a[20];
	int base, mod;
	while(scanf("%d", &base) == 1 && base)
	{
		scanf("%s %s", s, a);
		int t = 1, sl = strlen(a), i;
		mod = 0;
		for(i = sl-1; i >= 0; i--)
		{
			mod += (a[i]-48)*t;
			t *= base;
		}
		t = 0;
		for(i = 0; s[i]; i++)
		{
			t = t*base + (s[i]-48);
			t %= mod;
		}
		int ans[50], j = -1;
		while(t)
		{
			ans[++j] = t%base;
			t /= base;
		}

		for(i = j; i >= 0; i--)
			printf("%d", ans[i]);
		if(j == -1) printf("0");
		puts("");
	}
	return 0;
}