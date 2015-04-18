#include<bits/stdc++.h>

using namespace std;

char maze[40][100];


void paint(int x, int y)
{
    if(maze[x][y] == ' '||maze[x][y]== '*')
    {
        maze[x][y] = '#';
        paint(x+1, y);
        paint(x, y+1);
        paint(x, y-1);
        paint(x-1, y);
    }
}

int main ()
{
    int cases;
    scanf("%d", &cases);
    getchar();
    while(cases--)
    {
        int no = 0, x, y;

        bool found = false;
        while(gets(maze[no]))
        {
            if(maze[no][0] == '_') break;
            if(!found)
            {
                int len = strlen(maze[no]);
                for(int i=0; i<len; i++)
                {
                    if(maze[no][i]=='*')
                    {
                        x = no;
                        y = i;
                        found = true;
                        break;
                    }
                }
            }
            no++;
        }

        paint(x, y);
        for(int i=0; i<=no; i++)
            puts(maze[i]);
    }
    return 0;
}

