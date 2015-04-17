#include<iostream>
#include<string>

using namespace std;

int main (void)
{
    string codedString;

    while(getline(cin, codedString))
    {
        string decodedString;
        for(int i = 0; i < codedString.length(); ++i)
        {
            char ch = codedString[i] - 7;
            decodedString += ch;
        }

        cout << decodedString << endl;
    }


    return 0;
}
