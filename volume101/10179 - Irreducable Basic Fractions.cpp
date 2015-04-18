#include <cstdio>
#include <cmath>
#include <vector>
#define maxN 31623

using namespace std;

bool is[maxN];
vector<int> P;

void sieve()
{
	int sq = sqrt(maxN);
	is[0] = is[1] = true;
	for(int i=4; i<maxN; i+=2)
		is[i] = true;
	for(int i=3; i<sq; i+=2)
		if(!is[i])
			for(int j=i*i; j<maxN; j+=2*i)
				is[j] = true;
	P.push_back(2);
	for(int i=3; i<maxN; i+=2)
		if(!is[i])
			P.push_back(i);
}

int main()
{
	sieve();
	int N, sz = P.size();
	while(scanf("%d", &N), N)
	{
		int result = N;

		for(int i=0; i<sz && P[i]*P[i] <= N; i++)
		{
			if(N % P[i] == 0)
			{
				result -= result/P[i];
				while(N%P[i] == 0)
					N/=P[i];
			}
		}
		if(N > 1) result -= result/N;
		printf("%d\n", result);
	}
	return 0;
}