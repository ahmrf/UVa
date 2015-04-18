#include<math.h>
#include<stdio.h>

#define pi acos(-1)
#define R 6440.0;

int main(void)
{
    double s, a, arc, chord, ra;
    char type[4];
    while(scanf("%lf %lf %s", &s, &a, type) == 3)
    {
        if(a > 180) a = 360 - a;
        if(type[0] == 'm') a /= 60.0;
        s += R;
        ra = a * pi / 180.0;
        chord = 2*s*sin(ra/2.0);
        arc = s * ra;
        printf("%.6lf %.6lf\n", arc, chord);
    }
    return 0;
}
