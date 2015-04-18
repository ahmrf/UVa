#include<stdio.h>
#include<string.h>

int NumberOfLostDays(int hparty[], int N, int P)
{
    int HortalDays[3651] = {0};
    int numberOfLostDays = 0;
    int i, j;
    for(i = 0; i < P; i++)
    {
        for(j = hparty[i]; j <= N; j += hparty[i])
        {
            int holiday = j % 7;
            if(holiday != 6 && holiday != 0 && !HortalDays[j])
            {
                HortalDays[j] = 1;
                numberOfLostDays++;
            }
        }
    }

    return numberOfLostDays;
}


int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int N, P, i;
        scanf("%d", &N);
        scanf("%d", &P);
        int hparty[100];
        for(i = 0; i < P; i++)
        {
            scanf("%d", &hparty[i]);
        }

        printf("%d\n", NumberOfLostDays(hparty, N, P));
    }

    return 0;
}
