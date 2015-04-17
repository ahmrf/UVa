#include<stdio.h>
struct rec
{
    double ux;
    double uy;
    double lx;
    double ly;
}recs[50];

int main (void)
{
    int c = 0, i, j=1;
    char r;
    while(1)
    {
        scanf("%c", &r);
        if(r=='*') break;
        else if(r=='r')
        {
            scanf("%lf%lf%lf%lf", &recs[c].ux, &recs[c].uy, &recs[c].lx, &recs[c].ly);
            c++;
        }
    }

    double x, y;
    while(scanf("%lf%lf", &x, &y)==2 && (x!=9999.9 && y!=9999.9))
    {
        int notfound = 1;
        for(i=0; i<c; i++)
        {
            if((x > recs[i].ux && x< recs[i].lx)&&(y<recs[i].uy && y>recs[i].ly))
            {
                printf("Point %d is contained in figure %d\n", j, i+1);
                notfound = 0;
            }
        }
        if(notfound) printf("Point %d is not contained in any figure\n", j);
        j++;
    }
    return 0;
}
