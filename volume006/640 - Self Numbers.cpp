#include <stdio.h>
#include <string.h>

using namespace std;

bool self[1000001];

int main()
{
	memset(self, true, sizeof(self));
	for(int i = 1; i < 1000000; i++)
	{
		int num = i, sum = 0;
		while(num)
		{
			sum += num%10;
			num/=10;
		}
		if(sum+i<=1000000) self[sum+i] = false;
	}

	for(int i = 1; i <= 1000000; i++)
	{
		if(self[i]) printf("%d\n", i);
	}
	return 0;
}
