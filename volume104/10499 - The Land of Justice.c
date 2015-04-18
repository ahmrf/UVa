#include<stdio.h>
int main ()
{
    long long n;
    while(scanf("%lld", &n), n > -1) (n==1)? printf("0%%\n"): printf("%lld%%\n", n*25);
    return 0;
}
