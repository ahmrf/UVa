#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;

int main(void)
{
    char ch;
    int c = 1;
    vector<char>str;
    while(scanf("%c", &ch) != EOF){
        if(ch =='"' && c == 1){
            ch = '`';
            str.push_back(ch);
            str.push_back(ch);
            c = 2;
        }

        else if(ch =='"' && c == 2){
            ch = '\'';
            str.push_back(ch);
            str.push_back(ch);
            c = 1;
        }

        else  str.push_back(ch);
    }

    for(int i = 0; i < str.size(); ++i)
    {
        cout << str[i];
    }



    return 0;
}
