#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

bool balanced(string str)
{
    stack<char>myStack;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '(' || str[i] == '[') myStack.push(str[i]);
        else
        {
            if(myStack.size() == 0) return false;
            if((str[i] == ')' && myStack.top() == '(') || (str[i] == ']' && myStack.top() == '['))
                myStack.pop();
            else return false;
        }
    }
    if(myStack.size() == 0) return true;
    else return false;
}

int main (void)
{
    int cases;
    cin >> cases;
    string hudai;
    getline(cin, hudai);
    while(cases--)
    {
        string input;
        getline(cin, input);
        bool flag = balanced(input);
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
