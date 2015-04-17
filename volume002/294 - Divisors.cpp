#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

#define maxN 31623

using namespace std;

bool notP[maxN];
vector<int>P;

void sieve()
{
	notP[0] = notP[1] = true;
	for(int i = 4; i<maxN; i+=2)
		notP[i] = true;
	for(int i = 3; i*i<maxN; i+=2)
		if(!notP[i])
			for(int j = i*i; j<maxN; j+=2*i)
				notP[j] = true;
	P.push_back(2);
	for(int i = 3; i<maxN; i+=2)
		if(!notP[i])
			P.push_back(i);
}

int nod(int N)
{
	if(N <= maxN && !notP[N]) return 2;
	if(N == 1) return 1;
	int no = 1;
	for(int i = 0; i<P.size() && P[i]*P[i] <= N; i++)
	{
		int c = 1;
		while(N%P[i] == 0) {
			c++;
			N /= P[i];
		}
		no *= c;
		if(N == 1) return no;
	}
	if(N > 1) return 2*no;
	return 2;
}

int main()
{
	sieve();
	int L, U, x, y, cases;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%d%d", &L, &U);
		x = L, y = U;
		if(x > y) swap(x, y);
		int number = x, maxnod = 0;
		for(int i = x; i <= y; i++) {
			int no = nod(i);
			if(no > maxnod) {
				maxnod = no;
				number = i;
			}
		}

		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,number,maxnod);
	}

}