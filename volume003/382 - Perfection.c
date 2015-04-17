#include<stdio.h>
#define MAX 60001
int main (void)
{

    int n, i, sum[MAX], count;
    sum[0] = 0;
    sum[1] = 0;
    sum[2] = 1;
    sum[3] = 1;
    for(n = 4; n < MAX; n++)
    {
        count = 1;
        for(i = 2; i < n/2; i++)
        {
            if(n%i == 0) count += i;
        }

        sum[n] = count;
    }


    int a, flag = 0;
    while(scanf("%d", &a) == 1 && a != 0)
    {
        if(flag == 0) printf("PERFECTION OUTPUT\n");
        flag = 1;
        if(a >= 1 && a <= 3) printf("%5d  DEFICIENT\n", a);
        else{
            count = 1;
            for(i = 2; i <= a/2; i++)
            {
                if(a%i == 0) count += i;
            }
            if(count ==  a) printf("%5d  PERFECT\n", a);
            else if(count > a) printf("%5d  ABUNDANT\n", a);
            else printf("%5d  DEFICIENT\n", a);

        }

    }

    printf("END OF OUTPUT\n");
    return 0;

}
