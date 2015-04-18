#include<stdio.h>

int main (void)
{
    int cases;
    scanf("%d", &cases);

    while(cases--)
    {
        int noOfFarmer;
        scanf("%d", &noOfFarmer);

        int sizeOfYard, noOfAnimal, degree;
        long long int result = 0;

        while(noOfFarmer--)
        {
            scanf("%d%d%d", &sizeOfYard, &noOfAnimal, &degree);
            result += (sizeOfYard*degree);
        }

        printf("%lld\n",result);
    }

    return 0;
}
