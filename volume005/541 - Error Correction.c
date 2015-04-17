#include<stdio.h>
int main (void)
{
    int n, matrix[100][100];
    while(scanf("%d", &n), n)
    {
        int rsum, csum, i, j;
        int rcount = 0, ccount = 0, r, c;
        for(i=0; i<n; i++)
        {
            rsum = 0;
            for(j=0; j<n; j++)
            {
                scanf("%d", &matrix[i][j]);
                rsum += matrix[i][j];
            }
            if(rsum % 2)
            {
                rcount++;
                r = i+1;
            }
        }

        for(i=0; i<n; i++)
        {
            csum = 0;
            for(j = 0; j<n; j++)
            {
                csum += matrix[j][i];
            }
            if(csum % 2)
            {
                ccount++;
                c = i + 1;
            }
        }

        if(rcount == 0 && ccount == 0) printf("OK\n");
        else if(rcount == 1 && ccount == 1) printf("Change bit (%d,%d)\n", r, c);
        else printf("Corrupt\n");
    }
    return 0;
}
