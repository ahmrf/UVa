#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;
#define MAX 20000

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
        for(int j = i*i; j < MAX; j += i+i)
        {
            p[j] = true;
        }
    }

}

int main ()
{
    sieveMethod();
    int cases, case_no = 0;
    scanf("%d", &cases);
    string hudai;
    getline(cin, hudai);
    while(cases--)
    {
        string input;
        getline(cin, input);
        map<char, int> freq;
        vector<char>alpha;
        vector<char>res;

        int l = input.length();

        for(int i = 0; i < l; i++)
        {
            if(freq.find(input[i]) == freq.end())
            {
                freq[input[i]] = 1;
                alpha.push_back(input[i]);

            }

            else freq[input[i]]++;
        }

        l = alpha.size();
        for(int i = 0; i < l; i++)
        {
            int num = freq[alpha[i]];
            if(p[num] == false) res.push_back(alpha[i]);
        }

        sort(res.begin(), res.end());

        l = res.size();
        printf("Case %d: ",++case_no);
        if(l == 0) printf("empty\n");
        else{
            for(int i = 0; i < l; i++)
            {
                printf("%c", res[i]);
            }
            printf("\n");
        }

    }
    return 0;
}
