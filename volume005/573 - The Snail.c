#include<stdio.h>
#include<math.h>

int main (void)
{
    double H, U, D, F, S;
    int count;
    while(scanf("%lf %lf %lf %lf", &H, &U, &D, &F) == 4)
    {
        if(H == 0) break;
        F = U*F/100.00;
        count = 0;
        S = 0.0;

        while(1)
        {
            count++;
            if(U > 0) S += U;
            U -= F;

            if(S > H) break;
            S -= D;
            if(S < 0) break;
        }

        if(S >= 0) printf("success on day %d\n", count);
        else printf("failure on day %d\n", count);


    }
    return 0;
}
