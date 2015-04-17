#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int index(char ch)
{
    if(ch >= 'a' && ch <= 'z') return (ch - 71);
    else return (ch - 65);
}

int main (void)
{
    string line;
    while(getline(cin, line))
    {
        int len = line.length();
        int frequency[52];
        memset(frequency, 0, sizeof(frequency));

        for(int i = 0; i < len; i++)
        {
            if((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))
            {
                int in = index(line[i]);
                frequency[in]++;
            }
        }

        int maxF = 0;
        vector<char> letters;

        for(int i = 0; i < 52; i++)
        {
            char ch;
            if(i < 26) ch = 'A' + i;
            else if (i >= 26)  ch = 'a' + (i-26);
            if(frequency[i] >= maxF)
            {
                if(frequency[i] > maxF) letters.clear();
                maxF = frequency[i];
                letters.push_back(ch);
            }
        }

        len = letters.size();
        for(int i = 0; i < len; i++)
            cout << letters[i];

        cout << " " << maxF << endl;
    }
    return 0;
}
