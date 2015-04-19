#include<stdio.h>
#include<math.h>

int main (void)
{
    double L, f, v;
    while(scanf("%lf%lf", &L, &f)==2 && (L!=0 && f!=0))
    {
        v = sqrt(2*L*f);
        printf("%.8lf %.8lf\n", v, (v*3600.0)/(2.0*L));
    }
    return 0;
}
