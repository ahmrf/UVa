#include<bits/stdc++.h>
#define EPS 1e-9

using namespace std;

int p, q, r, s, t, u;

double evaluate(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double solve()
{
    double a = 0, b = 1;
    while(a + EPS < b)
    {
        double x = (a+b)/2;
        if(evaluate(a)*evaluate(x)<=0)
            b = x;
        else a = x;
    }
    return (a+b)/2;
}

int main()
{
    while (scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF)
    {
        if (evaluate(0) * evaluate(1) > 0)
            puts("No solution");
        else
            printf("%.4lf\n", solve());
    }
    return 0;
}
