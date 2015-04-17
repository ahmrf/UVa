#include <stdio.h>

int n;
int matrix[120][120];
int largestSubSum(int array[])
{
	int maxSum = 0, sum = 0, i;
	for(i = 0; i < n; i++)
	{
		if(sum + array[i] > 0)
		{
			sum += array[i];
			if(sum > maxSum)
				maxSum = sum;
		}
		else
			sum = 0;
	}
	return maxSum;
}
int largestSumMatrix()
{
	int maxSum = 0, i, j, k, l;
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
		{
			int tempSum[120] = {};
			for(k = 0; k < n; k++)
			{
				for(l = i; l <= j; l++)
				{
					tempSum[k] += matrix[k][l];
				}
			}
			
			int tempLargest = largestSubSum(tempSum);
			if(tempLargest > maxSum)
				maxSum = tempLargest;
		}
	}
	return maxSum;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		int i, j;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}
		printf("%d\n", largestSumMatrix());
	}
	return 0;
}
