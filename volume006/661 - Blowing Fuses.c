#include<stdio.h>
#include<string.h>
int main (void)
{
    int n, m, c, i, j, s = 1, total, dop, blown, maxC;
    while(scanf("%d%d%d", &n, &m, &c) == 3)
    {
        if(!n && !m && !c) break;
        int *device = (int*) malloc(n*sizeof(int));
        int *operation = (int*)malloc(n*sizeof(int));
        memset(operation, 0, sizeof(int)*n);

        for(i=0; i<n; i++)
        {
            scanf("%d", &device[i]);
        }
        total = 0;
        blown = 0;
        maxC = -1;
        for(i=0; i<m; i++)
        {
            scanf("%d", &dop);
            dop--;
            if(!operation[dop])
            {
                operation[dop] = 1;
                total += device[dop];
                if(total > c)
                {
                    blown = 1;
                }
                else
                {
                    if(total > maxC) maxC = total;
                }
            }

            else
            {
                operation[dop] = 0;
                total -= device[dop];
            }
        }
        printf("Sequence %d\n", s++);
        if(blown) printf("Fuse was blown.\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", maxC);
        printf("\n");


        free(device);
        free(operation);
    }

    return 0;

}
