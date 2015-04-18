#include<stdio.h>
#include<math.h>

int main (void)
{
    double const pi = 2* acos(0.0);
    double const coneA = (pi*108)/180;
    double const coneB = (pi*63)/180;
    double const constant = sin(coneA)/sin(coneB);
    double length;

    while(scanf("%lf", &length) != EOF)
    {
        printf("%.10lf\n", length*constant);
    }


    return 0;
}
