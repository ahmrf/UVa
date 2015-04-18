#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

string removeLeadingZero(string str)
{
    string a;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '0') str[i] = ' ';
        else break;
    }

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ');
        else a += str[i];
    }
    return a;
}

int carry(int sum)
{
    return sum/10;
}

int digit(int sum)
{
    return sum%10;
}

string add (string BigIntegerA, string BigIntegerB)
{
    int maxLength;
    if(BigIntegerA.length() >= BigIntegerB.length()) {
        maxLength = BigIntegerA.length();
        int l = BigIntegerB.length();
        for(int j = 0; j < maxLength-l; j++)
        {
            BigIntegerB = "0" + BigIntegerB;
        }
    }
    else {
        maxLength = BigIntegerB.length();
        int l = BigIntegerA.length();
        for(int j = 0; j < maxLength-l; j++)
        {
            BigIntegerA = "0" + BigIntegerA;
        }
    }


    int hateAche = 0;
    string result;
    for(int i = maxLength-1; i >= 0; i--)
    {
        int d = hateAche + (BigIntegerA[i] - '0') + (BigIntegerB[i] - '0');

        hateAche = carry(d);

        char ch = digit(d) + '0';
        result = ch + result;
    }

    if(hateAche > 0)
    {
        stringstream ss;
        ss << hateAche;
        string hateAcheString;
        ss >> hateAcheString;
        result = hateAcheString + result;
    }
    result = removeLeadingZero(result);
    return result;
}

int main (void)
{
    vector<string> fibonacci(1001);

    fibonacci[0] = "1";
    fibonacci[1] = "2";

    string sum;
    for(int i = 2; i < 1001; i++)
        fibonacci[i] = add(fibonacci[i-1], fibonacci[i-2]);

    int n;
    while(cin >> n)
    {
         cout << fibonacci[n] << endl;
    }


    return 0;
}


