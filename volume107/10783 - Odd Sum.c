#include<stdio.h>

int main (void)
{
    int cases, caseNo = 0;
    scanf("%d", &cases);

    while(cases--)
    {
        int a, b;
        scanf("%d%d", &a, &b);

        if(a%2 == 0) a++;
        if(b%2 == 0) b--;

        int n = (b-a)/2+1;

        printf("Case %d: %d\n", ++caseNo, (n+a-1)*n);
    }
    return 0;
}
