#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main()
{
	int array[1010], n = 1, ans;
	while(scanf("%d", &array[0]) == 1 && array[0])
	{
		while(scanf("%d", &array[n]) == 1 && array[n])
		{
			n++;
		}

		sort(array, array+n);
		ans = array[1]-array[0];
		for(int i = 2; i < n; i++)
		{
			ans = gcd(ans, array[i]-array[0]);
		}
		printf("%d\n", ans);
		n = 1;
	}
	return 0;

}
