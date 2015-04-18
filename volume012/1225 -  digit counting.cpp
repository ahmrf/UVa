#include<stdio.h>
#include<string.h>
#define MAX 10000

int arr[MAX][10] = {0};

int number_of_digit(int num)
{
    int count = 0;
    while(num > 0){
        count++;
        num /= 10;
    }
    return count;
}

void CountDigit()
{
    memset(arr, 0, sizeof(arr));

    int i, j;
    for(i = 1; i < MAX; i++)
    {
        for(j = 0; j < 10; j++)
        {
            arr[i][j] = arr[i-1][j];
        }
        if(i < 10) arr[i][i]++;
        else
        {
            int l = number_of_digit(i);
            int num = i;
            for(j = 0; j < l; j++)
            {
                int rem = num % 10;
                arr[i][rem]++;
                num /= 10;
            }
        }

    }

}

int main (void)
{
    int i, n;
    CountDigit();
    int cases;
    scanf("%d", &cases);
    while(cases-- && scanf("%d", &n) == 1)
    {
        int f = 0;
        for(i = 0; i < 10; i++)
        {
            if(f == 1) printf(" ");
            printf("%d", arr[n][i]);
            f = 1;
        }

        printf("\n");
    }
    return 0;
}
