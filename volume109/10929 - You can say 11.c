#include <stdio.h>
#include <string.h>

int main()
{
	char num[100010];
	int sumOdd, sumEven, length, i;

	while(scanf("%s", num) == 1 && strcmp(num, "0"))
	{
		length = strlen(num), sumOdd = 0, sumEven = 0;
		for(i = 0; i < length; i += 2)
        {
            sumOdd += (num[i] - '0');
        }

        for(i = 1; i < length; i += 2)
        {
            sumEven += (num[i] - '0');
        }

        if((sumOdd-sumEven) % 11 == 0) printf("%s is a multiple of 11.\n", num);
        else printf("%s is not a multiple of 11.\n", num);
	}

	return 0;
}