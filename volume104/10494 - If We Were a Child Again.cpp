#include<bits/stdc++.h>

using namespace std;

string division(string vajjo, long long int vajok)
{
    long long int rem = 0;
    string vagfol;
    int sl = vajjo.length();
    bool f = true;
    for(int i = 0; i < sl; i++)
    {
        rem = vajjo[i]-'0' + rem * 10;
        if(rem / vajok != 0) f = false;
        if(!f)
        {
            long long int v = rem/vajok;
            stringstream ss;
            string s;
            ss << v;
            ss >> s;
            vagfol += s;
        }
        rem = rem % vajok;
    }
    if(f) vagfol += "0";
    return vagfol;
}

long long int reminder(string vajjo, long long int vajok)
{
    long long int rem = 0;
    int sl = vajjo.length();
    for(int i=0; i<sl; i++)
    {
        rem = (rem*10 + vajjo[i]-'0') % vajok;
    }
    return rem;
}

int main()
{
    string a;
    char sign;
    long long int vajok;
    while(cin >> a >> sign >> vajok)
    {
        (sign == '/')? cout << division(a, vajok) << endl : cout << reminder(a, vajok) << endl;
    }
    return 0;
}

