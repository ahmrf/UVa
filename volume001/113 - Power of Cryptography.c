#include<stdio.h>
#include<math.h>

int main (void)
{
    double n, k;

    while(scanf("%lf%lf", &k, &n) == 2)
    {
        double inK = 1.0000000000/k;
        printf("%.0lf\n", pow(n, inK));
    }

    return 0;
}
