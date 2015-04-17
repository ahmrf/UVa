#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

bool vowel (char ch)
{

    string vowelString = "AaEeIiOoUu";
    for(int i = 0; i < 10; i++)
    {
        if(ch == vowelString[i]) return true;
    }
    return false;
}

string removeSymbols(string str)
{
    int lomba = str.length();
    for(int i = 0; i < lomba; i++)
    {
        if(!((str[i] <= 'z' && str[i] >= 'a') || (str[i] <= 'Z' && str[i] >= 'A'))) str[i] = ' ';
    }

    return str;
}

string manupulate (string str)
{
    string manupulatedString;
    int lomba = str.length();
    if(lomba == 1)
    {
        manupulatedString += (str + "ay");
        return manupulatedString;
    }
    for(int i = 1; i < lomba; i++)
            manupulatedString += str[i];

    if(vowel(str[0]) == false) manupulatedString += str[0];
    else manupulatedString = str[0] + manupulatedString;

    manupulatedString += "ay";
    return manupulatedString;
}

int main (void)
{
    string input;
    while(getline(cin, input))
    {
        string copyInput = input;
        input = removeSymbols(input);
        istringstream iss(input);
        string word;
        vector<string> words, words2;

        while(iss >> word)
        {
            words.push_back(word);
            word = manupulate(word);
            words2.push_back(word);
        }

        string output;

        int lomba = copyInput.length(), j = 0;
        for(int i = 0; i < lomba; i++)
        {
            if((copyInput[i] >= 91 && copyInput[i] <= 96) || copyInput[i] <= 64 || copyInput[i] >= 123 || copyInput[i] == ' ')
            {
                output += copyInput[i];
            }
            else
            {
                output += words2[j];
                int len = words[j].length();
                j++;
                len--;
                i += len;
            }
        }
        int limit = output.length();
        if(copyInput[lomba-1] >= 'a' && copyInput[lomba-1] <= 'z') limit -= 3;
        else if(copyInput[lomba-1] >= 'A' && copyInput[lomba-1] <= 'Z') limit -= 3;
        for(int i = 0; i < limit; i++) cout << output[i];
        cout << endl;

    }

    return 0;
}
