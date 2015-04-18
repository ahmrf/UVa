#include<stdio.h>

#define MAX 1000000

int a[MAX], b [MAX] , c[MAX];
int main (void)
{
    int cases, f = 0;
    scanf("%d", &cases);
    while(cases--)
    {
        int n, i;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a[i], &b[i]);
        }
        int hate = 0, r;
        for(i = n-1; i >= 0; i--)
        {
            r = a[i] + b[i] + hate;
            if(r > 9) hate = 1;
            else hate = 0;
            c [i] = r%10;
        }
        if(f == 1) printf("\n");
        f = 1;
        for(i = 0; i < n; i++)
        {
            printf("%d", c[i]);
        }
        printf("\n");

    }
    return 0;
}
