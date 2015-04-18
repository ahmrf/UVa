#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


int main(void)
{
    int k = 0;
    string str;
    while(getline(cin,str))
    {
        vector<char>symbols;
        vector<int>freq;

        for(int i = 0; i < str.length(); i++)
        {
            symbols.push_back(str[i]);
        }

        int limit = symbols.size();

        for(int i = 0; i < limit; i++)
        {
            int count = 1;
            for(int j = i+1; j < limit; j++)
            {
                if(symbols[i] == symbols[j])
                {
                    count++;
                    symbols.erase(symbols.begin()+j);
                    j--;
                    limit = symbols.size();
                }
                limit = symbols.size();
            }

            limit = symbols.size();

            freq.push_back(count);
        }

        for(int i = 0; i < symbols.size(); ++i)
        {
            for(int j = 0; j < symbols.size() - i - 1; ++j)
            {
                if(freq[j+1] < freq[j])
                {
                    int temp = freq[j];
                    freq[j] = freq[j+1];
                    freq[j+1] = temp;

                    char tempC = symbols[j];
                    symbols[j] = symbols[j+1];
                    symbols[j+1] = tempC;
                }

                else if(freq[j+1] == freq[j])
                {
                    if(symbols[j+1] > symbols[j])
                    {
                        char tempC = symbols[j];
                        symbols[j] = symbols[j+1];
                        symbols[j+1] = tempC;
                    }
                }
            }
        }

        if(k != 0) cout << endl;

        for(int i = 0; i < symbols.size(); ++i)
        {
            cout << (int)symbols[i] << " " << freq[i] << endl;
        }

        k++;

    }

    return 0;
}
