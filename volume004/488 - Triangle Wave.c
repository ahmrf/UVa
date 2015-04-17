#include<stdio.h>

int main (void)
{
    int cases, n;
    while(scanf("%d", &cases) == 1)
    {
        for(n = 1; n <= cases; n++)
        {
            int a, f, i, j, k;
            scanf("%d%d", &a, &f);

            for(k = 1; k <= f; k++)
            {
                for(i = 1; i <= a; i++)
                {
                    for(j = 1; j <= i; j++)
                    {
                        printf("%d", i);
                    }
                    printf("\n");
                }


                for(i = a-1; i >= 1; i--)
                {
                    for(j = 1; j <= i; j++)
                    {
                        printf("%d", i);
                    }
                    printf("\n");
                }
                if(n != cases || k!= f) printf("\n");
            }
        }
    }
    return 0;
}
