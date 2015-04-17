#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string getMirroredString(string str)
{
    string original = "E3JLS2Z5";
    string mirrored = "3ELJ2S5Z";

    int len = str.length();

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(str[i] == original[j]){
                str[i] = mirrored[j];
                break;
            }
        }
    }

    return str;
}

string makeOZero(string str)
{
    int len = str.length();
    for(int i = 0; i < len; i++)
    {
        if(str[i] == 'O') str[i] = '0';
    }

    return str;
}

int main (void)
{
    string str;
    while(cin >> str)
    {
        bool mir = false, pali = false;
        string oFree = makeOZero(str);

        string mirrored = getMirroredString(oFree);
        string temp1 = oFree, temp2 = mirrored;

        reverse(temp1.begin(), temp1.end());

        reverse(temp2.begin(), temp2.end());

        if(temp1 == oFree) pali = true;
        if(oFree == temp2)
        {
            mir = true;
            string harami = "BCDFGKNPQR4679";
            int l = oFree.length();
            for(int i = 0; i < l; i++)
            {
                for(int j = 0; j < 14; j++)
                {
                    if(oFree[i] == harami[j]){
                        mir = false;
                        break;
                    }
                }
            }
        }

        if(pali && mir) cout << str << " -- is a mirrored palindrome.\n" << endl;
        else if(pali && !mir) cout << str << " -- is a regular palindrome.\n" << endl;
        else if(!pali && mir) cout << str << " -- is a mirrored string.\n" << endl;
        else cout << str << " -- is not a palindrome.\n" << endl;
    }

    return 0;
}
