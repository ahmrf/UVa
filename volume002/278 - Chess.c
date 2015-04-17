#include<stdio.h>

int knights(int n, int m)
{
    if(m==1||n==1) return m*n;
    if(m==2||n==2){
        int ans=m*n/8*4;
        if((m*n)%8==2) return ans+=2;
        if((m*n)%8==6||(m*n)%8==4) return ans+=4;
    }
    return (m*n+1)/2;
}

int rooksAndQueens(int n, int m)
{
    return (n < m)? n : m;
}

int kings(int n, int m)
{
    if(m%2) m++;
    if(n%2) n++;
    return (m*n)/4;
}

int solve(char guti, int n, int m)
{
    if(guti == 'r' || guti== 'Q') return rooksAndQueens(n, m);
    else if(guti == 'K') return kings(n, m);
    else return knights(n, m);
}

int main (void)
{
    int cases, n, m;
    char guti;
    scanf("%d", &cases);

    while(cases--)
    {
        getchar();
        scanf("%c %d %d", &guti, &n, &m);
        printf("%d\n", solve(guti, n, m));
    }
    return 0;
}
