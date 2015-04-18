#include<map>
#include<string>
#include<iostream>

using namespace std;

string getpassword(int n, string str)
{
    int maxF = -1;
    map<string, int> f;
    string password;
    int len = str.length();
    for(int i = 0; i<len - n + 1; i++)
    {
        string s = str.substr(i, n);
        f[s]++;
    }
    for(std::map<string, int> :: const_iterator it = f.begin(); it != f.end(); it++)
    {
        if(it->second > maxF)
        {
            maxF = it->second;
            password = it->first;
        }
    }
    return password;
}

int main (void)
{
    string str;
    int N;
    while(cin >> N >> str) cout << getpassword(N, str) << endl;
    return 0;
}

