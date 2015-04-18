#include<map>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main (void)
{
    map<string, string> mp_str;
    string line;
    while(getline(cin, line) && line != "")
    {
        string word[2];
        int i = 0;
        istringstream iss(line);

        while(iss >> word[i])
        {
            i++;
        }

        mp_str[word[1]] = word[0];

    }

    while(cin >> line)
    {
        if(mp_str.find(line) == mp_str.end()) cout << "eh" << endl;
        else cout << mp_str[line] << endl;
    }
    return 0;
}
