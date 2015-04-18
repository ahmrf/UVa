#include<cmath>
#include<cstdio>
#include<string>
#include<iostream>
#include<sstream>


using namespace std;

int valueOfDigit(char ch)
{
    int value;
    if(ch <= '9' && ch >= '0')
    {
        value = ch - '0';
        return value;
    }

    else if(ch == 'A') return 10;
    else if(ch == 'B') return 11;
    else if(ch == 'C') return 12;
    else if(ch == 'D') return 13;
    else if(ch == 'E') return 14;
    else if(ch == 'F') return 15;
}

char makeIntChar(int num)
{
    if(num < 10)
    {
        char ch = num + '0';
        return ch;
    }

    else if(num == 10) return 'A';
    else if(num == 11) return 'B';
    else if(num == 12) return 'C';
    else if(num == 13) return 'D';
    else if(num == 14) return 'E';
    else if(num == 15) return 'F';
}

long long int ConvertIntoDecimal(string number)
{
    int l = number.length();
    long long int decimal = 0;
    double p = (double)l - 3.0;

    for(int i = 2; i < l; i++)
    {
        int digit = valueOfDigit(number[i]);
        double value = (double)digit * pow(16.0, p);
        int valueInt = value;
        decimal += value;
        p -= 1.0;
    }

    return decimal;
}

string ConvertIntoHexaDecimal(string number)
{
    stringstream ss;
    long long int num;
    ss << number;
    ss >> num;

    string hexaDecimal;

    while(num > 0)
    {
        int rem = num % 16;
        char ch = makeIntChar(rem);
        hexaDecimal = ch + hexaDecimal;
        num /= 16;
    }

    hexaDecimal = "0x" + hexaDecimal;
    return hexaDecimal;
}


int main (void)
{
    string number;
    while(cin >> number)
    {
        if(number[0] == '-') break;
        if(number[1] == 'x') cout << ConvertIntoDecimal(number) << endl;
        else cout << ConvertIntoHexaDecimal(number) << endl;

    }
    return 0;
}

