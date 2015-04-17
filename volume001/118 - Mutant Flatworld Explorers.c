#include <string.h>
#include <stdio.h>

int main()
{
	char command[110], orientation[10], direction;
	int lost[100][100] = {}, sx, sy, x, y, i, flag;
	scanf("%d %d", &x, &y);

	while(scanf("%d %d %s", &sx, &sy, orientation) == 3)
	{
		direction = orientation[0];
		scanf("%s", command);

		flag = 0;
		for(i = 0; command[i]; i++)
		{
			if(command[i] == 'F')
			{
				switch(direction)
				{
					case 'N' : sy++; break;
					case 'E' : sx++; break;
					case 'S' : sy--; break;
					case 'W' : sx--; break;
				}
			}
			else if(command[i] == 'R')
			{
				switch(direction)
				{
					case 'N' : direction = 'E'; break;
					case 'E' : direction = 'S'; break;
					case 'S' : direction = 'W'; break;
					case 'W' : direction = 'N'; break;
				}
			}
			else
			{
				switch(direction)
				{
					case 'N' : direction = 'W'; break;
					case 'W' : direction = 'S'; break;
					case 'S' : direction = 'E'; break;
					case 'E' : direction = 'N'; break;	
				}

			}
			if(sx < 0 || sy < 0 || sx > x || sy > y)
			{
				switch(direction)
				{
					case 'N' : sy--; break;
					case 'E' : sx--; break;
					case 'S' : sy++; break;
					case 'W' : sx++; break;
				}	
				if(lost[sx][sy] == 1) continue;
				flag = 1;
				lost[sx][sy] = 1;
				break;
			}

		}
		if(!flag) printf("%d %d %c\n", sx, sy, direction);
		else printf("%d %d %c LOST\n", sx, sy, direction);
	}
	return 0;
}


