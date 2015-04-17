#include<stdio.h>
#include<stdlib.h>



int main (void)
{
    int h, m;
    char ch;
    while(scanf("%d%c%d", &h, &ch, &m) == 3)
    {
        if(h == 0 && m == 0) break;
        if(h == 12) h = 0;
        double hAngle = 0.5 *(h*60 + m);
        double mAngle = 6* m;
        double angle;
        if(hAngle >= mAngle) angle = hAngle - mAngle;
        else angle = mAngle - hAngle;
        if(angle > (360-angle)) angle = 360-angle;
        printf("%.3lf\n", angle);
    }

    return 0;

}
