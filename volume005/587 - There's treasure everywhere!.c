#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
	const double sqrt2 = sqrt(2);
	char s[250];
	int map = 1;
	while(scanf("%s", s) == 1)
	{
		if(!strcmp(s, "END")) break;
		int i, j = -1;
		double x = 0, y = 0;
		char command[20];
		for(i = 0; s[i]; i++)
		{
			if(s[i] == ',' || s[i] == '.')
			{
				command[j+1] = '\0';
				int n = atoi(command);
				double a = (double)n;
				if(command[j-1] <= 'Z' && command[j-1] >= 'A')
				{
					if(command[j-1] == 'N' && command[j] == 'W')
					{
						x -= a/sqrt2;
						y += a/sqrt2;
					}
					else if(command[j-1] == 'N' && command[j] == 'E')
					{
						x += a/sqrt2;
						y += a/sqrt2;
					}
					else if(command[j-1] == 'S' && command[j] == 'W')
					{
						x -= a/sqrt2;
						y -= a/sqrt2;
					}
					else if(command[j-1] == 'S' && command[j] == 'E')
					{
						x += a/sqrt2;
						y -= a/sqrt2;
					}
				}
				else
				{	

					if(command[j] == 'N')
						y += a;
					else if(command[j] == 'E')
						x += a;
					else if(command[j] == 'S')
						y -= a;
					else if(command[j] == 'W')
						x -= a;
				}
				j = -1;
			}

			else
			{
				command[++j] = s[i];
			}
		}
		printf("Map #%d\n", map++);
		printf("The treasure is located at (%.3lf,%.3lf).\n", x, y);
		printf("The distance to the treasure is %.3lf.\n", sqrt(x*x+y*y));
		puts("");
	}

	return 0;
}