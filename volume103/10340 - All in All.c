#include<stdio.h>
#include<string.h>
#define MAX 100000

int max(int a, int b)
{
    return (a > b)? a : b;
}

int LCS(char *X, char *Y, int m, int n)
{
    int L[m+1][n+1];
    int i, j;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0) L[i][j] = 0;

            else if (X[i-1] == Y[j-1]) L[i][j] = L[i-1][j-1] + 1;

            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }


    return L[m][n];
}
int main ()
{
    char a[MAX], b[MAX];
    while(scanf("%s %s", a, b) != EOF)
    {
        int len = strlen(a);
        int l = LCS(a, b, strlen(a), strlen(b));
        if(l == len) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


