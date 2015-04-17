#include <iostream>
#include<string>
#include<cctype>

using namespace std;

int compare(char a, char b)
{
    if(a < b) return 1;
    else return 0;
}


string mySort (int index, string &str)
{
    for(int i = index; i < str.length(); i++)
    {
        for(int j = i + 1; j < str.length(); j++)
        {
            if(compare(str[j], str[i]) == 1)
            {
                char t = str[i];
                str[i] = str[j];
                str[j] = t;
            }
        }
    }

    return str;
}

bool nextPemutation(string &str)
{
    bool flag = false;

    for(int i = str.length()-2; i >= 0; i--)
    {
        if(compare(str[i], str[i+1]) == 1)
        {
            for(int j = str.length()-1; j > i; --j)
            {
                if(compare(str[i], str[j]) == 1)
                {
                    char t = str[i];
                    str[i] = str[j];
                    str[j] = t;
                    mySort(i+1, str);

                    break;

                }
            }
            flag = true;
            break;
        }
    }

    return flag;
}


int main (void)
{
    string a;
    while(cin >> a && a != "#")
    {
        bool flag = true;
        if(nextPemutation(a) == true) cout << a << endl;

        else cout << "No Successor" << endl;
    }

    return 0;
}
