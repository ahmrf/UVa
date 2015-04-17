#include<stdio.h>
#include<math.h>

#define PI acos(-1)

int main (void)
{

    double x1, y1, x2, y2, x3, y3;
    while(scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
    {
        double a = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        double b = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        double c = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
        a = sqrt(a);
        b = sqrt(b);
        c = sqrt(c);

        double s = (a+b+c) * (c+a-b) * (b+c-a) * (a+b-c);
        s = sqrt(s);
        double r = (a*b*c) / s;
        double circumference = 2 * PI * r;
        printf("%.2lf\n", circumference);
    }
    return 0;
}
