#include<stdio.h>
#include<math.h>

#define PI acos(-1)

int main (void)
{
    double L, D;
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%lf %lf", &D, &L);
        printf("%.3lf\n", PI * (L/2.0)*sqrt(L*L/4.0 - D*D/4.0));
    }
    return 0;
}
