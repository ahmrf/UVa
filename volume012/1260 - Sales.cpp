#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    int a[5000];
    scanf("%d", &cases);
    while(cases--)
    {
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
            scanf("%d", &a[i]);
        int c = 0;
        for(int i=1; i<N; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(a[j] <= a[i]) c++;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
