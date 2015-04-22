#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main (void)
{
    int cases;
    long long int x1, x2, y1, y2, dx, dy, dd;
    scanf("%d", &cases);
    while(cases--)
    {
        int m, n;
        scanf("%d%d", &m, &n);
        while(m--){
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            dx = x1-x2;
            dy = y1-y2;
            dd = abs(dx)-abs(dy);

            if(x1 > n || x2 > n || y1 > n || y2 > n) printf ("no move\n");
            else if(x1==x2 && y1==y2) printf("0\n");
            else if(abs(dx) == abs(dy)) printf("%d\n", 1);
            else if(x1==x2 && (dy)%2 == 0) printf("%d\n", 2);
            else if(y1==y2 && (dx)%2 == 0) printf("%d\n", 2);
            else if((dx)%2 == 0 && (dy)%2 == 0) printf("%d\n", 2);
            else if (dd%2 == 0) printf("%d\n", 2);
            else printf ("no move\n");
        }
    }

    return 0;
}


