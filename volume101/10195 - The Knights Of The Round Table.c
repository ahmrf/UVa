#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, s, area;
	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		if(a == 0 || b == 0 || c == 0)
		{
			area = 0, s = 1;
		}
		else
		{
			s = (a+b+c)/2.0;
			area = sqrt(s*(s-a)*(s-b)*(s-c));
		}
		printf("The radius of the round table is: %.3lf\n", area/s);
	}
	return 0;
}