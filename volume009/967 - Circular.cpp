#include <bits/stdc++.h>
#define maxn 1000001

using namespace std;

bool isp[maxn];
int counter[maxn];

int no_of_digit(int n)
{
	int count = 1;
	while(n > 9)
	{
		count++;
		n /= 10;
	}
	return count;
}

bool is_circular(int n)
{
	int len = no_of_digit(n);
	if(len < 3) return false;
	len--;
	int ex = pow(10, len);

	while(len--)
	{
		n = (n%ex)*10 + (n/ex);
		if(isp[n] == false) return false;
	}
	return true;
}


void sieve()
{
	memset(isp, true, sizeof(isp));
	isp[0] = isp[1] = false;
	int lim = sqrt(maxn);
	for(int i = 4; i < maxn; i += 2)
	{
		isp[i] = false;
	}
	for(int i = 3; i < lim; i += 2)
	{
		if(isp[i])
		{
			for(int j = i*i; j < maxn; j += i+i)
			{
				isp[j] = false;
			}
		}
	}

	int c = 0;
	for(int i = 0; i < 101; i++)
	{
		counter[i] = 0;
	}
	for(int i = 101; i < maxn; i += 2)
	{
		if(isp[i])
		{
			if(is_circular(i)) c++;
		}
		counter[i] = counter[i+1] = c;
	}

}

int main()
{
	sieve();
	int L, U;
	while(scanf("%d", &L) == 1 && L!=-1)
	{
		scanf("%d", &U);
		if(L > 0) L--;
		int n = counter[U] - counter[L];
		if(n == 0)
		{
			puts("No Circular Primes.");
		}
		else if(n == 1)
		{
			puts("1 Circular Prime.");
		}
		else
		{
			printf("%d Circular Primes.\n", n);
		}
	}
	return 0;
}