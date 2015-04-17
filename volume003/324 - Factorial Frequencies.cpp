#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<map>

using namespace std;

struct content
{
    string s;
    map<char, int> m;
};

int carry(int sum)
{
    return sum/10;
}

int digit(int sum)
{
    return sum%10;
}

string removeLeadingZero(string str)
{
    string a;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '0') str[i] = ' ';
        else break;
    }

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ' ');
        else a += str[i];
    }

    if(a.length() == 0) return "0";
    else return a;
}



string add (vector<string>BigInteger)
{
    int maxLength = 0;
    for(int i = 0; i < BigInteger.size(); i++)
    {
        if(BigInteger[i].length() >= maxLength) maxLength = BigInteger[i].length();
    }

    for(int i = 0; i < BigInteger.size(); i++)
    {
        int l = BigInteger[i].length();
        for(int j = 0; j < maxLength-l; j++)
        {
            BigInteger[i] = "0" + BigInteger[i];
        }

    }

    int hateAche = 0;
    string result;
    for(int i = maxLength-1; i >= 0; i--)
    {
        int sum = hateAche;
        for(int j = 0; j < BigInteger.size(); j++)
        {
            int d = BigInteger[j][i] - '0';
            sum += d;
        }

        hateAche = carry(sum);

        char ch = digit(sum) + '0';
        result = ch + result;
    }

    if(hateAche > 0)
    {
        stringstream ss;;
        ss << hateAche;
        string hateAcheString;
        ss >> hateAcheString;
        result = hateAcheString + result;
    }

    return result;
}

string multiply(string str, char ch)
{
    int hateAche = 0;
    int mul = ch - '0';
    string result;
    for(int i = str.length()-1; i >= 0; i--)
    {
        int dig = str[i] - '0';
        dig = dig*mul + hateAche;
        ch = digit(dig) + '0';
        hateAche = carry(dig);
        result = ch + result;
    }

    if(hateAche > 0)
    {
        stringstream ss;
        ss << hateAche;
        string hateAcheString;
        ss >> hateAcheString;
        result = hateAcheString + result;
    }

    return result;
}

string MultiplyEvolution(string a, string b)
{
    int n = 0;
    vector<string> BigInteger;
    for(int i = b.length()-1; i >= 0; i--)
    {
        string mul = multiply(a, b[i]);
        for(int j = 0; j < n; j++)
        {
            char ch = '0';
            mul += ch;
        }
        n++;
        BigInteger.push_back(mul);

    }

    string res = add(BigInteger);
    res = removeLeadingZero(res);
    return res;

}

int main (void)
{
    int n, l;
    vector<content>factorials;


    string pro = "1";
    content c;
    for(int i = 1; i <= 366; i++)
    {
        stringstream ss;
        string a;
        ss << i;
        ss >> a;
        pro = MultiplyEvolution(pro, a);
        c.s = pro;
        l = pro.length();
        map<char, int> M;
        for(int j = 0; j<l; j++)
        {
            if(M.find(pro[j]) == M.end())
            {
                M[pro[j]] = 1;
            }

            else M[pro[j]]++;
        }

        c.m = M;


        factorials.push_back(c);
    }

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        map<char, int> myMap;
        myMap = factorials[n-1].m;
        cout << n << "! --" << endl;
        for(char i = '0'; i<= '4'; i++)
        {
            if(myMap.find(i) == myMap.end()) printf("   (%c)%5d", i, 0);
            else printf("   (%c)%5d", i, myMap[i]);
        }

        cout << endl;
        for(char i = '5'; i<= '9'; i++)
        {
            if(myMap.find(i) == myMap.end()) printf("   (%c)%5d", i, 0);
            else printf("   (%c)%5d", i, myMap[i]);
        }
        cout << endl;

    }

    return 0;
}



