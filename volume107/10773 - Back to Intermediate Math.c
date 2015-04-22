#include<stdio.h>
#include<math.h>

int main (void)
{
    int cases, case_no = 0;
    scanf("%d", &cases);
    while(cases--)
    {
        double d, v, u;
        scanf("%lf%lf%lf", &d, &v, &u);
        if(v >= u || v == 0 || u == 0) printf("Case %d: can't determine\n", ++case_no);
        else
        {
            double t = d / u;
            double T = d/ sqrt(u*u-v*v);
            printf("Case %d: %.3lf\n",++case_no, T-t);
        }
    }
    return 0;
}

