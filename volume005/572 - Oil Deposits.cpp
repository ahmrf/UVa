#include<cstdio>
#include<iostream>
#include<cstring>

using namespace std;

int di[] = { -1, 0, 1, 0, 1, 1, -1, -1 };
int dj[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int coun;
bool flag[101][101];
char grid[101][101];
int N, M;

void dfs(int i, int j)
{
    flag[i][j]=false;

    for(int k=0; k<8; k++)
    {
        int x = i+di[k];
        int y = j+dj[k];
        if(grid[x][y]=='@' && flag[x][y])
        {
            dfs(x, y);
        }
    }
}
int main (void)
{
    while(scanf("%d%d", &N, &M)==2 && (M && N))
    {
        for(int i=0; i<N; i++) scanf("%s", grid[i]);

        memset(flag, true, sizeof(flag));
        int oil = 0;
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {

                if(grid[i][j]=='@' && flag[i][j])
                {
                    oil++;
                    dfs(i,j);
                }
            }

        printf("%d\n", oil);
    }
    return 0;
}
