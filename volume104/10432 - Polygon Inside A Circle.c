#include<stdio.h>
#include<math.h>

int main (void)
{
    double const cone = 4*acos(0.0);

    double r;
    int n;

    while(scanf("%lf%d", &r, &n) != EOF)
    {
        double A = cone/(double)n;
        double area = (double)n* .5 * r * r * sin(A);

        printf("%.3lf\n", area);
    }

    return 0;
}
