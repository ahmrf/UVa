#include<stdio.h>
#include<math.h>

int main (void)
{
    double a, b, c;
    while(scanf("%lf%lf%lf", &a, &b, &c) != EOF)
    {
        double m = a*a*b*b + b*b*c*c + c*c*a*a;
        double n = a*a*a*a + b*b*b*b + c*c*c*c;
        if(2*m - n <= 0.000000) printf("-1.000\n");
        else printf("%.3lf\n", sqrt(2*m - n)/3.000000);

    }
    return 0;
}
