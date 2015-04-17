#include <stdio.h>
#include <string.h>

int main()
{
	int caseno = 1, n;
	char command[1000];
	while(scanf("%d", &n) == 1 && n)
	{
		getchar();
		char grid[11][11];
		
		for(int i = 0; i < 10; i++)
		{
			for(int j = 0; j < 10; j++)
			{
				grid[i][j] = ' ';
			}
		}
		int x = 0, y = 0, mode = 2;
		while(n--)
		{
			gets(command);
			int len = strlen(command);
			for(int i = 0; i < len; i++)
			{
				if(command[i] == '^')
				{
					if(command[i+1] == 'b') y = 0, i++;
					else if(command[i+1] == 'c')
					{
						for(int j = 0; j < 10; j++)
						{
							for(int k = 0; k < 10; k++)
							{
								grid[j][k] = ' ';
							}
						}
						i++;
					}
					else if(command[i+1] == 'd') 
					{
						if(x < 9) x++;
						i++;
					}
					else if(command[i+1] == 'e')
					{
						int j;
						for(j = y; j < 10; j++)
							grid[x][j] = ' ';
						i++;
					}
					else if(command[i+1] == 'h') x = 0, y = 0, i++;
					else if(command[i+1] == 'i') mode = 1, i++;
					else if(command[i+1] == 'l')
					{
						if(y > 0) y--;
						i++;
					} 
					else if(command[i+1] == 'o') mode = 2, i++;
					else if(command[i+1] == 'r') 
					{
						if(y < 9) y++;
						i++;
					}
					else if(command[i+1] == 'u')
					{
						if(x > 0) x--;
						i++;
					}
					else if(command[i+1] == '^')
					{
						if(mode == 1)
						{
							int j;
							for(j = 8; j >= y; j--)
								grid[x][j+1] = grid[x][j];
							grid[x][y] = '^';
						}
						else if(mode == 2) grid[x][y] = '^';
						i++;
						if(y < 9) y++;
						
					}
					else if(command[i+1] <= '9' && command[i+1] >= '0')
					{
						x = command[i+1] - 48;
						y = command[i+2] - 48;
						i+=2;
					}
				}

				else 
				{
				
					if(mode == 2)
					{
						grid[x][y] = command[i];
					}
					else if(mode == 1)
					{
						int j;
						for(j = 8; j >= y; j--)
							grid[x][j+1] = grid[x][j];
						grid[x][y] = command[i];
					}
					if(y < 9) y++;
				}
			}
		}
		printf("Case %d\n", caseno++);
		puts("+----------+");
		for(int i = 0; i < 10; i++)
		{
			printf("|");
			for(int j = 0; j < 10; j++)
			{
				printf("%c", grid[i][j]);
			}
			puts("|");
		}
		puts("+----------+");
	}
	return 0;
}