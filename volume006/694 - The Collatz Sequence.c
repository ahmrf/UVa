#include<stdio.h>

int main()
{
    int c = 0;
    long long int num, limit;
    while(scanf("%lld%lld", &num, &limit), num != -1 && limit != -1)
    {
        long long int N = num;
        int terms = 0;
        while(num <= limit)
        {
            if(num == 1)
            {
                terms++;
                break;
            }
            if(num%2)
            {
                num = num*3 + 1;
                terms++;
            }
            else
            {
                num /= 2;
                terms++;
            }
        }

        printf("Case %d: A = %lld, limit = %lld, number of terms = %d\n", ++c,  N, limit,terms);
    }
    return 0;
}
