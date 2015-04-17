#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

struct content{
    char ch;
    int count;
};

int main (void)
{
    char c;
    vector<content>maze;
    vector<char>hehe;
    while(scanf("%c", &c) != EOF)
    {
        hehe.push_back(c);

    }

    int sum = 0;

    for(int i = 0; i < hehe.size(); i++)
    {
        content demo;
        demo.ch = hehe[i];
        if(demo.ch == '\n' || demo.ch == '!')
        {
            if(demo.ch == '!') demo.ch = '\n';
            demo.count = 1;
            maze.push_back(demo);
        }

        if(demo.ch >= 48 && demo.ch <= 57)
        {
            sum += (demo.ch - '0');
        }

        else
        {
            if(demo.ch == 'b') demo.ch = ' ';
            demo.count = sum;
            maze.push_back(demo);
            sum = 0;
        }
    }

    for(int i = 0; i < maze.size(); i++)
    {
        for(int j = 0; j < maze[i].count; j++)
        {
            cout << maze[i].ch;
        }
    }



    return 0;
}
