#include <stdio.h>
#include <string.h>

char str[150];

int balanced ()
{
	int length = strlen(str), i, k = -1;
	char stack[150];

	for(i = 0; i < length; i++)
	{
		if(str[i] == '(' || str[i] == '[')
		{
			++k;
			stack[k] = str[i];
		}
		else
		{
			if(k == -1) return 0;
			if((str[i] == ')' && stack[k] == '(') || (str[i] == ']' && stack[k] == '['))
                k--;
            else return 0;
		}
	}  
	if(k == -1) return 1;
	return 0;  
}

int main()
{
	int cases;
	scanf("%d\n", &cases);
	while(cases--)
	{
		gets(str);
		balanced()? puts("Yes") : puts("No");
	}
	return 0;
}
