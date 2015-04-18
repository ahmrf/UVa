#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define Maximum 1000001

int isPrimeWithinMax[Maximum];
int primeNumbers[330000];
int i, j, k ;


void sieve()
{
    primeNumbers[0] = 2;
    k = 1;
    memset(isPrimeWithinMax, 0, sizeof(isPrimeWithinMax));
    isPrimeWithinMax[0] = isPrimeWithinMax[1] = 1;
    for(i = 4; i < Maximum; i += 2) isPrimeWithinMax[i] = 1;
    for(i = 3; i*i <Maximum; i+=2)
    {
        if(isPrimeWithinMax[i] == 0)
        {
            for(j = i*i; j < Maximum; j += i+i) isPrimeWithinMax[j] = 1;
        }
    }

    for(i = 3; i < Maximum; i+=2)
    {
        if(isPrimeWithinMax[i] == 0)
        {
            primeNumbers[k] = i;
            k++;
        }
    }
}

int main (void)
{
    long long int num;
    sieve();

    while(scanf("%lld", &num), num != -1)
    {
        i = 0;
        int pf = primeNumbers[i];
        while(pf*pf <= num && i<k)
        {
            while(num % pf == 0)
            {
                num /= pf;
                printf("    %d\n", pf);
            }
            pf = primeNumbers[++i];
        }
        if(num != 1) printf("    %lld\n", num);

        printf("\n");
    }
    return 0;
}

