#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string removeSymbols(string str)
{
    string symbolFreeStr;
    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        {
            if(ch >= 97 && ch <= 122)
            {
                ch = ch - 32;
            }
            symbolFreeStr += ch;
        }
    }

    return symbolFreeStr;
}

int main (void)
{
    while(1)
    {
        string str;
        getline(cin, str);
        if(!str.compare("DONE")) break;

        string temp = removeSymbols(str);
        str = removeSymbols(str);

        reverse(temp.begin(), temp.end());
        if(!str.compare(temp)) cout << "You won't be eaten!" << endl;
        else cout << "Uh oh.." << endl;

    }

    return 0;
}
