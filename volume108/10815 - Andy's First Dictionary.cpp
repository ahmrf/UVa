#include<vector>
#include<map>
#include<cstdio>
#include<string>
#include<cctype>
#include<algorithm>
#include<iostream>

using namespace std;

int main (void)
{
    char ch, Lch;
    map<string, int> Map;
    vector<string>dictionary;
    string word = "";
    while(scanf("%c", &ch) != EOF)
    {
        if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        {
            Lch = tolower(ch);
            word += Lch;
        }

        else
        {
            if(Map.find(word) == Map.end())
            {
                Map[word] = 1;
                if(word!="") dictionary.push_back(word);
            }

            word = "";
        }
    }

    if(Map.find(word) == Map.end())
    {
        Map[word] = 1;
        if(word!="") dictionary.push_back(word);
    }

    sort(dictionary.begin(), dictionary.end());
    int len = dictionary.size();

    for(int i = 0; i < len; i++)
    {
        cout << dictionary[i] << endl;
    }

    return 0;

}

