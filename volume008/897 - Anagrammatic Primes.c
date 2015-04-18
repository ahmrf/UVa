#include<stdio.h>

int main (void)
{
    int n, i, a, m;
    int ap[] =  {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
    int s = 22;
    while(scanf("%d", &n) == 1 && n)
    {
        a = 22;
        for(i = 21; i >= 0 && ap[i] > n; --i, --a);
        if(a < 22){
            m = 1;
            while(n)
            {
                m *= 10;
                n /= 10;
            }

            if(ap[a] < m) printf("%d\n", ap[a]);
            else printf("0\n");
        }

        else printf("0\n");
    }
    return 0;
}

