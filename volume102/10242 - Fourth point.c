#include<stdio.h>
int main ()
{
    double ax, ay, bx, by, cx, cy, dx, dy, ex, ey;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ax, &ay, &bx, &by, &cx, &cy, &dx, &dy) != EOF)
    {
        if(ax == bx && ay == by)
        {
            ex = cx + dx - ax;
            ey = cy + dy - ay;
        }

        else if(ax == cx && ay == cy)
        {
            ex = bx + dx - ax;
            ey = by + dy - ay;
        }

        else if(ax == dx && ay == dy)
        {
            ex = bx + cx - ax;
            ey = by + cy - ay;
        }

        else if(bx == cx && by == cy)
        {
            ex = ax + dx - bx;
            ey = ay + dy - by;
        }

        else if(bx == dx && by == dy)
        {
            ex = ax + cx - bx;
            ey = ay + cy - by;
        }

        else if(cx == dx && cy == dy)
        {
            ex = ax + bx - cx;
            ey = ay + by - cy;
        }
        printf("%.3lf %.3lf\n", ex, ey);
    }
    return 0;
}
