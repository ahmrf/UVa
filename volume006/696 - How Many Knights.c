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

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) == 2 && m && n)
    {
        printf("%d knights may be placed on a %d row %d column board.\n", knights(n, m), n, m);
    }
    return 0;
}
