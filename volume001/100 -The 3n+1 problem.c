#include <stdio.h>

long long int countSteps(long long int number)
{
    long long int count = 1;
    while(1)
    {
        if(number == 1) break;
        if(number%2)
        {
            number = 3*number + 1;
            count++;
        }

        else
        {
            number/=2;
            count++;
        }
    }
    return count;
}

int main (void)
{
    long long int i, j;
    while(scanf("%lld %lld", &i, &j)!=EOF)
    {
        long long int tempI = i;
        long long int tempJ = j;
        if(i>=j){
            i = tempJ;
            j = tempI;
        }
        long long int maxLength = 0;
        while(i<=j)
        {
            long long int steps = countSteps(i);
            if(steps >= maxLength) maxLength = steps;
            i++;
        }

        printf("%lld %lld %lld\n", tempI, tempJ, maxLength);
    }
    return 0;
}

