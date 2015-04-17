#include <bits/stdc++.h>

using namespace std;

int main()
{
	char ques[100000];
	int cases;
	scanf("%d\n", &cases);
	for(int k = 1; k <= cases; k++)
	{
		gets(ques);
		int n = 0, m = 0;
		int equal[2];
		char data[2];
		bool P = false, U = false, I = false;
		float a[2], ans;
		for(int i = 0; ques[i]; i++)
		{
			if(ques[i] == '=')
			{
				equal[n++] = i, data[m++] = ques[i-1];
				if(ques[i-1] == 'P') P = true;
				else if(ques[i-1] == 'U') U = true;
				else if(ques[i-1] == 'I') I = true;
			}
			if(n == 2) break;
		}

		if(data[0] > data[1])
		{
			swap(data[0], data[1]);
			swap(equal[0], equal[1]);
		}
		char info[2][30];

		for(int i = 0; i < 2; i++)
		{
			int l = -1;
			for(int j = equal[i]+1; ques[j]; j++)
			{
				info[i][++l] = ques[j];
				if(ques[j] == 'W'||ques[j] == 'A' || ques[j] == 'V') break;
			}
			float mul = 1;
			
			if(info[i][l-1] == 'k') mul*=1000, l--;
			else if(info[i][l-1] == 'M') mul*=1000000, l--;
			else if(info[i][l-1] == 'm') mul/=1000, l--;
			info[i][l] = '\0';
			sscanf(info[i], "%f", &a[i]);
			a[i]*=mul;
		}

		printf("Problem #%d\n", k);
		if(I && P)
		{
			printf("U=%.2fV\n", a[1]/a[0]);
		}
		else if(P && U)
		{
			printf("I=%.2fA\n", a[0]/a[1]);
		}
		else if(I && U)
		{
			printf("P=%.2fW\n", a[0]*a[1]);
		} 
		puts("");

	}
	return 0;
}