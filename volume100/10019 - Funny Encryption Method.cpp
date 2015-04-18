#include<bits/stdc++.h>

using namespace std;

int binary(int num)
{
    int c = 0;
    while(num)
    {
        if(num %2 == 1) c++;
        num /= 2;
    }
    return c;
}

int hexa(int num)
{
    int c = 0, r;
    while(num)
    {
        r = num%10;
        num/=10;
        if(r == 1 || r == 2 || r == 4 || r == 8) c++;
        else if(r == 3 || r == 5 || r == 6 || r == 9) c+=2;
        else if(r == 7) c+=3;
    }
    return c;
}

int main()
{
    int cases, num;
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &num);
        printf("%d %d\n", binary(num), hexa(num));
    }
    return 0;
}
