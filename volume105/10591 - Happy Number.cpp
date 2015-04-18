#include<sstream>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int total(int num)
{
    stringstream ss;
    string str;
    ss << num;
    ss >> str;
    int l = str.length();
    int sum = 0;
    for(int i = 0; i < l; i++)
    {
        int d = str[i] - '0';
        sum += d*d;
    }

    return sum;
}

int main (void)
{
    long long int num, number;
    int cases;
    scanf("%d", &cases);
    for(int c = 1; c <= cases; c++)
    {
        scanf("%lld", &num);
        number = num;
        while(1)
        {
            if(num <= 9) break;

            num = total(num);
        }

        if(num == 1 || num == 7){
            printf("Case #%d: %lld is a Happy number.\n", c, number);
        }

        else printf("Case #%d: %lld is an Unhappy number.\n", c, number);
    }
    return 0;
}
