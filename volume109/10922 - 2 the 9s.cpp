#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int sum(string str)
{
    int s = str.length(), total = 0;
    for(int i = 0; i < s; i++) total += (str[i] - '0');
    return total;
}

string convertIntoS(int num)
{
    stringstream ss;
    string str;
    ss << num;
    ss >> str;
    return str;
}

int main (void)
{
    string str;
    while(cin >> str && str.compare("0"))
    {
        if(sum(str) % 9) cout << str << " is not a multiple of 9." << endl;
        else
        {
            if(str == "9")
            {
                cout << "9 is a multiple of 9 and has 9-degree 1." << endl;
                continue;
            }
            string s = str;
            int count = 0;
            while(1)
            {

                if(str == "9") break;
                int total = sum(str);
                count++;
                str = convertIntoS(total);
            }

            cout << s << " is a multiple of 9 and has 9-degree " << count << "." << endl;
        }
    }
    return 0;
}
