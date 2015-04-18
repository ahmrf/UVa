#include <cstdio>
#include <vector>
#define maxN 46341
#define int64 long long int

using namespace std;

bool is[maxN];
vector<int>primes;
vector< pair<int, int> > factors;

void sieve()
{
	is[0] = is[1] = true;
	for(int i = 4; i<maxN; i+=2)
		is[i] = true;
	for(int i = 3; i*i<maxN; i+=2)
		if(!is[i])
			for(int j = i*i; j<maxN; j+=2*i)
				is[j] = true;
	primes.push_back(2);
	for(int i = 3; i<maxN; i+=2)
		if(!is[i])
			primes.push_back(i);
}

int get_power(int N, int P)
{
	int res = 0;
	for(int64 power = P; power <= N; power*=P)
		res += N/power;
	return res;
}

void factorize(int N)
{
	factors.clear();
	int num = N;
	for(int i = 0; i<primes.size() && primes[i] <= num; i++)
	{
		if(num % primes[i] == 0)
		{
			int c = 0;
			while(num%primes[i] == 0)
			{
				num /= primes[i];
				c++;
			}
			factors.push_back(make_pair(primes[i], c));
		}
	}
	if(num > 1) factors.push_back(make_pair(num, 1));
}

bool is_divisible(int N, int dividend)
{
	if(dividend == 0) return false;
	if(N >= dividend) return true;
	factorize(dividend);
	
	for(int i = 0; i<factors.size(); i++)
	{
		if(factors[i].first > N) return false;
		if(get_power(N, factors[i].first) < factors[i].second) return false;
	}
	return true;
}

int main()
{
	sieve();
	int N, dividend;
	while(scanf("%d %d", &N, &dividend) == 2)
	{
		if(is_divisible(N, dividend)) printf("%d divides %d!\n", dividend, N);
		else printf("%d does not divide %d!\n", dividend, N);

	}
	return 0;
}