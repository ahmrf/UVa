#include<stdio.h>
int main (void)
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int sum, dif;
        scanf("%d%d", &sum, &dif);
        if(dif > sum) printf("impossible\n");
        else if(dif == sum) printf("%d 0\n", sum);
        else
        {
            int a = (sum + dif);
            if(a % 2 == 0){
                a /= 2;
                printf("%d %d\n", a, sum - a);
            }
            else printf("impossible\n");
        }
    }
    return 0;
}
