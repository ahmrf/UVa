#include<stdio.h>

int remainder(int n, int k)
{
    return n%k;
}

int division(int n, int k)
{
    return n/k;
}


int main(void)
{
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        int N = n;
        int count = n;

        while(1)
        {
            int d = division(N, k);
            if(d == 0) break;
            count += d;
            N = remainder(N,k) + d;
        }

        printf("%d\n", count);
    }

    return 0;
}
