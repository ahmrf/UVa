#include <stdio.h>
#define uint64 unsigned long long int

int no_of_digit(uint64 N)
{
	int count = 0;
	while(N) {
		count++;
		N /= 10;
	}
	return count;
}

uint64 reversed(uint64 N) 
{
	uint64 ret = 0, p = 1;
	int nod = no_of_digit(N)-1;
	while(nod--) p*=10;
	while(N) 
	{
		ret += p*(N%10);
		N /= 10;
		p /= 10;
	}
	return ret;
}

int main() 
{
	int cases, count;
	uint64 N;
	scanf("%d", &cases);
	while(cases--) {
		count = 0;
		scanf("%llu", &N);
		while(1)
		{
			count++;
			N += reversed(N);
			if(N == reversed(N)) break; 
		}
		printf("%d %llu\n", count, N);
	}

	return 0;
}