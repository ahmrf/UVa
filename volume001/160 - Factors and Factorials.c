#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    int prime_factor[26], prime[25];
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11;
    prime[5] = 13;
    prime[6] = 17;
    prime[7] = 19;
    prime[8] = 23;
    prime[9] = 29;
    prime[10] = 31;
    prime[11] = 37;
    prime[12] = 41;
    prime[13] = 43;
    prime[14] = 47;
    prime[15] = 53;
    prime[16] = 59;
    prime[17] = 61;
    prime[18] = 67;
    prime[19] = 71;
    prime[20] = 73;
    prime[21] = 79;
    prime[22] = 83;
    prime[23] = 89;
    prime[24] = 97;
    int a, b, c, d, n, i, j;
    while(scanf("%d", &n) == 1 && n != 0){
        for(i=0; i<25; i++){
            c = n;
            d = 0;
            while(1){
                if(c == 0) break;
                c /= prime[i];
                d += c;
            }
            prime_factor[i] = d;

        }
        prime_factor[25] = 0;

        printf("%3d! =", n);

        for(j= 0; j<25; j++)
        {
            if(prime[j] > n ) break;
            printf("%3d", prime_factor[j]);


            if((j+1) % 15 == 0 && prime[j+1] <= n)
            {

                printf("\n      ");
            }
        }

        printf("\n");
    }
    return 0;
}
