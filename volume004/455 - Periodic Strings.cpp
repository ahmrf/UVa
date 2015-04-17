#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

#define MAX 100

bool p[MAX];

void sieveMethod()
{
    p[0] = p[1] = true;

    for(int i = 4; i < MAX; i += 2)
    {
        p[i] = true;
    }

    int sq = sqrt(MAX);

    for(int i = 3; i < sq; i+=2)
    {
        if(p[i] == true) continue;
        for(int j = i+i; j < MAX; j += i)
        {
            p[j] = true;
        }
    }

}

int main (void)
{
    sieveMethod();
    int cases;
    cin >> cases;
    string hudai;
    getline(cin, hudai);
    int f = 0;

    while(cases--)
    {
        string blankLine, str;
        getline(cin,blankLine);
        getline(cin, str);
        if(f == 1) cout << endl;
        f = 1;
        int num = str.length();
        if(num == 1)cout << "1" << endl;
        else if(p[num] == false)
        {
            bool flag = true;
            char ch = str[0];
            for(int i = 1; i < num; i++)
            {
                if(str[i] != ch)
                {
                    flag = false;
                    break;
                }
            }

            if(flag) cout << "1" << endl;
            else cout << num << endl;
        }

        else
        {
            bool head = true;
            vector<int>factor;
            for(int i = 1; i <=num/2; i++)
            {
                if(num%i == 0) factor.push_back(i);
            }
            int s = factor.size();
            for(int i = 0; i < s; i++)
            {
                int limit = num/factor[i];
                int j = 0;
                string sub = str.substr(j, factor[i]);
                limit--;
                bool flag = true;
                while(limit--)
                {
                    j += factor[i];
                    string sub2 = str.substr(j, factor[i]);
                    if(sub != sub2)
                    {
                        flag = false;

                        break;
                    }
                }
                if(flag) {
                    head = false;
                    cout << factor[i] << endl;
                    break;
                }
            }

            if(head) cout << num << endl;


        }
    }
    return 0;
}
