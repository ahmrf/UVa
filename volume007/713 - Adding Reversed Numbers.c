#include <stdio.h>
#include <string.h>


void add(char *a, char *b)
{
	int lena = strlen(a), lenb = strlen(b), k = 0, i, j, carry = 0, digit;
	char temp, ret[10000];
	for(i = 0, j = 0; i < lena && j < lenb; j++, i++, k++)
	{
		digit = a[i]-'0' + b[j]-'0' + carry;
		ret[k] = (digit%10) + '0';
		carry = digit/10;
	}
	if(lena > lenb)
	{
		while(i < lena)
		{
			digit = a[i]-'0' + carry;
			ret[k] = digit%10 + '0';
			carry = digit/10;
			i++, k++;
		}	
	}
	else if(lena < lenb)
	{
		while(j < lenb)
		{
			digit = b[j]-'0' + carry;
			ret[k] = digit%10 + '0';
			carry = digit/10;
			j++, k++;
		}	
	}
	if(carry)
	{
		ret[k] = carry + '0';
		k++;
	}
	ret[k] = '\0';
	
	int zero = 0;
	for(i = 0; i < k; i++)
	{
		if(ret[i] == '0') 
		{
			if(zero) putchar(ret[i]);
		}
		else
		{
			putchar(ret[i]);
			zero = 1;
		}
	}
	if(zero == 0) putchar('0');
	puts("");	
	
}

int main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--)
	{
		char a[10000], b[10000];
		scanf("%s %s", a, b);
		add(b, a);	
	}
	return 0;
}
