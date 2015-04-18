#include<stdio.h>

int main()
{
    char names[10001][25];
    int lower_price[10001], highest_price[10001], i, j, pos, Q, amount, cases, n;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%s %d %d", names[i], &lower_price[i], &highest_price[i]);
        scanf("%d", &Q);
        while(Q--)
        {
            pos = -1;
            scanf("%d", &amount);
            for(i = 0; i < n; i++)
                if(amount >= lower_price[i] && amount <= highest_price[i])
                {
                    if(pos < 0)
                        pos = i;
                    else
                    {
                        pos = -1;
                        break;
                    }
                }

            if(pos < 0) printf("UNDETERMINED\n");
            else printf("%s\n", names[pos]);

        }
        if(cases) printf("\n");
    }

    return 0;
}
