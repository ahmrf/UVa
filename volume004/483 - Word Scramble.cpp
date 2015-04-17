#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
    string str;

    while(getline(cin, str))
    {
        string word;
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] != ' ') word += str[i];
            else
            {
                reverse(word.begin(), word.end());
                cout << word << " " ;
                word = "";
            }
        }
        reverse(word.begin(), word.end());
        cout << word << endl;
    }

    return 0;
}
