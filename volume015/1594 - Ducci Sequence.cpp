#include<bits/stdc++.h>

using namespace std;

bool iszero;

void set_diff(vector<int>&diff, int n)
{
    iszero = true;
    diff[n] = diff[0];
    for(int i = 0; i < n; i++)
    {
        diff[i] = abs(diff[i] - diff[i+1]);
        if(diff[i] != 0) iszero = false;
    }
}

int main()
{
    int cases, n;
    scanf("%d", &cases);
    while(cases--)
    {
        int thousand = 1000;
        set< vector<int> > mySet;
        iszero = true;
        scanf("%d", &n);
        vector<int>diff(n+1);
        for(int i = 0; i<n; i++)
        {
            scanf("%d", &diff[i]);
            if(diff[i] != 0) iszero = false;
        }
        mySet.insert(diff);
        if(iszero) puts("ZERO");
        else
        {
            while(thousand--)
            {
                set_diff(diff, n);
                if(iszero)
                {
                    puts("ZERO");
                    break;
                }
                if(mySet.find(diff) != mySet.end())
                {
                    puts("LOOP");
                    break;
                }
                else mySet.insert(diff);
            }
        }
    }
    return 0;
}
