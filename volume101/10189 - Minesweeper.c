#include<stdio.h>
#include<string.h>

int di[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dj[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int r, c;
char grid[150][150];

char countMines(int i, int j)
{
    int count = 0, k;
    for(k = 0; k<8; k++)
    {
        int x = i + di[k];
        int y = j + dj[k];
        if(x < 0 || y < 0 || x >= r || y >= c) continue;
        if(grid[x][y] == '*') count++;
    }
    return count+'0';
}

int main (void)
{
    int cs = 1, enter = 0;
    while(scanf("%d%d", &r, &c) == 2)
    {
        if(r == 0 && c == 0) break;
        int i, j;
        for(i = 0; i<r; i++)
            scanf("%s", grid[i]);
        for(i = 0; i<r; i++)
        {
            for(j = 0; j<c; j++)
            {
                if(grid[i][j] == '.') grid[i][j] = countMines(i, j);
            }
        }
        if(enter) printf("\n");
        enter = 1;
        printf("Field #%d:\n", cs++);
        for(i = 0; i<r; i++)
        {
            for(j = 0; j<c; j++)
            {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
