#include<math.h>
#include<stdio.h>

int main (void)
{
    long long N, C, M, R;
    long long a[9999], i;


    while(scanf("%lld%lld", &N, &M) != EOF)
    {

        if(N < M || N < 2 || M < 2) printf("Boring!\n");
        else{
            R = 0;
            C = 0;
            while(1)
            {
                a[C] = N;

                if(N % M != 0) break;
                N /= M;
                C++;
            }

            if(a[C] == 1){
                printf("%lld", a[0]);
                for(i = 1; i <= C; i++)
                    printf(" %lld", a[i]);
                printf("\n");
            }
            else printf("Boring!\n");

        }
    }


    return 0;
}

