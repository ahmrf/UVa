#include<stdio.h>
#include<stdlib.h>


int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main (void)
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int a[n];
        int dif[n-1];

        int i, temp;

        for(i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            if(i != 0)
            {
                if(a[i] >= temp) dif[i-1] = a[i] - temp;
                else dif[i-1] = temp-a[i];
            }
            temp = a[i];
        }

        int flag = 1;
        qsort (dif, n-1, sizeof(int), compare);
        for(i = 0; i < n-2; ++i)
        {
            if(dif[i] == dif[i+1] || dif[i] < 1 || dif[i] >= n || dif[i+1] < 1 || dif[i+1] >= n)
            {
                flag = 2;
                break;
            }
        }

        if(flag == 1) printf("Jolly\n");
        else printf("Not jolly\n");
    }

    return 0;
}
