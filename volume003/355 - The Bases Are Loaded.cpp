#include<bits/stdc++.h>
#define int64 long long int
using namespace std;


int int_value(char ch)
{
    if(ch <= '9' && ch >= '0') return ch-48;
    return ch-55;
}

bool is_valid(string number, int base)
{
    int nod = number.length();
    for(int i=0; i<nod; i++)
        if(int_value(number[i]) >= base) return false;
    return true;
}

char char_value(int digit)
{
    if(digit < 10) return digit+'0';
    return (digit-10)+'A';
}

int64 to_decimal(string number, int base)
{
    int64 decimal = 0;
    int nod = number.length();
    int xp = nod - 1;
    for(int i=0; i<nod; i++)
    {
        decimal += int_value(number[i]) * (int64)pow(base, xp);
        xp--;
    }
    return decimal;
}

string to_b_base(int64 decimal, int base)
{
    if(decimal == 0) return "0";
    string otherBase;
    while(decimal)
    {
        otherBase = char_value(decimal%base) + otherBase;
        decimal/=base;
    }
    return otherBase;
}

int main()
{
    int current, next;
    string number;
    while(cin >> current >> next >> number)
    {
        if(is_valid(number, current))
            cout << number << " base "<< current << " = " << to_b_base(to_decimal(number, current), next) << " base " << next << endl;
        else
            cout << number << " is an illegal base " << current << " number" << endl;
    }
    return 0;
}
