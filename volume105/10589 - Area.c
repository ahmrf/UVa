#include<stdio.h>

int main()
{
    int N, a, M, n;
    double x, y, d, square, isInside;
    while(scanf("%d%d", &N, &a), N||a)
    {
        square = a*a;
        n = N;
        M = 0;

        while(N--)
        {
            scanf("%lf%lf", &x, &y);
            isInside = 1;

            if((x-0)*(x-0)+(y-0)*(y-0) > square) isInside = 0;
            if((x-0)*(x-0)+(y-a)*(y-a) > square) isInside = 0;
            if((x-a)*(x-a)+(y-0)*(y-0) > square) isInside = 0;
            if((x-a)*(x-a)+(y-a)*(y-a) > square) isInside = 0;

            if(isInside) M++;
        }

        printf("%.5lf\n", (double)(square*M)/n);
    }
    return 0;
}
