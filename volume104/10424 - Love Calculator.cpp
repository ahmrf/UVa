#include<sstream>
#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

string intIntoStr(int num)
{
    stringstream ss;
    ss << num;
    string str = ss.str();
    return str;
}

int sumOfDigit(string str)
{
    int sum = 0;
    for(int i = 0; i< str.length(); ++i)
    {
        if((str[i] <= 90 && str[i] >= 65) || (str[i] <= 122 && str[i] >= 97))
        {
            if(str[i] <= 90 && str[i] >= 65) str[i] = str[i] + 32;
            int digit = str[i] - 96;
            sum += digit;
        }

    }
    return sum;
}


int sumOfDigit2(string str)
{
    int sum = 0;
    for(int i = 0; i< str.length(); ++i)
    {
        int digit = str[i] - '0';
        sum += digit;
    }
    return sum;
}


int main()
{
    string str1, str2;
    while(getline(cin, str1) && getline(cin, str2))
    {
        int sum1 = sumOfDigit(str1), sum2 = sumOfDigit(str2);
        str1 = intIntoStr(sum1);
        str2 = intIntoStr(sum2);
        while(1)
        {
            if(str1.length() == 1) break;
            sum1 = sumOfDigit2(str1);
            str1 = intIntoStr(sum1);

        }

        sum1 = str1[0] - '0';

        while(1)
        {
            if(str2.length() == 1) break;
            sum2 = sumOfDigit2(str2);
            str2 = intIntoStr(sum2);

        }

        sum2 = str2[0] - '0';

        double ans;
        if(sum1 >= sum2) ans = ((double)sum2/(double)sum1)*100.000000;
        else ans = ((double)sum1/(double)sum2)*100.000000;

        printf("%.2lf %%\n", ans);

    }
    return 0;
}

