#include<stdio.h>
#include<string.h>

int main (void)
{
    int cases, len, i, sum, c;
    char ox[100];
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%s", ox);
        len = strlen(ox);
        sum = 0;
        c = 0;
        for(i=0; i<len; i++)
        {
            if(ox[i] == 'O') c++;
            else if(ox[i] == 'X')
            {
                sum += (c*(c+1))/2;
                c = 0;
            }
        }

        sum += (c*(c+1))/2;

        printf("%d\n", sum);
    }
    return 0;
}
