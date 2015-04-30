#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

bool myCompare(string a, string b)
{
    string x = a + b;
    string y = b + a;
    return (x > y) ? true : false;
}

int main (void)
{
    string s[50];
    int non;
    while(cin >> non, non)
    {
        for(int i=0; i<non; i++) cin >> s[i];
        sort(s, s + non, myCompare);
        for(int i=0; i<non; i++) cout << s[i];
        cout << endl;
    }
    return 0;
}


