#include<stdio.h>

#define MAX 500001

int array[MAX];

int main (void)
{
    int i, temp = 2;
    array[1] = 1;
    array[2] = 2;
    for(i = 3; i < MAX; i++)
    {
        if(temp > i) temp = 2;
        array[i] = temp;
        temp += 2;
    }

    int n;
    while(scanf("%d", &n), n)
    {
        printf("%d\n", array[n]);
    }

    return 0;

}
