#include<string>
#include<iostream>
#include<vector>

using namespace std;

int main (void)
{
    vector<string> store;
    string a;
    int s, maxS = 0;
    while(getline(cin, a))
    {
        store.push_back(a);
        s = a.length();
        if(s > maxS) maxS = s;
    }
    int S = store.size();
    for(int i = 0; i<S; i++)
    {
        s = a.length();
        for(int j = 0; j < maxS-s; j++)
        {
            store[i] += ' ';
        }
    }

    for(int i = 0; i < maxS; i++)
    {
        for(int j = S-1; j >= 0; j--)
        {
            cout << store[j][i];
        }
        cout << endl;
    }
    return 0;
}

