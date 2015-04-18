#include<map>
#include<cstdio>
#include<algorithm>

using namespace std;

int main (void)
{
    int n, q, i, j, t, s;

    for(j = 1; j != 0; j++)
    {
        scanf("%d%d", &n, &q);
        if(n == 0 && q == 0) break;
        int a[n];
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        sort(a, a+n);
        map<int, int> m;
        for(i = 0; i < n; i++)
        {
            if(m.find(a[i]) == m.end()) m[a[i]] = i+1;
        }

        printf("CASE# %d:\n", j);
        while(q--)
        {
            scanf("%d", &s);
            if(m.find(s) == m.end())
            {
                printf("%d not found\n", s);
            }
            else printf("%d found at %d\n", s, m[s]);
        }
    }

    return 0;
}
