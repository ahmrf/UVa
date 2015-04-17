#include<bits/stdc++.h>

using namespace std;

struct square
{
    int row;
    int column;
};

string s1,s2;
int moves[10][10];
bool visited[10][10];
int dx[]= {-2,-1, 1, 2, 2,1,-1,-2};
int dy[]= {-1,-2,-2,-1, 1,2, 2, 1};
int x, y, tx, ty;

void bfs()
{
    memset(visited, false, sizeof(visited));
    queue<square> qiu;
    visited[x][y] = true;
    moves[x][y] = 0;
    square s;
    s.row = x;
    s.column = y;
    qiu.push(s);

    while(!qiu.empty())
    {
        square u = qiu.front();
        qiu.pop();
        if(u.row == tx && u.column == ty)
        {
            cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<moves[u.row][u.column]<<" knight moves.\n";
            return ;
        }

        for(int i = 0; i < 8; i++)
        {
            int r = u.row + dx[i];
            int c = u.column + dy[i];

            if(r>=1 && r<=8 && c>=1 && c<=8 && !visited[r][c])
            {
                visited[r][c] = true;
                moves[r][c] = moves[u.row][u.column] + 1;
                square v;
                v.row = r, v.column = c;
                qiu.push(v);
            }
        }
    }
}

int main()
{
    while(cin >> s1 >> s2)
    {
        x = s1[0] - 96;
        y = s1[1] - '0';
        tx = s2[0] - 96;
        ty = s2[1] - '0';

        bfs();
    }
    return 0;
}
