#include <string>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int to_decimal(string str, int base)
{
    int decimal = 0, k = str.length();
    double Base = base, xp = 0.0;
    for(int i=k-1; i>=0; i--)
    {
        int digit;
        if(str[i]<=70 && str[i]>=65)
        {
            digit = str[i]-55;
        }
        else digit = str[i]-'0';
        decimal += (int)pow(Base, xp)*digit;
        xp += 1.0;
    }
    return decimal;
}

string to_baseB(int num, int base)
{
    string bBased;
    while(num)
    {
        int digit = num%base;
        char charDigit;
        if(digit > 9) charDigit = 'A'+(digit-10);
        else charDigit = digit+'0';
        bBased = charDigit + bBased;
        num/=base;
    }
    return bBased;
}

int main (void)
{
    string s;
    int base,b;
    while(cin >> s >> base >> b)
    {
        cout.width(7);
		cout.setf(ios :: right);
		int flag = 0;
		for (int i = 0; s[i]; ++i){
			if (s[i] != '0')
				flag = 1;
		}

		if (!flag){
			cout << 0 << endl;
			continue;
		}
        else{
            int dec;
            if(base!=10) dec = to_decimal(s, base);
            else dec = atoi(s.c_str());
            string s = to_baseB(dec, b);
            int n = s.length();
            if(n > 7) cout << "  ERROR" << endl;
            else
            {
                cout << s << endl;
            }
        }
    }

    return 0;
}