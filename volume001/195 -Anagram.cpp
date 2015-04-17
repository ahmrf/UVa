#include <iostream>
#include<string>
#include<cctype>

using namespace std;

int compare(char a, char b)
{
    if(tolower(a) == tolower(b))
    {
        if(a == b) return 0;
        else if(a<b) return -1;
        else return 1;
    }

    else if(tolower(a) < tolower(b)) return -1;
    else return 1;
}


string mySort (int index, string &str)
{
    for(int i = index; i < str.length(); i++)
    {
        for(int j = i + 1; j < str.length(); j++)
        {
            if(compare(str[i], str[j]) == 1)
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
        if(compare(str[i], str[i+1]) == -1)
        {
            for(int j = str.length()-1; j > i; --j)
            {
                if(compare(str[i], str[j]) == -1)
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

int main ()
{

    int cases;
    cin >> cases;
    while(cases--){
        string mychars;
        cin >> mychars;
        mySort (0, mychars);
        cout << mychars << endl;
        while(nextPemutation(mychars) == true)
        {
            cout << mychars << endl;
        }
    }

    return 0;
}



