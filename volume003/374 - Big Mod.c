#include<stdio.h>

int Mod(int x, int n, int M)
{
    if(n == 0) return 1;
    else if(n%2 == 0)
    {
        int y = Mod(x, n/2, M);
        return (y*y) % M;
    }

    else return ((x%M) * Mod(x, n-1, M)) % M;
}

int main (void)
{
    int x, n, M;
    while(scanf("%d %d %d", &x, &n, &M) != EOF)
    {
        printf("%d\n", Mod(x, n, M));
    }


    return 0;
}


