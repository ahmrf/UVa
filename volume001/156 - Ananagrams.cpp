#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

void lowerCase(string &str)
{
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] >= 65 && str[i] <= 90) str[i] = str[i] + 32;
    }
}

int main (void)
{
    vector<string>container;
    vector<string>result;


    while(1)
    {
        string str;
        getline(cin, str);
        if(str == "#") break;

        if(str[0] == ' ') str[0] = '1';
        string word;

        for(int i = 0; i<str.length(); ++i)
        {
            if(str[i] == '1');
            else if(str[i] == ' '){
                container.push_back(word);
                word = "";
            }

            else word += str[i];
        }

        if(word != "") container.push_back(word);

    }

    for(int i = 0; i < container.size(); ++i)
    {
        string word = container[i];

        lowerCase(word);

        sort(word.begin(), word.end());


        int c = 0;
        for(int j = 0; j < container.size(); ++j)
        {
            string a = container[j];

            lowerCase(a);

            sort(a.begin(), a.end());

            if(word == a){
                c++;
            }
        }

        if(c == 1) result.push_back(container[i]);
    }

    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }

    container.clear();
    result.clear();

    return 0;

}
