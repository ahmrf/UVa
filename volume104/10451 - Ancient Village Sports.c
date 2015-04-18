#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main (void)
{
    int n, i=1;
    double A, A1, A2, R, r, c;
    while(scanf("%d %lf", &n, &A)==2 && n>2)
    {
        R = sqrt((2*A/n)/sin(2*PI/n));
        c = R*sin(PI/n);
        r = sqrt(R*R-c*c);
        A1=PI*R*R;
        A2=PI*r*r;
        printf("Case %d: %.5lf %.5lf\n", i++, A1-A, A-A2);
    }
    return 0;
}
