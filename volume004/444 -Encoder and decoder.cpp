#include<string>
#include<cstring>
#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>

using namespace std;

string to_string(int num)
{
    stringstream ss;
    string s;
    ss << num;
    ss >> s;
    return s;
}
int main (void)
{
    char asci[123], ch = '\0';
    for(int i = 0; i<123; i++)
        asci[i] = ch + i;
    string str;
    while(getline(cin, str))
    {
        int len = str.length();

        if(str[0] <= 57 && str[0] >= 48)
        {
            string s, out;
            for(int i = len-1; i >= 0; i--)
            {
                if(str[i] == '1')
                {
                    int num = (str[i]-'0')*100 + (str[i-1]-'0')*10 + str[i-2] - '0';
                    out += asci[num];
                    i-=2;
                }
                else
                {
                    int num = (str[i]-'0')*10 + str[i-1] - '0';
                    out += asci[num];
                    i--;
                }
            }
            cout << out << endl;
        }
        else
        {
            string out, s;
            for(int i = len-1; i>=0; i--)
            {
                int num = str[i];
                s = to_string(num);
                reverse(s.begin(), s.end());
                out += s;
            }
            cout << out << endl;
        }
    }
    return 0;
}

