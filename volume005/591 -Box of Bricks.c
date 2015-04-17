#include<stdio.h>
int main (void)
{
    int case_no = 0;
    int n;
    while(scanf("%d", &n) == 1 && n)
    {
        int h[n], i, avg = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &h[i]);
            avg += h[i];
        }

        avg /= n;

        int moves = 0;
        for(i = 0; i < n; i++)
        {
            if(h[i] > avg) moves += (h[i] - avg);
        }

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++case_no, moves);

    }
    return 0;
}
