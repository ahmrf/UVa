#include<string.h>
#include<stdio.h>

int main()
{
    int x, y, _x, _y, found, valid, k, i, len;
    char grid[5][6], moves[1000];
    for(k = 1; ; k++)
    {
        found = 0;
        for(y = 0; y < 5; ++y)
        {
            gets(grid[y]);
            if(!strcmp(grid[0], "Z"))
                return 0;
            if(!found)
                for(x = 0; x < 5; x++)
                    if(grid[y][x] == ' ')
                    {
                        found = 1;
                        _y = y;
                        _x = x;
                        break;
                    }
        }

        valid = 1;
        while(gets(moves))
        {
            len = strlen(moves);
            if(valid)
            {
                for(i = 0; i < len; i++)
                {
                    if(moves[i] == '0') break;
                    else if(moves[i] == 'A') y = _y - 1, x = _x;
                    else if(moves[i] == 'B') y = _y + 1, x = _x;
                    else if(moves[i] == 'L') y = _y, x = _x - 1;
                    else if(moves[i] == 'R') y = _y, x = _x + 1;

                    if(x >= 0 && x < 5 && y >= 0 && y < 5)
                    {
                        grid[_y][_x] = grid[y][x];
                        grid[y][x] = ' ';
                        _x = x, _y = y;
                    }
                    else
                        valid  = 0;
                }
            }
            if(moves[len-1] == '0') break;
        }
        if(k > 1) printf("\n");
        printf("Puzzle #%d:\n", k);
        if(valid)
            for(y = 0; y < 5; y++)
            {
                for(x = 0; x < 4; x++)
                    printf("%c ", grid[y][x]);
                printf("%c\n", grid[y][4]);
            }
        else
            printf("This puzzle has no final configuration.\n");
    }
    return 0;
}

