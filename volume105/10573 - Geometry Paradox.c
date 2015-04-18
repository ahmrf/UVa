#include<math.h>
#include<stdio.h>

#define PI acos(-1)

int main (void)
{
    int cases, r1, r2;
    double area;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &r1);
        if(getchar() == '\n')
        {
            area = PI*(r1*r1/4.0 - (r1*r1/8.0));
        }

        else
        {
            scanf("%d", &r2);
            area = PI* ((r1+r2)*(r1+r2) - (r1*r1 + r2*r2));
        }

        printf("%.4lf\n", area);


    }
    return 0;
}

