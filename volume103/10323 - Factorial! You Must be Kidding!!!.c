#include<stdio.h>
int main (void)
{
    int n;
    long long int i;

    long long int a[15];
    a[8] = 40320;
    a[9] = 362880;
    a[10] = 3628800;
    a[11] = 39916800;
    a[12] = 479001600;
    a[13] = 6227020800;



    while(scanf("%d", &n) != EOF)
    {
        if(n < 0)
        {
            if( n / 2 * 2 == n)
                printf("Underflow!\n");
            else
                printf("Overflow!\n");
        }
        else if(n >= 8 && n <= 13) printf("%lld\n", a[n]);
        else if(n > 13) printf("Overflow!\n");
        else if(n < 8)printf("Underflow!\n");
    }

    return 0;
}
