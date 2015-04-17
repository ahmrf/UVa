#include<iostream>
#include<sstream>
#include<string>

using namespace std;

int main (void)
{
    string line;
    while(getline(cin, line))
    {
        int l = line.length();
        for(int i = 0; i < l; i++)
        {
            if((line[i] <= 'z' && line[i] >= 'a') || (line[i] <= 'Z' && line[i] >= 'A'));
            else line[i] = ' ';
        }

        string word;
        int count = 0;
        istringstream iss(line);
        while(iss >> word)
            count++;

        cout << count << endl;
    }
    return 0;
}
