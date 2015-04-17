#include<bits/stdc++.h>
#define maxN 105

using namespace std;

vector<int> graph[maxN];
int source, check;
bool visited[maxN];

void dfs(int u)
{
    if(u != source || check != 0)
        visited[u] = true;
    check = 1;
    int sz = graph[u].size();
    for(int i = 0; i < sz; i++)
        if(!visited[graph[u][i]])
            dfs(graph[u][i]);
    return;
}

int main ()
{
    int N;
    while(scanf("%d", &N) == 1 && N)
    {
        int u, v;
        while(1)
        {
            scanf("%d", &u);
            if(u == 0) break;
            while(scanf("%d", &v) == 1)
            {
                if(v == 0) break;
                graph[u].push_back(v);
            }
        }

        int q;
        scanf("%d", &q);
        while(q--)
        {
            vector<int> unvisited;
            memset(visited, false, sizeof visited);
            check = 0;
            scanf("%d", &source);
            dfs(source);
            for(int i = 1; i <= N; i++)
                if(!visited[i])
                    unvisited.push_back(i);
            int sz = unvisited.size();
            printf("%d", sz);
            for(int i = 0; i < sz; i++)
                printf(" %d", unvisited[i]);
            puts("");
        }
        for(int i = 1; i <= N; i++)
            graph[i].clear();
    }
    return 0;
}
